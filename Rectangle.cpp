#include "Rectangle.h"

void Rectangle::Size()
{
	printf("’ê•Ó‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf_s("%f\n", &x);
	printf("‚‚³‚Ì’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
	scanf_s("%f\n", &y);

	size = x * y;
}

void Rectangle::Draw()
{
	printf("–ÊÏF%f\n", size);
}