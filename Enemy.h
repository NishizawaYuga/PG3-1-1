#pragma once

class Enemy {
protected:
public:
	static int enemyCount;
	Enemy() { enemyCount++; }
	~Enemy() {
		printf("“G‚ğ“|‚µ‚½I\n");
		enemyCount--;
		printf("“G‚Ì”F%d\n",enemyCount);
	}
};
