#include <sstream>
#include <algorithm>
#include "Functions.h"

int stringToInt(std::string str) {
	std::istringstream buffer(str);
	int result;
	buffer >> result;
	return result;
}

std::string intToString(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

std::string toLowerCase(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}