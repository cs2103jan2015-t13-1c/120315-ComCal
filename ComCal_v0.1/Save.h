//@author A0116683B
// Save.h
// Subclass of Command; implements the save function

#pragma once

#include "Command.h"
#include "TextStorage.h"

class Save : public Command {
public:
	Save();
	~Save();
	std::string execute(std::string argument);
};