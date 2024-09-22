#include "TestVector2.h"
#include <math/Vector2.h>

using namespace Towell::Test;

void TestVector2::Run()
{
	test("Operator +", []() -> void {
		Vector2 result = Vector2::One + Vector2::One;
		assertEqual(2.0f, result.x, "Sum vector 1 + 1 x value");
		assertEqual(2.0f, result.y, "Sum vector 1 + 1 y value");

		result = Vector2(4.5f, 10.48f) + Vector2(17.13f, 45.003f);
		assertEqual(21.63f, result.x, "Sum vectors with complex numbers, x value");
		assertEqual(55.483000f, result.y, "Sum vectors with complex numbers, y value");

		result = Vector2::Zero + Vector2::Zero;
		assertEqual(0.0f, result.x, "Sum zero vectors results 0 in value for x");
		assertEqual(0.0f, result.y, "Sum zero vectors results 0 in value for y");
	});

	test("Operator -", []() -> void {
		Vector2 result = Vector2(2.0f, 2.0f) - Vector2::One;
		assertEqual(1.0f, result.x, "Subtract vector with x value 2 by 1");
		assertEqual(1.0f, result.y, "Subtract vector with y value 2 by 1");

		result = Vector2::One - Vector2::One;
		assertEqual(0.0f, result.x, "Subtract vector with x value 1 by 1 should result in 0");
		assertEqual(0.0f, result.y, "Subtract vector with y value 1 by 1 should result in 0");

		result = Vector2::Zero - Vector2::Zero;
		assertEqual(0.0f, result.x, "Subtract two zero vectors should result in 0 for x value");
		assertEqual(0.0f, result.y, "Subtract two zero vectors should result in 0 for y value");

		result = Vector2(4.5f, 10.48f) - Vector2(17.13f, 45.003f);
		assertEqual(-12.63f, result.x, "Subtraction of vectors with complex numbers, x value");
		assertEqual(-34.523f, result.y, "Subtraction of vectors with complex numbers, y value");
	});

	test("Operator * with other Vector", []() -> void {
		Vector2 result = Vector2::Zero * Vector2::Zero;
		assertEqual(0.0f, result.x, "Multiply zero vectors should result in zero for x value");
		assertEqual(0.0f, result.y, "Multiply zero vectors should result in zero for y value");

		result = Vector2::One* Vector2::One;
		assertEqual(1.0f, result.x, "Multiply two vectors of value 1 should result in 1 for x value");
		assertEqual(1.0f, result.y, "Multiply two vectors of value 1 should result in 1 for y value");

		result = Vector2(4.5f, 10.48f) * Vector2(17.13f, 45.003f);
		assertEqual(77.085f, result.x, "Multiply two vectors with complex number for x value");
		assertEqual(471.63144f, result.y, "Multiply two vectors with complex number for y value");
	});

	test("Operator * with scalar value", []() -> void {
		Vector2 result = Vector2::Zero * 0;
		assertEqual(0.0f, result.x, "Multiply zero vector with scalar zero should result in zero for x value");
		assertEqual(0.0f, result.y, "Multiply zero vector with scalar zero should result in zero for y value");

		result = Vector2::One * 1;
		assertEqual(1.0f, result.x, "Multiply vector of value 1 with scalar 1 should result in 1 for x value");
		assertEqual(1.0f, result.y, "Multiply vector of value 1 with scalar 1 should result in 1 for y value");

		result = Vector2(4.5f, 10.48f) * 5.89f;
		assertEqual(26.505f, result.x, "Multiply vector with complex number for x value");
		assertEqual(61.7272f, result.y, "Multiply vector with complex number for y value");
	});

	test("Operator +=", []() -> void {
		Vector2 result = Vector2::One;
		result += Vector2::One;
		assertEqual(2.0f, result.x, "Sum vector 1 + 1 x value");
		assertEqual(2.0f, result.y, "Sum vector 1 + 1 y value");

		result = Vector2(4.5f, 10.48f);
		result += Vector2(17.13f, 45.003f);
		assertEqual(21.63f, result.x, "Sum vectors with complex numbers, x value");
		assertEqual(55.483000f, result.y, "Sum vectors with complex numbers, y value");

		result = Vector2::Zero;
		result += Vector2::Zero;
		assertEqual(0.0f, result.x, "Sum zero vectors results 0 in value for x");
		assertEqual(0.0f, result.y, "Sum zero vectors results 0 in value for y");
	});

	test("Operator += with scalar value", []() -> void {
		Vector2 result = Vector2::One;
		result += 1;
		assertEqual(2.0f, result.x, "Sum vector 1 + 1 x value");
		assertEqual(2.0f, result.y, "Sum vector 1 + 1 y value");

		result = Vector2(4.5f, 10.48f);
		result += 19.34f;
		assertEqual(23.84f, result.x, "Sum vectors with complex numbers, x value");
		assertEqual(29.82f, result.y, "Sum vectors with complex numbers, y value");

		result = Vector2::Zero;
		result += 0;
		assertEqual(0.0f, result.x, "Sum zero vectors results 0 in value for x");
		assertEqual(0.0f, result.y, "Sum zero vectors results 0 in value for y");
	});

	test("Operator -=", []() -> void {
		Vector2 result = Vector2(2.0f, 2.0f);
		result -= Vector2::One;
		assertEqual(1.0f, result.x, "Subtract vector with x value 2 by 1");
		assertEqual(1.0f, result.y, "Subtract vector with y value 2 by 1");

		result = Vector2::One;
		result -= Vector2::One;
		assertEqual(0.0f, result.x, "Subtract vector with x value 1 by 1 should result in 0");
		assertEqual(0.0f, result.y, "Subtract vector with y value 1 by 1 should result in 0");

		result = Vector2::Zero;
		result -= Vector2::Zero;
		assertEqual(0.0f, result.x, "Subtract two zero vectors should result in 0 for x value");
		assertEqual(0.0f, result.y, "Subtract two zero vectors should result in 0 for y value");

		result = Vector2(4.5f, 10.48f);
		result -= Vector2(17.13f, 45.003f);
		assertEqual(-12.63f, result.x, "Subtraction of vectors with complex numbers, x value");
		assertEqual(-34.523f, result.y, "Subtraction of vectors with complex numbers, y value");
	});

	test("Operator *=", []() -> void {
		Vector2 result = Vector2::Zero;
		result *= Vector2::Zero;
		assertEqual(0.0f, result.x, "Multiply zero vectors should result in zero for x value");
		assertEqual(0.0f, result.y, "Multiply zero vectors should result in zero for y value");

		result = Vector2::One;
		result *= Vector2::One;
		assertEqual(1.0f, result.x, "Multiply two vectors of value 1 should result in 1 for x value");
		assertEqual(1.0f, result.y, "Multiply two vectors of value 1 should result in 1 for y value");

		result = Vector2(4.5f, 10.48f);
		result *= Vector2(17.13f, 45.003f);
		assertEqual(77.085f, result.x, "Multiply two vectors with complex number for x value");
		assertEqual(471.63144f, result.y, "Multiply two vectors with complex number for y value");
	});

	test("Length", []() -> void {
		float result = Vector2::Zero.Length();
		assertEqual(0.0f, result, "Length of vector 0,0 should be 0");

		result = Vector2::One.Length();
		assertEqual(1.4142135623730950f, result, "Length of vector 1,1");

		result = Vector2(2.0f, 2.0f).Length();
		assertEqual(2.828427124746190f, result, "Length of vector 2,2");

		result = Vector2(17.13f, 45.003f).Length();
		assertEqual(48.152953273916647697283177153044f, result, "Length of vector with complex numbers");
	});

	test("SquaredLength", []() -> void {
		float result = Vector2::Zero.SquaredLength();
		assertEqual(0.0f, result, "Squared Length of vector 0,0 should be 0");

		result = Vector2::One.SquaredLength();
		assertEqual(2.0f, result, "Squared Length of vector 1,1 should be 2");

		result = Vector2(2.0f, 2.0f).SquaredLength();
		assertEqual(8.0f, result, "Squared Length of vector 2,2 should be 8");
		
		result = Vector2(17.13f, 45.003f).SquaredLength();
		assertEqual(2318.706909f, result, "Squared Length of vector with complex numbers");
	});

	test("Normalize", []() -> void {
		Vector2 result = Vector2::One;
		result.Normalize();
		assertEqual(0.70710678118654754f, result.x, "Normalized x of vector 0,0 should be approximately 0.7");
		assertEqual(0.70710678118654754f, result.y, "Normalized y of vector 0,0 should be approximately 0.7");

		result = Vector2(2.0f, 2.0f);
		result.Normalize();
		assertEqual(0.70710678118654754f, result.x, "Normalized x of vector 2,2 should be approximately 0.7");
		assertEqual(0.70710678118654754f, result.y, "Normalized y of vector 2,2 should be approximately 0.7");

		result = Vector2(17.13f, 45.003f);
		result.Normalize();
		assertEqual(0.355741420522153f, result.x, "Normalized x of vector 17.13, 45.003 should be approximately 0.35");
		assertEqual(0.934584421935696f, result.y, "Normalized y of vector 17.13, 45.003 should be approximately 0.93");
	});

	test("Dot multiplication", []() -> void {
		float result = Vector2::Dot(Vector2::Zero, Vector2::Zero);
		assertEqual(0.0f, result, "Dot multiplication of vectors 0,0 should result in 0");

		result = Vector2::Dot(Vector2::One, Vector2::One);
		assertEqual(2.0f, result, "Dot multiplication of vectors 1,1 should result in 1");

		result = Vector2::Dot(Vector2(2.0f, 2.0f), Vector2(2.0f, 2.0f));
		assertEqual(8.0f, result, "Dot multiplication of vectors 2,2 should result in 16");

		result = Vector2::Dot(Vector2(4.5f, 10.48f), Vector2(17.13f, 45.003f));
		assertEqual(548.71644f, result, "Dot multiplication of vectors with complex numbers");
	});

	test("Reflect", []() -> void {
		// TODO: Create tests for Vector2 reflect function
	});
}
