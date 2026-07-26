#pragma once
#include "base_types.hpp"

class Heap
{
      public:
	void *start;
	u32 size;
	Heap *parent;
	u32 flags;

	void resizeToFit();
	void destroy();
	void *allocate(u32, u32);
	void deallocate(void *memory);
	u32 sizeOf(void *memory);
	u32 setFlags(u32 flags);
	u32 maxAllocatableSize(s32 alignment);
	Heap *setCurrent();
	u32 maxAllocationUnitSize();
	void test();

	virtual void _(); // Temp function to create vtable
};

class FrameHeap
{
      public:
	static Heap *create(u32, Heap *, u32);
};
