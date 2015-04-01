#include "TextStorage.h"
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

std::vector<Task*>* TextStorage::getTodoTask() {
	return _todoTasks;
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
 
	xml_node<>* rootNode = xmlDocument.allocate_node(node_element, "root");
	xmlDocument.append_node(rootNode);
 
	xml_node<>* node1 = xmlDocument.allocate_node(node_element, "node1");
	node1->value("Contents of node1");
	rootNode->append_node(node1);
 
	rapidxml::xml_node<>* root2 = xmlDocument.allocate_node(node_element, "root2");
	root2->value("Contents of root2");
	xmlDocument.append_node(root2);
 
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