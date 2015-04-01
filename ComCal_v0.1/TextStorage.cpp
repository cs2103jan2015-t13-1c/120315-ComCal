#include "TextStorage.h"

// Global static pointer used to ensure a single instance of the class
TextStorage* TextStorage::_instance = NULL;

TextStorage::TextStorage() {
	_todoTasks = new std::vector<Task*>();
}

TextStorage::~TextStorage() {
	delete _todoTasks;
}

TextStorage* TextStorage::getInstance() {
	if (_instance == NULL)
		_instance = new TextStorage();
	return _instance;
}

void TextStorage::initialize(std::string todoFileName, std::string doneFileName) {
	_todoFileName = todoFileName;
	_doneFileName = doneFileName;
}

std::vector<Task*>* TextStorage::getTodoTask() {
	return _todoTasks;
}

bool TextStorage::deleteTask(int index) {
	bool hasDeleted = false;
	for (unsigned int i = 0; i < _todoTasks->size(); i++) {
		if ((*_todoTasks)[i]->getIndex() == index) {
			_todoTasks->erase(_todoTasks->begin() + i);
			i--;
			hasDeleted = true;
		}
	}
	return hasDeleted;
}

//I have a feeling this will be taken out
//void TextStorage::saveTasks(std::string fileName) {
//	std::ofstream outputFile(fileName);
//	int size = _todoTasks->size();
//	
//	if (outputFile.is_open()) {
//		outputFile << size << std::endl;
//		for (int i = 0; i < size; i++) {
//			outputFile << (*_todoTasks)[i]->toString() << std::endl;
//		}
//		outputFile.close();
//	}
//}

//Should be taken out as well
//void TextStorage::loadTasks(std::string fileName) {
//	std::string numberOfTasks;
//	std::string task[10];

//	_todoTasks->clear();

//	std::ifstream inputFile(fileName);
//	if (inputFile.is_open()) {
//		getline(inputFile, numberOfTasks);
//		int n = typeConversions::stringToInt(numberOfTasks);

//		for (int x = 0; x < n; x++) {
//			for (int i = 0; i < 10; i++) {
//				getline(inputFile, task[i]);
//			}
//			_todoTasks->push_back(new Task(task[0],
//									   task[1],
//									   typeConversions::stringToInt(task[2]),
//									   typeConversions::stringToInt(task[3]),
//									   typeConversions::stringToInt(task[4]),
//									   typeConversions::stringToInt(task[5]),
//									   typeConversions::stringToInt(task[6]),
//  								   typeConversions::stringToInt(task[7]),
//									   typeConversions::stringToInt(task[8]),
//									   typeConversions::stringToInt(task[9])));
//		}
//		inputFile.close();
//	}
//}