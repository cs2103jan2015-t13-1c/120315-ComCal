#pragma once
#include "Task.h"
#include "keywords.h"

//This class is used mainly for undo and redo
class comAndTask
{
public:
	//Arguments: 1st - command string, 2nd - Task
	comAndTask(std::string, Task);
	~comAndTask();

	Task getTask();
	std::string getCommand();

private:
	Task _task;
	std::string _command;
};

