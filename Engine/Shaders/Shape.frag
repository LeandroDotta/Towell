#version 330

uniform vec4 uColor;

// This corresponds to the output color to the color buffer
out vec4 outColor;

void main()
{
	// Sample color from texture
	outColor = uColor;;
}