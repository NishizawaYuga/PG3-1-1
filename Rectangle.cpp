#include "Rectangle.h"

void Rectangle::Size()
{
	printf("底辺の値を入力してください\n");
	scanf_s("%f\n", &x);
	printf("高さの値を入力してください\n");
	scanf_s("%f\n", &y);

	size = x * y;
}

void Rectangle::Draw()
{
	printf("面積：%f\n", size);
}