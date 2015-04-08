// Show.h
// Subclass of Command; implements the show function
//@author A011954X

#pragma once

#include "Command.h"
#include "Date.h"
#include "TextStorage.h"
#include "ComCalManager.h"
#include "timeDateInfo.h"
#include "keywords.h"
#include "typeConversions.h"

class Show : public Command {
	
private:
	int getMonthInput(std::string argument);
public:
	Show();
	~Show();
	std::string execute(std::string argument);
};