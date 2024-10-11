#ifndef TOWELL_COLOR_H
#define TOWELL_COLOR_H

#include <string>

namespace Towell
{
	struct Color
	{
	public:
		float r;
		float g;
		float b;
		float a;

		Color();
		Color(float r, float g, float b);
		Color(float r, float g, float b, float a);
		~Color();

		float* ToFloatArray() const;

		static Color Parse(char* hexColor);

		static const Color White;
		static const Color Black;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Transparent;
	};
}

#endif // TOWELL_COLOR_H

