#include "Rectangle.h"

void Rectangle::Size()
{
	printf("��ӂ̒l����͂��Ă�������\n");
	scanf_s("%f\n", &x);
	printf("�����̒l����͂��Ă�������\n");
	scanf_s("%f\n", &y);

	size = x * y;
}

void Rectangle::Draw()
{
	printf("�ʐρF%f\n", size);
}