#include "includes.h"
#include "ps3.h"

#define TOC                                                     ( 0x0072DCE8 )

struct opd_s
{
	uint32_t sub;
	uint32_t toc;
};

int sys_ppu_thread_exit()
{
	system_call_1(41, 0);
	return_to_user_prog(int);
}

int cstrcmp(const char* s1, const char* s2)//Please note if its equal to zero the strings are equal
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int console_write(const char * s)
{
	uint32_t len;
	system_call_4(403, 0, (uint64_t)s, std::strlen(s), (uint64_t)&len);
	return_to_user_prog(int);
}


void sleep(usecond_t time)  //1 second = 1000
{
	sys_timer_usleep(time * 1000);
}

// PS3 Class

float PS3::floatArray[100];
float* PS3::ReadFloat(int address, int length)
{
	for (int i = 0; i < length; i++)
	{
		floatArray[i] = *(float*)(address + (i * 0x04));
	}
	return floatArray;
}

char PS3::byteArray[100];
char* PS3::ReadBytes(int address, int length)
{
	for (int i = 0; i < length; i++)
	{
		byteArray[i] = *(char*)(address + (i));
	}
	return byteArray;
}

void PS3::WriteFloat(int address, float* input, int length)
{
	for (int i = 0; i < length; i++)
	{
		*(float*)(address + (i * 4)) = input[i];
	}
}

void PS3::WriteBytes(int address, char* input, int length)
{
	for (int i = 0; i < length; i++)
	{
		*(char*)(address + (i)) = input[i];
	}
}

float PS3::intArray[100];
float* PS3::ReadInt(int address, int length)
{
	for (int i = 0; i < length; i++)
	{
		intArray[i] = *(int*)(address + (i * 0x04));
	}
	return intArray;
}

void PS3::WriteInt(int address, int* input, int length)
{
	for (int i = 0; i < length; i++)
	{
		*(int*)(intArray + (i * 0x04)) = input[i];
	}
}

void PS3::WriteString(int address, char* string)
{
	int FreeMem = 0x1D00000;
	int strlength = std::strlen(string);
	*(char**)FreeMem = string;
	char* StrBytes = PS3::ReadBytes(*(int*)FreeMem, strlength);
	PS3::WriteBytes(address, StrBytes, strlength);
}