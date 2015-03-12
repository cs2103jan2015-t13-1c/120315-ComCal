#include "typeConversions.h"
#include <sstream>
#include <algorithm>

// Converts System::String^ into std::string
std::string typeConversions::convertStrTostr(System::String^ userInput) {
	std::string strInput;

	strInput = msclr::interop::marshal_as<std::string>(userInput);

	return strInput;
}

// Converts std::string into System::String^
System::String^ typeConversions::convertstrToStr(std::string userInput) {
	System::String^ strInput;

	strInput = msclr::interop::marshal_as<System::String^>(userInput);

	return strInput;
}

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

// Converts std::string into lower case
std::string typeConversions::toLowerCase(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

