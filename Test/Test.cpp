#include <Log.h>
#include "Test.h"

using namespace Towell;

void printSucess(char* message) 
{
	TW_INFO("\t- [PASSED] %s", message);
}

void Test::test(char* description, std::function<void()> testFunction)
{
	TW_INFO("Test Case - %s", description);
	testFunction();
}

void Test::assertEqual(int expected, int actual, char* message)
{
	bool result = expected == actual;

	if (result)
	{
		printSucess(message);
		return;
	}

	TW_ERROR("\t- [FAILED] %s\n\t- Expected: %d\n\t- Actual: %d", message, expected, actual);
}

void Test::assertEqual(float expected, float actual, char* message)
{
	bool result = expected == actual;

	if (result)
	{
		printSucess(message);
		return;
	}
	
	TW_ERROR("\t- [FAILED] %s\n\t- Expected: %f\n\t- Actual: %f", message, expected, actual);
}