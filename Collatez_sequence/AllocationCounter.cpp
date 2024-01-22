#pragma once
#include <iostream>
#include <cmath>

static uint32_t bytesAllocated= 0;

static uint32_t s_AllocCount = 0;

void* operator new(size_t size)
{
	bytesAllocated += size;
	s_AllocCount++;

	return malloc(size);
}
