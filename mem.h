#pragma once
#include <vector>
namespace mem
{

	void Patch(BYTE* dst, BYTE* src, unsigned int size);
	void Nop(BYTE* dst, unsigned int size);
	uintptr_t offset(uintptr_t ptr, std::vector<unsigned int> offset);

	



};

