// Undo.h
// Subclass of Command; implements the undo function
//@author A011954X

#pragma once

#include "Command.h"

class Undo : public Command {
public:
	std::string execute(std::string argument);
};