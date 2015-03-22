// Edit.h
// Subclass of Command; implements the edit function
//@author A011954X

#pragma once

#include "Command.h"

class Edit : public Command {
public:
	std::string execute(std::string argument);
};