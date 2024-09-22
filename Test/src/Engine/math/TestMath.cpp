#include "TestMath.h"
#include <math/Math.h>

using namespace Towell::Test;

void TestMath::Run()
{
	test("Absolute", []() -> void {
		float result1 = Math::Abs(1.0f);
		assertEqual(1.0f, result1, "Should absolute value of positive value be itself");

		float result2 = Math::Abs(-1.0f);
		assertEqual(1.0f, result2, "Should absolute value of a negative value be a positive value of itself");

		float result3 = Math::Abs(-352.798f);
		assertEqual(352.798f, result3, "Should absolute value of a negative value be a positive value of itself");
	});

	test("Cos", []() -> void {
		// TODO: test not implemented
	});

	test("Sin", []() -> void {
		// TODO: test not implemented
	});

	test("Tan", []() -> void {
		// TODO: test not implemented
	});

	test("Acos", []() -> void {
		// TODO: test not implemented
	});

	test("Atan2", []() -> void {
		// TODO: test not implemented
	});

	test("Floor", []() -> void {
		float result = Math::Floor(77.085f);
		assertEqual(77.0f, result, "Shoud floor a float number");
	});

	test("Round", []() -> void {
		float result = Math::Round(77.985f);
		assertEqual(78.0f, result, "Shoud round a float number up");

		result = Math::Round(77.6f);
		assertEqual(78.0f, result, "Shoud round a float number up");

		result = Math::Round(77.085f);
		assertEqual(77.0f, result, "Shoud round a float number down");

		result = Math::Round(77.4f);
		assertEqual(77.0f, result, "Shoud round a float number down");
	});

	test("Square Root", []() -> void {
		float result = Math::Sqrt(9.0f);
		assertEqual(3.0f, result, "Should square root of 9 be 3");

		result = Math::Sqrt(125.37f);
		assertEqual(11.19687456391291364010284611267f, result, "Should square root of complex number be properly calculated");
	});

	test("Float AreEqual", []() -> void {
		bool result = Math::AreEqual(0.0f, 0.0f);
		assertTrue(result, "Should two floats 0 be equals");

		result = Math::AreEqual(0.0f, 1.0f);
		assertTrue(!result, "Should two explicit different float be considered Not Equals");

		result = Math::AreEqual(1.0f, 1.0001f);
		assertTrue(result, "Should too close float values be considered to be equals");
	});

	test("NearZero", []() -> void {
		bool result = Math::NearZero(0.0f);
		assertTrue(result, "Should 0.0 be considered near to zero");

		result = Math::NearZero(0.0005f);
		assertTrue(result, "Should 0.0005 be considered near to zero");

		result = Math::NearZero(-0.0005f);
		assertTrue(result, "Should -0.0005 be considered near to zero");

		result = Math::NearZero(1.0f);
		assertTrue(!result, "Should 1.0 NOT to be considered near to zero");

		result = Math::NearZero(-1.0f);
		assertTrue(!result, "Should -1.0 NOT to be considered near to zero");
	});
}
