#include "Color.h"
#include <sstream>
#include <iomanip>

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

Color Color::Parse(char* hexColor)
{
	std::string hex(hexColor);

	// Remove '#' if present
	if (hex[0] == '#') {
		hex = hex.substr(1);
	}

	int r, g, b, a = 255;

	// Handle 3 digit hex string (RGB)
	if (hex.length() == 3)
	{
		std::stringstream(hex[0]) >> std::hex >> r;
		std::stringstream(hex[1]) >> std::hex >> g;
		std::stringstream(hex[2]) >> std::hex >> b;
	}
	else if (hex.length() == 4)
	{
		std::stringstream(hex[0]) >> std::hex >> r;
		std::stringstream(hex[1]) >> std::hex >> g;
		std::stringstream(hex[2]) >> std::hex >> b;
		std::stringstream(hex[3]) >> std::hex >> a;
	}
	else if (hex.length() == 6)
	{
		std::stringstream(hex.substr(0, 2)) >> std::hex >> r;
		std::stringstream(hex.substr(2, 2)) >> std::hex >> g;
		std::stringstream(hex.substr(4, 2)) >> std::hex >> b;
	}
	else if (hex.length() == 8)
	{
		std::stringstream(hex.substr(0, 2)) >> std::hex >> r;
		std::stringstream(hex.substr(2, 2)) >> std::hex >> g;
		std::stringstream(hex.substr(4, 2)) >> std::hex >> b;
		std::stringstream(hex.substr(6, 2)) >> std::hex >> a;
	}
	else
	{
		throw std::invalid_argument("Invalid hexadecimal color format");
	}

	return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}

