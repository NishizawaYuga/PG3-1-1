#include "Circle.h"

void Circle::Size()
{
	printf("半径の値を入力してください\n");
	scanf_s("%f\n", &r);

	size = r * r * 3.14f;
}

void Circle::Draw()
{
	printf("面積：%f\n", size);
}