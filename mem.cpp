#include "pch.h"
#include "mem.h"

void mem::Patch(BYTE* dst, BYTE* src, unsigned int size) {
	DWORD oldPro;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldPro);
	memcpy(dst, src, size);
	VirtualProtect(dst, size, oldPro, &oldPro);


}
void mem::Nop(BYTE* dst, unsigned int size) {
	DWORD oldPro;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldPro);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldPro, &oldPro);


}

uintptr_t mem::offset(uintptr_t ptr, std::vector<unsigned int> offset)
{
	intptr_t addr = ptr;

	//for (unsigned int i = 0; i < offset.size(); ++i) {
	for (auto o : offset){
		addr = *(uintptr_t*)addr;
		addr += o;

	}
	return addr;
}