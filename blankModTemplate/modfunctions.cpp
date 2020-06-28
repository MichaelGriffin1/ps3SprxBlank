#pragma once

#include "modfunctions.h"
#include "dialog.h"

//-----------------//
//    DIAL class   //
//-----------------//

// Function that displays a okay prompt with a text argument
void DIAL::OkPrompt(char* dText)
{
	// Sets the mode to the string ok mode, and displays prompt
	Dialog::msgdialog_mode = Dialog::MODE_STRING_OK;
	Dialog::Show(dText);
}
	
// Function that displays a yes/no prompt with a text argument
bool DIAL::YesNoPrompt(char* dText)
{
	// Declares return bool
	bool retBool = false;
		
	// Shows a yes or no dialog according to the dText argument
	Dialog::msgdialog_mode = Dialog::MODE_STRING_YESNO;
	Dialog::ShowYESNO(dText);
		
	// Waits until the dialog has finished
	while (Dialog::msgdialog_mode != Dialog::MODE_EXIT) {}

	// Stores answer in return bool
	retBool = Dialog::YESNO;

	// Exits dialog
	Dialog::End();

	// Returns the return bool
	return retBool;
}

//-----------------//
//    MODF class   //
//-----------------//


// Causes segmentation fault :)
void MODF::causeSegFault()
{
	int zeroOffset = 0x0;
	char* zeroChar = 0x0;

	PS3::WriteBytes(zeroOffset, zeroChar, sizeof(zeroChar));
}

// Grants infinite shouts upon call!
void MODF::infShout()
{
	// Infinite shout offset and char array to write
	int InfShoutOffeset = 0x8EA00;
	char InfShoutValue[] = { 0x60, 0x00, 0x00, 0x00 };

	// Writes those into memory
	PS3::WriteBytes(InfShoutOffeset, InfShoutValue, sizeof(InfShoutValue));
}