#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
using namespace std;

int Enemy::enemyCount;

int main() {
	int move = 0;
	Enemy* enemy1 = new Enemy;
	printf("�G%d�����ꂽ�I\n", Enemy::enemyCount);
	Enemy* enemy2 = new Enemy;
	printf("�G%d�����ꂽ�I\n", Enemy::enemyCount);
	Enemy* enemy3 = new Enemy;
	printf("�G%d�����ꂽ�I\n", Enemy::enemyCount);

	while (Enemy::enemyCount) {
		printf("\n�ǂ�����H\n");
		printf("1.�G1���U������\n");
		printf("2.�G2���U������\n");
		printf("3.�G3���U������\n");
		printf("4.�������Ȃ�\n");
		printf("�G�̐��F%d\n",Enemy::enemyCount);
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
			//�������Ȃ��̂ł��̂܂܍ŏ���
		}
	}
	printf("�G��S�ē|�����I\n");
	printf("�G�̐��F%d\n", Enemy::enemyCount);

	system("pause");
	return 0;
}