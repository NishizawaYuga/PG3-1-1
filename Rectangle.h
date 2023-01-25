#pragma once
#include "IShape.h"
#include <stdio.h>
#include <stdlib.h>

class Rectangle : IShape {
	float x = 0;
	float y = 0;
	float size = 0;
public:
	void Size() override
	{
		printf("’ê•Ó‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		scanf_s("%f\n", &x);
		printf("‚‚³‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		scanf_s("%f\n", &y);

		size = x * y;
	}

	void Draw() override
	{
		printf("–ÊÏF%f\n", size);
	}
};
