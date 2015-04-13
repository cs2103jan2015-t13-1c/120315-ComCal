//@author A0110783L

#include "typeConversions.h"
#include <algorithm>

//@author A0119754X
// Converts std::string into int
int typeConversions::stringToInt(std::string str) {
	std::istringstream buffer(str);
	int result;
	buffer >> result;
	return result;
}

// Converts int into std::string
std::string typeConversions::intToString(int i) {
	std::stringstream ss;
	ss << i;
	return ss.str();
}

// Check if a string can be converted into an integer
bool typeConversions::isNumber(std::string str) {
	return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

// Converts std::string into lower case
std::string typeConversions::toLowerCase(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

// Removes the extra spaces in the string, eg. "a bc   def  ghi" becomes "a bc def ghi"
std::string typeConversions::trimExtraSpaces(std::string str) {
	while (true) {
		int find = str.find("  ");
		if ((find == -1) || (find == std::string::npos)) {
			return str;
		}
		str = str.substr(0, find) + str.substr(find + 1, str.length() - find - 1);
	}
	return str;
}

