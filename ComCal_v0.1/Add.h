//@author A0119754X
// Add.h
// Subclass of Command; implements the add function

#pragma once

#include "Task.h"
#include "TextStorage.h"
#include "typeConversions.h"
#include "ComCalManager.h"
#include "Command.h"

#include <string>

class Add : public Command {
private:
	std::string _argument;

	int _d;
	int _s;
	int _e;
	int _l;
	int _taskIndex;
	Task* _addedTask;

	bool _isValid;
	bool _usesFrom;
	bool _usesOn;
	bool _usesTo;
	bool _usesBy;
	bool _usesIn;
	bool _hasLocation;
	bool _hasStartDate;
	bool _hasEndDate;

	std::string _description;
	std::string _startDate;
	std::string _endDate;
	std::string _location;

	bool canFind(int index);
	std::string checkIfValid();
	void findDSEL();
	void getFourParameters();
public:
	Add();
	~Add();
	std::string execute(std::string argument);
	std::string undo();
	std::string redo();
};