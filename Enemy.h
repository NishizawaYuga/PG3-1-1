#pragma once

class Enemy {
protected:
public:
	static int enemyCount;
	Enemy() { enemyCount++; }
	~Enemy() {
		if (enemyCount != 0) { enemyCount = 0;
		printf("�G��|�����I\n");
		}
		else {
			printf("�G��|�����I\n");
			delete this; }
	}
};
