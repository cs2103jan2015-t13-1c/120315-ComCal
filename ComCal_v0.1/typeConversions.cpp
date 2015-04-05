#include "typeConversions.h"

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

// Check if a string can be converted into an integer
bool typeConversions::isNumber(std::string str) {
	return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

// Converts std::string into lower case
std::string typeConversions::toLowerCase(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

void typeConversions::convertArrStrToConststrArr(array<System::String^>^ fileNames, const char** strFilesNames, int numOfSpecifiedFiles) {

	msclr::interop::marshal_context^ context = gcnew msclr::interop::marshal_context();
	strFilesNames = new const char*[numOfSpecifiedFiles];
	for (int i = 0; i < numOfSpecifiedFiles; i++) {
		strFilesNames[i] = context->marshal_as<const char*>(fileNames[i]);

		context = nullptr;
	}

}

