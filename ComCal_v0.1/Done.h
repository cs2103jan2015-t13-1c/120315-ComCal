//@author A0085731A
// Done.h
// Subclass of Command; implements the done function

#pragma once

#include "Command.h"
#include "typeConversions.h"
#include "TextStorage.h"
#include "Exceptions.h"
#include "support.h"

#include <vector>
#include <algorithm>

class Done : public Command {
private:
	std::vector<int> _doneTasksIndexes;
	std::vector<Task*> _doneTasks;

	void process(std::string);
	bool checkDateBefore(Date*, Date*);

public:
	Done();
	~Done();
	std::string execute(std::string argument);
	std::string undo();
	std::string redo();
};