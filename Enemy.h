#pragma once

class Enemy {
protected:
public:
	static int enemyCount;
	Enemy() { enemyCount++; }
	~Enemy() {
		printf("�G��|�����I\n");
		enemyCount--;
		printf("�G�̐��F%d\n",enemyCount);
	}
};
