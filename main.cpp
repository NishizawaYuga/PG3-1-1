#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Enemy.h"
using namespace std;

int main() {
	//�s��
	int move = 0;
	//��ԑJ�ڂ̃J�E���g
	int phase = 0;

	Enemy enemy;

	while (true)
	{
		printf("0����͂���ƓG�̏�Ԃ��i��\n");
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