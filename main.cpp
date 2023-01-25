#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
using namespace std;

int main() {
	//行動
	int move = 0;
	//状態遷移のカウント
	int phase = 0;

	Enemy enemy;

	while (true)
	{
		printf("0を入力すると敵の状態が進む\n");
		scanf_s("%d\n",&move);
		if (move == 0) {
			enemy.ChangeFhase(phase);
			phase++;
			if (phase > 2) {
				break;
			}
		}
	}

	system("pause");
	return 0;
}