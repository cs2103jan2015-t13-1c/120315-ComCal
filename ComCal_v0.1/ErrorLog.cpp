#include "ErrorLog.h"
#include "typeConversions.h"
#include "keywords.h"

#include <fstream>

void ErrorLog::inputErrorLog(const std::string error){

	std::ofstream outputFile;

	outputFile.open(FILENAME_LOGDEFAULT, std::ios::app);

	if (outputFile.is_open()) {
		outputFile << error << std::endl;

		outputFile.close();
	}

}
