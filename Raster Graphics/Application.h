#pragma once
#include "String.h"

class Application
{
public:
	void run();

private:
	bool isRunning = true;

	const String LOAD_COMMAND = "load";
	const String ADD_COMMAND = "add";
	const String COLLAGE_COMMAND = "collage";
	const String COLLAGE_HORIZONTAL_DIRECTION = "horizontal";
	const String COLLAGE_VERTICAL_DIRECTION = "vertical";
	const String SESSION_INFO_COMMAND = "session_info";
	const String SWITCH_COMMAND = "switch";
	const String SAVE_COMMAND = "save";
	const String SAVEAS_COMMAND = "save_as";
	const String UNDO_COMMAND = "undo";
	const String HELP_COMMAND = "help";
	const String EXIT_COMMAND = "exit";

	const String HELP_MESSAGE = "load <filename> - load image\nadd <filename> - add image\nsave - save all images\nsave_as <filename> - save first image as\nundo - undo last transform\nexit - exit the application\nswitch <session_id> - switch to another session\nsession_info - get info about the current session\ntransforms: grayscale, monochrome, negative, rotate <direction>\ncollage <direction> <image1> <image2> <output> - collage images\n";
};