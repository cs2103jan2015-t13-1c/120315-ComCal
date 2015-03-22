// Add.h
// Subclass of Command; implements the add function
//@author A011954X

#pragma once

#include "Command.h"

class Add : public Command {
public:
	std::string execute(std::string argument);
};