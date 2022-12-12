#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
using namespace std;

int Enemy::enemyCount;

int main() {
	int move = 0;
	Enemy* enemy1 = new Enemy;
	printf("“G%d‚ªŒ»‚ê‚½I\n", Enemy::enemyCount);
	Enemy* enemy2 = new Enemy;
	printf("“G%d‚ªŒ»‚ê‚½I\n", Enemy::enemyCount);
	Enemy* enemy3 = new Enemy;
	printf("“G%d‚ªŒ»‚ê‚½I\n", Enemy::enemyCount);

	while (Enemy::enemyCount) {
		printf("\n‚Ç‚¤‚·‚éH\n");
		printf("1.“G1‚ğUŒ‚‚·‚é\n");
		printf("2.“G2‚ğUŒ‚‚·‚é\n");
		printf("3.“G3‚ğUŒ‚‚·‚é\n");
		printf("4.‰½‚à‚µ‚È‚¢\n");
		printf("“G‚Ì”F%d\n",Enemy::enemyCount);
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
			//‰½‚à‚µ‚È‚¢‚Ì‚Å‚»‚Ì‚Ü‚ÜÅ‰‚Ö
		}
	}
	printf("“G‚ğ‘S‚Ä“|‚µ‚½I\n");
	printf("“G‚Ì”F%d\n", Enemy::enemyCount);

	system("pause");
	return 0;
}