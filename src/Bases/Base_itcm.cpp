#include "Base.hpp"

i32 Base::func_01ffd524(PTMF a, PTMF b, PTMF c)
{
    void **vtable = *((void ***)this);
    // if ((b.params & 1) != 0) {
    //     b.func = (void(*)())vtable[b.params];
    // }
    // b.func();
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
        if ((BOOL)(this->state == Active) != FALSE)
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
                ((skip_flags & UpdateChildren) != 0) ||
                ((skip_flags & Update) != 0))
            {

                this->skipFlags = (SkipFlags)(this->skipFlags | Update);
            }
            else
            {
                if ((this->skipFlags & Update) != 0)
                {
                    this->skipFlags = (SkipFlags)(this->skipFlags & ~Update);
                }
            }

            skip_flags = parent->skipFlags;
            // Check to see if this object should be rendered
            if (
                ((skip_flags & RenderChildren) != 0) ||
                ((skip_flags & Render) != 0))
            {

                this->skipFlags = (SkipFlags)(this->skipFlags | Render);
            }
            else
            {
                if ((this->skipFlags & Render) != 0)
                {
                    this->skipFlags = this->skipFlags & ~Render;
                }
            }
        }
        //
        state = this->state;
        if (BOOL(state == Active) != FALSE)
        {
            PriorityNode *u = &this->process_link.update;
            if (BOOL(u->sortPriority != u->currentPriority) != FALSE)
            {
                LinkedList_Remove(&ProcessManager::ExecuteTask, &this->process_link.update);
                PriorityNode *update = &this->process_link.update;
                update->currentPriority = update->sortPriority;
                ProcessSet_add(&ProcessManager::ExecuteTask, update);
            }
            PriorityNode *r = &this->process_link.render;
            if (BOOL(r->sortPriority != r->currentPriority) != FALSE)
            {
                LinkedList_Remove(&ProcessManager::DrawTask, &this->process_link.render);
                PriorityNode *render = &this->process_link.render;
                render->currentPriority = render->sortPriority;
                ProcessSet_add(&ProcessManager::DrawTask, render);
            }
        }
        else if (BOOL(state == Inactive) == FALSE)
        {
            if (this->pending_create)
            {
                this->pending_create = 0;
                LinkedList_append(&ProcessManager::CreateTask, &this->process_link.update);
            }
            else
            {
                if (this->pending_update)
                {
                    this->pending_update = false;
                    ProcessSet_add(&ProcessManager::ExecuteTask, &this->process_link.update);
                    ProcessSet_add(&ProcessManager::DrawTask, &this->process_link.render);
                    this->state = Active;
                }
            }
        }
    }
    return true;
}

void Base::func_01ffd22c()
{
    PTMF a = {0x18, 1};
    PTMF b = {0x1c, 1};
    PTMF c = {0x20, 1};
    Base::func_01ffd524(a, b, c);
}