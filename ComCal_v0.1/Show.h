// Show.h
// Subclass of Command; implements the show function
//@author A011954X

#pragma once

#include "Command.h"

class Show : public Command {
	
private:
	int getMonthInput(std::string argument);
	int numOfWS(std::string argument);

public:
	std::string execute(std::string argument);
};