// Load.h
// Subclass of Command; implements the load function
//@author A011954X

#pragma once

#include "Command.h"

class Load : public Command {
public:
	Load();
	~Load();
	std::string execute(std::string argument);
};