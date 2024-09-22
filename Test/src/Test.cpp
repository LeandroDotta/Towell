#include "Test.h"

#include <Log.h>
#include <math/Math.h>


using namespace Towell;

void printSuccess(char* message) 
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
		printSuccess(message);
		return;
	}

	TW_ERROR("\t- [FAILED] %s\n\t- Expected: %d\n\t- Actual: %d", message, expected, actual);
}

void Test::assertEqual(float expected, float actual, char* message)
{
	bool result = Math::AreEqual(expected, actual);

	if (result)
	{
		printSuccess(message);
		return;
	}
	
	TW_ERROR("\t- [FAILED] %s\n\t- Expected: %f\n\t- Actual: %f", message, expected, actual);
}

void Test::assertTrue(bool value, char* message)
{
	if (value)
	{
		printSuccess(message);
		return;
	}

	TW_ERROR("\t- [FAILED] %s\n\t- Value was expected to be True", message);
}
