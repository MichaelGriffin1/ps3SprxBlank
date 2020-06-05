#pragma once

// Console write in PTC class
class PTC
{
public:
	static int console_write(const char * s);
};

// Thread create command
sys_ppu_thread_t create_thread(void(*entry)(uint64_t), int priority, size_t stacksize, const char* threadname, sys_ppu_thread_t tid);