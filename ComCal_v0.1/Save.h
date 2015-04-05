// Save.h
// Subclass of Command; implements the save function
//@author A011954X

#pragma once

#include "Command.h"

class Save : public Command {
public:
	Save();
	~Save();
	std::string execute(std::string argument);
};