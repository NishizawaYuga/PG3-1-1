#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
using namespace std;

int Enemy::enemyCount;

int main() {
	//行動
	int move = 0;
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;
	printf("敵が現れた！\n");

	while (Enemy::enemyCount) {
		printf("敵の数：%d\n", Enemy::enemyCount);
		printf("0を入力すると敵が全滅する\n");
		scanf_s("%d", &move);

		if (move == 0) {
			delete enemy1;
			delete enemy2;
			delete enemy3;
		}
	}
	printf("敵を全て倒した！\n");

	system("pause");
	return 0;
}