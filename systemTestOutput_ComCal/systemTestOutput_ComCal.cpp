#include <gtest\gtest.h>
#include "ComCalManager.h"
#include <queue>
#include <string>

class ComCalManagerTest : public ::testing::Test {
protected:
	//this is the setup method
	virtual void SetUp() {
		actual.push(ComCalManager::getInstance()->deduceCommand("add .d coding .l com lab"));
		expected.push("Added coding com lab ");

		actual.push(ComCalManager::getInstance()->deduceCommand("add .d dance"));
		expected.push("Invalid add command: No location given");

		actual.push(ComCalManager::getInstance()->deduceCommand("add .d CS Tut .s 14/04/15 1500 .e 14/04/15 1600 .l Com Lab"));
		expected.push("Added CS Tut Com Lab 14/4/15 1500 14/4/15 1600");
	}

	//this functions acts like a dsetructor
	virtual void TearDown() {

	}

	std::queue<std::string> expected;
	std::queue<std::string> actual;
};

TEST_F(ComCalManagerTest, feedBackTest){
	int actualStage = 0;
	int expectedStage = expected.size();

	while (!expected.empty() && !actual.empty()) {

		if (expected.front() == actual.front()) {
			actualStage++;
		}
		actual.pop();
		expected.pop();
	}

	ASSERT_EQ(expectedStage, actualStage);
}

