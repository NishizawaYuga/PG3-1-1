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
		printf("���a�̒l����͂��Ă�������\n");
		scanf_s("%f\n", &r);

		size = r * r * 3.14f;
	}

	void Draw() override
	{
		printf("�ʐρF%f\n",size);
	}
};
