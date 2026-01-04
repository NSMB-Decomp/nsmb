class Heap
{
public:
    void *start;
    u32 size;
    Heap *parent;
    u32 flags;

    void resizeToFit();
    void destroy();
    void* allocate(u32, u32);
    Heap* setCurrent();
    u32 maxAllocationUnitSize();

    virtual _(); // Temp function to create vtable
};

class FrameHeap {
public:
    static Heap *create(u32, Heap*, u32);
};