#include <sstream>
#include <algorithm>
#include "Functions.h"

// Converts std::string into int
int stringToInt(std::string str) {
	std::istringstream buffer(str);
	int result;
	buffer >> result;
	return result;
}

// Converts int into std::string
std::string intToString(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

// Converts std::string into lower case
std::string toLowerCase(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}
