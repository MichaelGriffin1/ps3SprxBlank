#pragma once

struct opd_s;
int sys_ppu_thread_exit();
int cstrcmp(const char* s1, const char* s2);
int console_write(const char * s);
void sleep(usecond_t time);

class PS3
{
public:
	static float floatArray[100];
	static float* ReadFloat(int address, int length);
	static char byteArray[100];
	static char* ReadBytes(int address, int length);
	static void WriteFloat(int address, float* input, int length);
	static void WriteBytes(int address, char* input, int length);
	static float intArray[100];
	static char ReturnRead[1000];
	static float* ReadInt(int address, int length);
	static void WriteInt(int address, int* input, int length);
	static void WriteString(int address, char* string);
	// The readstring part has been removed, and will be added back in a later revision.
};