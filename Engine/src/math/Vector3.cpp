#include "Vector3.h"

using namespace Towell;

const Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::One(1.0f, 1.0f, 1.0f);
const Vector3 Vector3::Up(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::Right(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Down(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::Left(-1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Forward(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::Infinity(Math::Infinity, Math::Infinity, Math::Infinity);
const Vector3 Vector3::NegativeInfinity(Math::NegativeInfinity, Math::NegativeInfinity, Math::NegativeInfinity);