// Undone.h
// Subclass of Command; implements the undone function
//@author A0085731A

#pragma once

#include "Command.h"
#include "typeConversions.h"
#include "TextStorage.h"
#include "Exceptions.h"
#include "support.h"

#include <vector>
#include <algorithm>

class Undone : public Command {
private:
	std::vector<int> _undoneTasksIndexes;
	std::vector<Task*> _undoneTasks;

	void process(std::string);
	bool checkDateBefore(Date*, Date*);

public:
	Undone();
	~Undone();
	std::string execute(std::string argument);
	std::string undo();
	std::string redo();
};