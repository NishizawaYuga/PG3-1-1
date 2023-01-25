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
		printf("半径の値を入力してください\n");
		scanf_s("%f\n", &r);

		size = r * r * 3.14f;
	}

	void Draw() override
	{
		printf("面積：%f\n",size);
	}
};
