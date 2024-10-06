#include "Color.h"

using namespace Towell;

const Color Color::White(1.0f, 1.0f, 1.0f, 1.0f);
const Color Color::Black(0.0f, 0.0f, 0.0f, 1.0f);
const Color Color::Red(1.0f, 0.0f, 0.0f, 1.0f);
const Color Color::Green(0.0f, 1.0f, 0.0f, 1.0f);
const Color Color::Blue(0.0f, 0.0f, 1.0f, 1.0f);
const Color Color::Transparent(0.0f, 0.0f, 0.0f, 0.0f);

Color::Color() : Color(0.0f, 0.0f, 0.0f)
{
}

Color::Color(float r, float g, float b) : Color(r, g, b, 1.0f)
{
}

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a)
{
}

Color::~Color()
{
}

float* Color::ToFloatArray() const
{
	return new float[4]{ r, g, b, a };
}

