#include "TextStorage.h"
#include "typeConversions.h"
#include <fstream>
#include <vector>
#include "rapidxml.hpp"
#include "rapidxml_print.hpp"
using namespace rapidxml;

template<class Ch> 
inline std::basic_ostream<Ch> &print(std::basic_ostream<Ch> &out, const xml_node<Ch> &node, int flags = 0);

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

void TextStorage::initialize(std::string todoFileName) {
	_todoFileName = todoFileName;
}

unsigned int TextStorage::getNumberOfTasks() {
	return _todoTasks->size();
}

Task* TextStorage::getTask(int index) {
	return _todoTasks->at(index);
}

void TextStorage::addTask(Task* newTask) {
	_todoTasks->push_back(newTask);
}

bool TextStorage::deleteTask(int index) {
	if (index > _todoTasks->size())
		return false;
	if (index <= 0)
		return false;
	_todoTasks->erase(_todoTasks->begin() + index - 1);
	return true;
}

bool TextStorage::saveTasks(std::string fileName)
{
	xml_document<> xmlDocument;
	std::ofstream saveFile(fileName);

	xml_node<>* xmlDeclarationNode = xmlDocument.allocate_node(node_declaration);
	xmlDeclarationNode->append_attribute(xmlDocument.allocate_attribute("version", "1.0"));
	xmlDeclarationNode->append_attribute(xmlDocument.allocate_attribute("encoding", "utf-8"));
	xmlDocument.append_node(xmlDeclarationNode);

	Task* tempTask;
	Date* tempDate;
	xml_node<>* taskNode;
	xml_node<>* detailsNode;
	xml_node<>* dateNode;
	for (unsigned int i = 0; i < _todoTasks->size(); i++) {
		tempTask = _todoTasks->at(i);
		taskNode = xmlDocument.allocate_node(node_element, "task");
		xmlDocument.append_node(taskNode);

		detailsNode = xmlDocument.allocate_node(node_element, "description");
		detailsNode->value(xmlDocument.allocate_string(tempTask->getDescription().c_str()));
		taskNode->append_node(detailsNode);

		detailsNode = xmlDocument.allocate_node(node_element, "location");
		detailsNode->value(xmlDocument.allocate_string(tempTask->getLocation().c_str()));
		taskNode->append_node(detailsNode);

		for (int i = 0; i < 2; i++)
		{
			if (((i == 0) && tempTask->hasStartDate()) || ((i == 1) && tempTask->hasEndDate()))
			{
				tempDate = (i == 0) ? tempTask->getStartDate() : tempTask->getEndDate();

				detailsNode = xmlDocument.allocate_node(node_element, (i == 0) ? "startDate" : "endDate");
				detailsNode->value(tempTask->getLocation().c_str());
				taskNode->append_node(detailsNode);

				dateNode = xmlDocument.allocate_node(node_element, "day");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getDay()).c_str()));
				detailsNode->append_node(dateNode);

				dateNode = xmlDocument.allocate_node(node_element, "month");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getMonth()).c_str()));
				detailsNode->append_node(dateNode);

				dateNode = xmlDocument.allocate_node(node_element, "year");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getYear()).c_str()));
				detailsNode->append_node(dateNode);

				dateNode = xmlDocument.allocate_node(node_element, "time");
				dateNode->value(xmlDocument.allocate_string(typeConversions::intToString(tempDate->getTime()).c_str()));
				detailsNode->append_node(dateNode);
			}
		}

		detailsNode = xmlDocument.allocate_node(node_element, "isDone");
		detailsNode->value(tempTask->getIsDone() ? "true" : "false");
		taskNode->append_node(detailsNode);
	}

	std::string sXml;
	print(back_inserter(sXml), xmlDocument);
 
	saveFile << sXml;
	saveFile.close();

	return true;
}

bool TextStorage::loadTasks(std::string fileName)
{
	xml_document<> xmlDocument;
	xml_node<>* rootNode;

	std::ifstream loadFile(fileName);
	std::vector<char> buffer((std::istreambuf_iterator<char>(loadFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');

	xmlDocument.parse<0>(&buffer[0]);

	return false; // TODO remove this when finished writing code

	return true;
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