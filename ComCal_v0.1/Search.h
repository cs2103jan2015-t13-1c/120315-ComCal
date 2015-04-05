// Search.h
// Subclass of Command; implements the search function
//@author A011954X

#pragma once

#include "Command.h"

class Search : public Command {
public:
	Search();
	~Search();
	std::string execute(std::string argument);
};