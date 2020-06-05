#include "includes.h"
#include "ppuThreadCreate.h"

// Console Write in PTC class for this specific instance
int PTC::console_write(const char * s)
{
	uint32_t len;
	system_call_4(403, 0, (uint64_t)s, std::strlen(s), (uint64_t)&len);
	return_to_user_prog(int);
}


// The create_thread function
// The function was moved here so that it could be in the scope of prx.cpp, although it can be placed back into ps3.cpp in the current revision
sys_ppu_thread_t create_thread(void(*entry)(uint64_t), int priority, size_t stacksize, const char* threadname, sys_ppu_thread_t tid)
{
	if (sys_ppu_thread_create(&tid, entry, 0, priority, stacksize, 0, threadname) != CELL_OK)
	{
		PTC::console_write("THREAD: Thread creation failed...\n");
	}
	else
	{
		PTC::console_write("THREAD: Thread created...\n");
	}
	return tid;
}
