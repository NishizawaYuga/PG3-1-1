#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
using namespace std;

int Enemy::enemyCount;

int main() {
	//�s��
	int move = 0;
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;
	Enemy* enemy3 = new Enemy;
	printf("�G�����ꂽ�I\n");

	while (Enemy::enemyCount) {
		printf("�G�̐��F%d\n", Enemy::enemyCount);
		printf("0����͂���ƓG���S�ł���\n");
		scanf_s("%d", &move);

		if (move == 0) {
			delete enemy1;
			delete enemy2;
			delete enemy3;
		}
	}
	printf("�G��S�ē|�����I\n");

	system("pause");
	return 0;
}