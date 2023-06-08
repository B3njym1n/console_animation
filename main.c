#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main(int argc, char** argv)
{
	uint16_t width = 120;
	uint16_t height = 30;
	float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;
	char gradient[] = " .a@";
	int gradientSize = 3;
	char* screen = (char*)calloc(width * height + 1, sizeof (char));
	screen[width * height] = '\0';
	for (int t = 0; t < 10000; ++t)
	{
		for (uint16_t i = 0; i < width; ++i) {
			for (uint16_t j = 0; j < height; ++j) {
				float x = (float)i / width * 2.0f - 1.0f;
				float y = (float)j / height * 2.0f - 1.0f;
				x *= aspect * pixelAspect;
				x += sin(t * 0.001);
				char pixel = ' ';
				float dist = sqrt(x * x + y * y);
				int color = (int)(1.0f / dist);
				if (color < 0) color = 0;
				else if (color > gradientSize) color = gradientSize;
				pixel = gradient[color];
				//if (x * x + y * y < 0.5) pixel = '@';
				screen[i + j * width] = pixel;
			}
		}
		printf("%s", screen);
	}
	
	getchar();
	return EXIT_SUCCESS;
}