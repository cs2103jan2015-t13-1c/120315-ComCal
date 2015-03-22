// Delete.h
// Subclass of Command; implements the delete function
//@author A011954X

#pragma once

#include "Command.h"

class Delete : public Command {
public:
	std::string execute(std::string argument);
};