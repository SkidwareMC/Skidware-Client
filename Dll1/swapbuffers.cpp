#include "includes.h"
#include "machip.h"

int __stdcall machip::hooks::swap_buffers_hk(HDC hdc)
{
	return machip::hooks::oswap_buffers(hdc);
}