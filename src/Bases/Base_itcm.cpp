#include "Base.hpp"

i32 Base::func_01ffd524(PTMF a, PTMF b, PTMF c) {
    void** vtable = *((void***)this);
    if ((b.params & 1) != 0) {
        b.func = (void(*)())vtable[b.params];
    }
    b.func();
}

bool Base::onUpdate()
{
    return true;
}

bool Base::preUpdate()
{
    if (this->pending_destroy != false || (this->skipFlags & Update) != 0)
    {
        return false;
    }
    return true;
}

void Base::postUpdate() {}

bool Base::onRender()
{
    return true;
}

bool Base::preRender()
{
    if (this->pending_destroy != false || (this->skipFlags & Render) != 0)
    {
        return false;
    }
    return true;
}

void Base::postRender() {}

bool Base::func_01ffd290()
{
    if (this->pending_destroy)
    {
        this->pending_destroy = false;
        if ((bool)(this->state != Active) ? 0 : 1)
        {
            LinkedList_Remove(&ProcessManager::ExecuteTask, &this->process_link.update);
            LinkedList_Remove(&ProcessManager::DrawTask, &this->process_link.render);
        }
        else
        {
            LinkedList_Remove(&ProcessManager::CreateTask, &this->process_link.update);
        }
        LinkedList_Remove(&ProcessManager::DestroyTask, &this->process_link.update);
        this->state = Inactive;
        for (SceneNode *first_child = this->process_link.connect.firstChild; first_child != (void *)0x0;
             first_child = first_child->next)
        {
            first_child->object->destroy();
        }
    }
    else
    {
        Base *parent = this->getParent();
        if (parent != (void *)0x0)
        {
            // Check to see if this object should be updated
            u32 skip_flags = parent->skipFlags;
            if (
                (skip_flags & Update) == 0 && 
                (skip_flags & UpdateChildren) == 0)
            {
                if ((this->skipFlags & Update) != 0)
                {
                    this->skipFlags = (SkipFlags)(this->skipFlags & ~Update);
                }
                else
                {
                    this->skipFlags = (SkipFlags)(this->skipFlags | Update);
                }
            }
            // Check to see if this object should be rendered
            if (((skip_flags & Render) == 0) && ((skip_flags & RenderChildren) == 0))
            {
                if ((this->skipFlags & Render) != 0)
                {
                    this->skipFlags = (SkipFlags)(this->skipFlags & ~Render);
                }
                else
                {
                    this->skipFlags = (SkipFlags)(this->skipFlags | Render);
                }
            }
            //
            state = this->state;
            if (state == Active)
            {
                if (this->process_link.update.sortPriority != this->process_link.update.currentPriority)
                {
                    LinkedList_Remove(&ProcessManager::ExecuteTask, &this->process_link.update);
                    this->process_link.update.currentPriority = this->process_link.update.sortPriority;
                    ProcessSet_add(&ProcessManager::ExecuteTask, &this->process_link.update);
                }
                if (this->process_link.render.sortPriority != this->process_link.render.currentPriority)
                {
                    LinkedList_Remove(&ProcessManager::DrawTask, &this->process_link.render);
                    this->process_link.render.currentPriority = this->process_link.render.sortPriority;
                    ProcessSet_add(&ProcessManager::DrawTask, &this->process_link.render);
                }
            }
            else if (state == Inactive)
            {
                if (this->pending_create)
                {
                    if (this->pending_update)
                    {
                        this->pending_update = false;
                        ProcessSet_add(&ProcessManager::ExecuteTask, &this->process_link.update);
                        ProcessSet_add(&ProcessManager::DrawTask, &this->process_link.render);
                        this->state = Active;
                    }
                }
                else
                {
                    this->pending_create = 0;
                    LinkedList_append(&ProcessManager::CreateTask, &this->process_link.update);
                }
            }
        }
    }
    return true;
}