// Show.h
// Subclass of Command; implements the show function
//@author A011954X

#pragma once

#include "Command.h"
#include "Date.h"

class Show : public Command {
	
private:
	int numOfWS(std::string argument);

	//Getter methods
	int getMonthInput(std::string argument);
	
	//Setter methods
	void setDoneSideBar(); //Set sideBar to show done tasks
	void setShowDaySideBar(Date*); //Set sideBar to show desired days todo tasks

public:
	std::string execute(std::string argument);
};