// Command.h
// Abstract class; used for Command subclasses to inherit
//@author A011954X

#pragma once

#include <string>

class Command {
public:
	virtual std::string execute(std::string argument) = 0;
};