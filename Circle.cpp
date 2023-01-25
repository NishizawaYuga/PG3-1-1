#include "Circle.h"

void Circle::Size()
{
	printf("”¼Œa‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf_s("%f\n", &r);

	size = r * r * 3.14f;
}

void Circle::Draw()
{
	printf("–ÊÏF%f\n", size);
}