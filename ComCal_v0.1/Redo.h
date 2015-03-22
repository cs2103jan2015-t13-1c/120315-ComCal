// Redo.h
// Subclass of Command; implements the redo function
//@author A011954X

#pragma once

#include "Command.h"

class Redo : public Command {
public:
	std::string execute(std::string argument);
};