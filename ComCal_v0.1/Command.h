// Command.h
// Abstract class; used for Command subclasses to inherit
//@author A011954X

#pragma once

#include "Task.h"
#include <string>

class Command {
public:
	Command();
	~Command();
	virtual std::string execute(std::string argument);
	virtual std::string undo();
	virtual std::string redo();
};