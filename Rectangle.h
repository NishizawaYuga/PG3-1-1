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
		printf("��ӂ̒l����͂��Ă�������\n");
		scanf_s("%f\n", &x);
		printf("�����̒l����͂��Ă�������\n");
		scanf_s("%f\n", &y);

		size = x * y;
	}

	void Draw() override
	{
		printf("�ʐρF%f\n", size);
	}
};
