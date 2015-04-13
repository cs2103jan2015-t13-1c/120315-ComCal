//@author A0110783L
#pragma once

#include <string>
#include <fstream>
#include <sstream>

//This namespace is cater to any type conversions that might occur
namespace typeConversions{
	//StrH refers to String^
//	std::string convertStrTostr(System::String^); // Converts System::String^ into std::string
//	System::String^ convertstrToStr(std::string); // Converts std::string into System::String^

	int stringToInt(std::string str);
	std::string intToString(int i);
	bool isNumber(std::string str);

	std::string toLowerCase(std::string str);
	std::string trimExtraSpaces(std::string str);

//	void convertArrStrToConststrArr(array<System::String^>^, const char**, int);
}
