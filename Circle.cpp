#include "Circle.h"

void Circle::Size()
{
	printf("���a�̒l����͂��Ă�������\n");
	scanf_s("%f\n", &r);

	size = r * r * 3.14f;
}

void Circle::Draw()
{
	printf("�ʐρF%f\n", size);
}