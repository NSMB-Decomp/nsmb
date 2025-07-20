class Heap
{
public:
    void *start;
    u32 size;
    Heap *parent;
    u32 flags;

    void destroy();
    void* allocate(u32, u32);
    Heap* setCurrent();
    void maxAllocationUnitSize();
};

Heap *func_02045240(u32, u32, u32);
