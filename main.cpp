#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
using namespace std;

int Enemy::enemyCount;

int main() {
	int move = 0;
	Enemy* enemy1 = new Enemy;
	printf("敵%dが現れた！\n", Enemy::enemyCount);
	Enemy* enemy2 = new Enemy;
	printf("敵%dが現れた！\n", Enemy::enemyCount);
	Enemy* enemy3 = new Enemy;
	printf("敵%dが現れた！\n", Enemy::enemyCount);

	while (Enemy::enemyCount) {
		printf("\nどうする？\n");
		printf("1.敵1を攻撃する\n");
		printf("2.敵2を攻撃する\n");
		printf("3.敵3を攻撃する\n");
		printf("4.何もしない\n");
		printf("敵の数：%d\n",Enemy::enemyCount);
		scanf_s("%d", &move);

		if (move == 1) {
			delete enemy1;
		}
		else if (move == 2) {
			delete enemy2;
		}
		else if (move == 3) {
			delete enemy3;
		}
		else if (move == 4) {
			//何もしないのでそのまま最初へ
		}
	}
	printf("敵を全て倒した！\n");
	printf("敵の数：%d\n", Enemy::enemyCount);

	system("pause");
	return 0;
}