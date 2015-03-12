#pragma once
#include <string>
namespace timeDateInfo{

	bool isDateValid(std::string);
	bool isTimeValid(std::string);
	bool isDayValid(std::string);
	bool isClashing(std::string);
};

