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
		printf("底辺の値を入力してください\n");
		scanf_s("%f\n", &x);
		printf("高さの値を入力してください\n");
		scanf_s("%f\n", &y);

		size = x * y;
	}

	void Draw() override
	{
		printf("面積：%f\n", size);
	}
};
