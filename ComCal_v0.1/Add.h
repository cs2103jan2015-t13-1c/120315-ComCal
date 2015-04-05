// Add.h
// Subclass of Command; implements the add function
//@author A011954X

#pragma once

#include <string>
#include "Command.h"

class Add : public Command {
private:
	std::string _argument;

	int _d;
	int _s;
	int _e;
	int _l;
	int _taskIndex;

	bool _isValid;
	bool _usesFrom;
	bool _usesOn;
	bool _usesTo;
	bool _usesBy;
	bool _usesIn;
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