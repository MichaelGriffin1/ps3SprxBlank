
#include "includes.h"

// SPRX Info, will display "Template Mod" as an entry in the PRX manager
SYS_MODULE_INFO( "Template Mod", 0, 1, 1);

// SPRX start and stop functions
SYS_MODULE_START( _blankModTemplate_prx_entry );
SYS_MODULE_STOP( _blankModTemplate_prx_exit );

SYS_LIB_DECLARE_WITH_STUB( LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME );
SYS_LIB_EXPORT( _blankModTemplate_export_function, LIBNAME );

// Functions header files
#include "ownIncludes.h"


// Object Declarations
PS3 ps3;
DIAL dialog;
MODF mod;

// The main mod thread that the SPRX executes
void ModThread(uint64_t modthread)
{
	dialog.OkPrompt("This is an example Skyrim mod that grants infinite shouts!");

	for(;;)
	{
		mod.infShout();
	}
}

// An exported function is needed to generate the project's PRX stub export library
extern "C" int _blankModTemplate_export_function(void)
{
    return CELL_OK;
}

extern "C" int _blankModTemplate_prx_entry(void)
{
	// Starts main mod thread
	create_thread(ModThread, 0x4AA, 0x6000, "Mod Thread", modThread);
    return SYS_PRX_RESIDENT;
}

extern "C" int _blankModTemplate_prx_exit(void)
{
	return SYS_PRX_STOP_OK;
}