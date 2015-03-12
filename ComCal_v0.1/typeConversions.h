#pragma once
#include <string>
#include "Task.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>

//This namespace is cater to any type conversions that might occur
namespace typeConversions{

	std::string convertTaskToStr(Task);
	Task convertStrToTask(std::string);

	//StrH refers to String^
	std::string convertStrTostr(System::String^); // Converts System::String^ into std::string
	System::String^ convertstrToStr(std::string); // Converts std::string into System::String^

	int stringToInt(std::string str);
	std::string intToString(int i);

	std::string toLowerCase(std::string str);
}
