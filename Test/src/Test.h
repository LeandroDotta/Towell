#ifndef TOWELL_TEST_H
#define TOWELL_TEST_H

#include <functional>

namespace Towell::Test
{
	void test(char* description, std::function<void()> testFunction);

	void assertEqual(int expected, int actual, char* message);
	void assertEqual(float expected, float actual, char* message);
	void assertTrue(bool value, char* message);

	class TestSuite
	{
	public:
		virtual void Run() = 0;
	};
}

#endif // TOWELL_TEST_H
