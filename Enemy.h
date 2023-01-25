#pragma once
#include <stdio.h>
#include <stdlib.h>

//class Enemy {
//protected:
//public:
//	static int enemyCount;
//	Enemy() { enemyCount++; }
//	~Enemy() {
//		if (enemyCount != 0) { enemyCount = 0;
//		printf("敵を倒した！\n");
//		}
//		else {
//			printf("敵を倒した！\n");
//			delete this; }
//	}
//};

//メンバ関数ポインタ
class Enemy {
public:
	//状態遷移
	void ChangeFhase(int number);
private:
	//近接
	void Melee();
	//射撃
	void Shooting();
	//離脱
	void Secession();
	//メンバ関数ポインタのテーブル
	static void (Enemy::* spFuncTable[])();
};