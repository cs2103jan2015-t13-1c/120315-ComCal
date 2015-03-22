// Show.h
// Subclass of Command; implements the show function
//@author A011954X

#pragma once

#include "Command.h"

class Show : public Command {
public:
	std::string execute(std::string argument);
};