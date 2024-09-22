#include "TestVector3.h"
#include <math/Vector3.h>

using namespace Towell::Test;

void TestVector3::Run()
{
	test("Operator +", []() -> void {
		Vector3 result = Vector3::One + Vector3::One;
		assertEqual(2.0f, result.x, "Sum vector 1 + 1 x value");
		assertEqual(2.0f, result.y, "Sum vector 1 + 1 y value");

		result = Vector3(4.5f, 10.48f, 3.76f) + Vector3(17.13f, 45.003f, -1.0f);
		assertEqual(21.63f, result.x, "Sum vectors with complex numbers, x value");
		assertEqual(55.483000f, result.y, "Sum vectors with complex numbers, y value");
		assertEqual(2.76f, result.z, "Sum vectors with complex numbers, z value");

		result = Vector3::Zero + Vector3::Zero;
		assertEqual(0.0f, result.x, "Sum zero vectors results 0 in value for x");
		assertEqual(0.0f, result.y, "Sum zero vectors results 0 in value for y");
		assertEqual(0.0f, result.z, "Sum zero vectors results 0 in value for z");
	});

	test("Operator -", []() -> void {
		Vector3 result = Vector3(2.0f, 2.0f, 2.0f) - Vector3::One;
		assertEqual(1.0f, result.x, "Subtract vector with x value 2 by 1");
		assertEqual(1.0f, result.y, "Subtract vector with y value 2 by 1");
		assertEqual(1.0f, result.z, "Subtract vector with z value 2 by 1");

		result = Vector3::One - Vector3::One;
		assertEqual(0.0f, result.x, "Subtract vector with x value 1 by 1 should result in 0");
		assertEqual(0.0f, result.y, "Subtract vector with y value 1 by 1 should result in 0");
		assertEqual(0.0f, result.z, "Subtract vector with z value 1 by 1 should result in 0");

		result = Vector3::Zero - Vector3::Zero;
		assertEqual(0.0f, result.x, "Subtract two zero vectors should result in 0 for x value");
		assertEqual(0.0f, result.y, "Subtract two zero vectors should result in 0 for y value");
		assertEqual(0.0f, result.z, "Subtract two zero vectors should result in 0 for z value");

		result = Vector3(4.5f, 10.48f, 3.76f) - Vector3(17.13f, 45.003f, -1.0f);
		assertEqual(-12.63f, result.x, "Subtraction of vectors with complex numbers, x value");
		assertEqual(-34.523f, result.y, "Subtraction of vectors with complex numbers, y value");
		assertEqual(4.76f, result.z, "Subtraction of vectors with complex numbers, z value");
	});

	test("Operator * with other Vector", []() -> void {
		Vector3 result = Vector3::Zero * Vector3::Zero;
		assertEqual(0.0f, result.x, "Multiply zero vectors should result in zero for x value");
		assertEqual(0.0f, result.y, "Multiply zero vectors should result in zero for y value");
		assertEqual(0.0f, result.z, "Multiply zero vectors should result in zero for z value");

		result = Vector3::One * Vector3::One;
		assertEqual(1.0f, result.x, "Multiply two vectors of value 1 should result in 1 for x value");
		assertEqual(1.0f, result.y, "Multiply two vectors of value 1 should result in 1 for y value");
		assertEqual(1.0f, result.z, "Multiply two vectors of value 1 should result in 1 for z value");

		result = Vector3(4.5f, 10.48f, 3.76f) * Vector3(17.13f, 45.003f, -1.0f);
		assertEqual(77.085f, result.x, "Multiply two vectors with complex number for x value");
		assertEqual(471.63144f, result.y, "Multiply two vectors with complex number for y value");
		assertEqual(-3.76f, result.z, "Multiply two vectors with complex number for z value");
	});

	test("Operator * with scalar value", []() -> void {
		Vector3 result = Vector3::Zero * 0;
		assertEqual(0.0f, result.x, "Multiply zero vector with scalar zero should result in zero for x value");
		assertEqual(0.0f, result.y, "Multiply zero vector with scalar zero should result in zero for y value");
		assertEqual(0.0f, result.z, "Multiply zero vector with scalar zero should result in zero for z value");

		result = Vector3::One * 1;
		assertEqual(1.0f, result.x, "Multiply vector of value 1 with scalar 1 should result in 1 for x value");
		assertEqual(1.0f, result.y, "Multiply vector of value 1 with scalar 1 should result in 1 for y value");
		assertEqual(1.0f, result.z, "Multiply vector of value 1 with scalar 1 should result in 1 for z value");

		result = Vector3(4.5f, 10.48f, 3.76f) * 5.89f;
		assertEqual(26.505f, result.x, "Multiply vector with complex number for x value");
		assertEqual(61.7272f, result.y, "Multiply vector with complex number for y value");
		assertEqual(22.1464f, result.z, "Multiply vector with complex number for z value");
	});

	test("Operator +=", []() -> void {
		Vector3 result = Vector3::One;
		result += Vector3::One;
		assertEqual(2.0f, result.x, "Sum vector 1 + 1 x value");
		assertEqual(2.0f, result.y, "Sum vector 1 + 1 y value");
		assertEqual(2.0f, result.z, "Sum vector 1 + 1 z value");

		result = Vector3(4.5f, 10.48f, 3.76f);
		result += Vector3(17.13f, 45.003f, -1.0f);
		assertEqual(21.63f, result.x, "Sum vectors with complex numbers, x value");
		assertEqual(55.483000f, result.y, "Sum vectors with complex numbers, y value");
		assertEqual(2.76f, result.z, "Sum vectors with complex numbers, z value");

		result = Vector3::Zero;
		result += Vector3::Zero;
		assertEqual(0.0f, result.x, "Sum zero vectors results 0 in value for x");
		assertEqual(0.0f, result.y, "Sum zero vectors results 0 in value for y");
		assertEqual(0.0f, result.z, "Sum zero vectors results 0 in value for z");
	});

	test("Operator += with scalar value", []() -> void {
		Vector3 result = Vector3::One;
		result += 1;
		assertEqual(2.0f, result.x, "Sum vector 1 + 1 x value");
		assertEqual(2.0f, result.y, "Sum vector 1 + 1 y value");
		assertEqual(2.0f, result.z, "Sum vector 1 + 1 z value");

		result = Vector3(4.5f, 10.48f, 3.76f);
		result += 19.34f;
		assertEqual(23.84f, result.x, "Sum vectors with complex numbers, x value");
		assertEqual(29.82f, result.y, "Sum vectors with complex numbers, y value");
		assertEqual(23.1f, result.z, "Sum vectors with complex numbers, z value");

		result = Vector3::Zero;
		result += 0;
		assertEqual(0.0f, result.x, "Sum zero vectors results 0 in value for x");
		assertEqual(0.0f, result.y, "Sum zero vectors results 0 in value for y");
		assertEqual(0.0f, result.z, "Sum zero vectors results 0 in value for z");
	});

	test("Operator -=", []() -> void {
		Vector3 result = Vector3(2.0f, 2.0f, 2.0f);
		result -= Vector3::One;
		assertEqual(1.0f, result.x, "Subtract vector with x value 2 by 1");
		assertEqual(1.0f, result.y, "Subtract vector with y value 2 by 1");
		assertEqual(1.0f, result.z, "Subtract vector with z value 2 by 1");

		result = Vector3::One;
		result -= Vector3::One;
		assertEqual(0.0f, result.x, "Subtract vector with x value 1 by 1 should result in 0");
		assertEqual(0.0f, result.y, "Subtract vector with y value 1 by 1 should result in 0");
		assertEqual(0.0f, result.z, "Subtract vector with z value 1 by 1 should result in 0");

		result = Vector3::Zero;
		result -= Vector3::Zero;
		assertEqual(0.0f, result.x, "Subtract two zero vectors should result in 0 for x value");
		assertEqual(0.0f, result.y, "Subtract two zero vectors should result in 0 for y value");
		assertEqual(0.0f, result.z, "Subtract two zero vectors should result in 0 for z value");

		result = Vector3(4.5f, 10.48f, 3.76f);
		result -= Vector3(17.13f, 45.003f, -1.0f);
		assertEqual(-12.63f, result.x, "Subtraction of vectors with complex numbers, x value");
		assertEqual(-34.523f, result.y, "Subtraction of vectors with complex numbers, y value");
		assertEqual(4.76f, result.z, "Subtraction of vectors with complex numbers, z value");
	});

	test("Operator *=", []() -> void {
		Vector3 result = Vector3::Zero;
		result *= Vector3::Zero;
		assertEqual(0.0f, result.x, "Multiply zero vectors should result in zero for x value");
		assertEqual(0.0f, result.y, "Multiply zero vectors should result in zero for y value");
		assertEqual(0.0f, result.z, "Multiply zero vectors should result in zero for z value");

		result = Vector3::One;
		result *= Vector3::One;
		assertEqual(1.0f, result.x, "Multiply two vectors of value 1 should result in 1 for x value");
		assertEqual(1.0f, result.y, "Multiply two vectors of value 1 should result in 1 for y value");
		assertEqual(1.0f, result.z, "Multiply two vectors of value 1 should result in 1 for z value");

		result = Vector3(4.5f, 10.48f, 3.76f);
		result *= Vector3(17.13f, 45.003f, -1.0f);
		assertEqual(77.085f, result.x, "Multiply two vectors with complex number for x value");
		assertEqual(471.63144f, result.y, "Multiply two vectors with complex number for y value");
		assertEqual(-3.76f, result.z, "Multiply two vectors with complex number for z value");
	});

	test("Length", []() -> void {
		float result = Vector3::Zero.Length();
		assertEqual(0.0f, result, "Length of vector 0,0 should be 0");

		result = Vector3::One.Length();
		assertEqual(1.732050807568877f, result, "Length of vector 1,1");

		result = Vector3(2.0f, 2.0f, 2.0f).Length();
		assertEqual(3.464101615137755f, result, "Length of vector 2,2");

		result = Vector3(17.13f, 45.003f, 3.76f).Length();
		assertEqual(48.2995290763792f, result, "Length of vector with complex numbers");
	});

	test("SquaredLength", []() -> void {
		float result = Vector3::Zero.SquaredLength();
		assertEqual(0.0f, result, "Squared Length of vector 0,0 should be 0");

		result = Vector3::One.SquaredLength();
		assertEqual(3.0f, result, "Squared Length of vector 1,1 should be 3");

		result = Vector3(2.0f, 2.0f, 2.0f).SquaredLength();
		assertEqual(12.0f, result, "Squared Length of vector 2,2 should be 12");

		result = Vector3(17.13f, 45.003f, 3.76f).SquaredLength();
		assertEqual(2332.844509f, result, "Squared Length of vector with complex numbers");
	});

	test("Normalize", []() -> void {
		Vector3 result = Vector3::One;
		result.Normalize();
		assertEqual(0.5773502691896259f, result.x, "Normalized x of vector 0,0,0 should be approximately 0.57");
		assertEqual(0.5773502691896259f, result.y, "Normalized y of vector 0,0,0 should be approximately 0.57");
		assertEqual(0.5773502691896259f, result.z, "Normalized y of vector 0,0,0 should be approximately 0.57");

		result = Vector3(2.0f, 2.0f, 2.0f);
		result.Normalize();
		assertEqual(0.5773502691896257f, result.x, "Normalized x of vector 2,2,2 should be approximately 0.57");
		assertEqual(0.5773502691896257f, result.y, "Normalized y of vector 2,2,2 should be approximately 0.57");
		assertEqual(0.5773502691896257f, result.z, "Normalized z of vector 2,2,2 should be approximately 0.57");

		result = Vector3(17.13f, 45.003f, 3.76f);
		result.Normalize();
		assertEqual(0.35466184303601f, result.x, "Normalized x of vector with complex number");
		assertEqual(0.9317482149532725f, result.y, "Normalized y of vector with complex number");
		assertEqual(0.0778475499016578f, result.z, "Normalized z of vector with complex number");
	});

	test("Dot multiplication", []() -> void {
		float result = Vector3::Dot(Vector3::Zero, Vector3::Zero);
		assertEqual(0.0f, result, "Dot multiplication of vectors 0,0,0 should result in 0");

		result = Vector3::Dot(Vector3::One, Vector3::One);
		assertEqual(3.0f, result, "Dot multiplication of vectors 1,1,1 should result in 1");

		result = Vector3::Dot(Vector3(2.0f, 2.0f, 2.0f), Vector3(2.0f, 2.0f, 2.0f));
		assertEqual(12.0f, result, "Dot multiplication of vectors 2,2,2 should result in 16");

		result = Vector3::Dot(Vector3(4.5f, 10.48f, 3.76f), Vector3(17.13f, 45.003f, -1.0f));
		assertEqual(544.95644f, result, "Dot multiplication of vectors with complex numbers");
	});

	test("Cross", []() -> void {
		// TODO test not implemented
	});

	test("Reflect", []() -> void {
		// TODO test not implemented
	});
}
