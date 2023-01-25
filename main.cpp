#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
using namespace std;

int main() {
	//計算方法などを変える変数
	int scene = 0;
	Circle circle;
	Rectangle rectangle;

	while (true)
	{
		printf("0：終了\n");
		printf("1：円の面積計算\n");
		printf("2：短形の面積計算\n");
		printf("3：円の面積表示\n");
		printf("4：短形の面積表示\n");
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