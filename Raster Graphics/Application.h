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
	const String EXIT_COMMAND = "exit";
};