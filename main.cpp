#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main() {
	//�v�Z���@�Ȃǂ�ς���ϐ�
	int scene = 0;
	Circle circle;
	Rectangle rectangle;

	while (true)
	{
		printf("0�F�I��\n");
		printf("1�F�~�̖ʐόv�Z\n");
		printf("2�F�Z�`�̖ʐόv�Z\n");
		printf("3�F�~�̖ʐϕ\��\n");
		printf("4�F�Z�`�̖ʐϕ\��\n");
		scanf_s("%d\n", &scene);

		if (scene == 0) {
			break;
		}
		else if (scene == 1) {
			circle.Size();
		}
		else if (scene == 2) {
			rectangle.Size();
		}
		else if (scene == 3) {
			circle.Draw();
		}
		else if (scene == 4) {
			rectangle.Draw();
		}
	}


	system("pause");
	return 0;
}