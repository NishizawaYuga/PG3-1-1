#pragma once
#include "IShape.h"
#include <stdio.h>
#include <stdlib.h>

class Circle : IShape {
	float r = 0;
	float size = 0;
public:
	void Size() override 
	{
		printf("”¼Œa‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		scanf_s("%f\n", &r);

		size = r * r * 3.14f;
	}

	void Draw() override
	{
		printf("–ÊÏF%f\n",size);
	}
};
