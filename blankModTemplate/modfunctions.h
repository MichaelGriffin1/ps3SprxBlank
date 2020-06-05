class DIAL
{
public:
	static void OkPrompt(char* dText);
	static bool YesNoPrompt(char* dText);
};

// This is the MODF class, where all of your memory-writing functions can go.
class MODF
{
public:
	// Causes a segmentation fault on the thread. Check it out in modfunctions.cpp :)
	static void causeSegFault();
};
