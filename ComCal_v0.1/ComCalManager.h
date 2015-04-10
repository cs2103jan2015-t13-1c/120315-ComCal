#pragma once

#include "Command.h"
#include "Add.h"
#include "Delete.h"
#include "Edit.h"
#include "Load.h"
#include "Save.h"
#include "Search.h"
#include "Show.h"
#include "timeDateInfo.h"
#include "keywords.h"
#include "TextStorage.h"
#include "typeConversions.h"
#include "Done.h"
#include "Undone.h"

#include <string>
#include <vector>
#include <stack>

class ComCalManager
{
private:
	static ComCalManager* _instance;

	//side bar viewer vector: This vector is used for search and show functions
	//To use this vector, delete the content in the vector then add in the searh/show info into this vector
	//The display will be done in the MonthForm.cpp by first getting this vector then displaying it on GUI
	std::vector<std::string>* _sideBarView;
	std::string _sideBarTitle;
	struct tm* _timeDetails;

	int _commandIndex;
	std::vector<std::string> _commands;

	std::stack<Command*> _commandHistory;
	std::stack<Command*> _undoHistory;
public:
	ComCalManager();
	~ComCalManager();

	static ComCalManager* getInstance();

	void initialise(int, const char**);

	//1) This function will deduce the mainCom and call that specific main function
	//2) The String^ here will be converted to a std::string the passed to the mainCom functions
	//3) Argument: std::string user input
	//3) Returns: std::string message for the UI feedback
	std::string deduceCommand(std::string);

	// Getter methods
	std::vector<std::string>* getSideVec();
	struct tm* getTimeDetails();
	std::string getSideBarTitle();

	//Setter methods
	void populateSideBar();
	void setTimeDetails(struct tm*);
	void setSideBarTitle(std::string);

	void resetCommandIndex();
	std::string moveCommandIndexUp();
	std::string moveCommandIndexDown();
};
