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
//		printf("�G��|�����I\n");
//		}
//		else {
//			printf("�G��|�����I\n");
//			delete this; }
//	}
//};

//�����o�֐��|�C���^
class Enemy {
public:
	//��ԑJ��
	void ChangeFhase(int number);
private:
	//�ߐ�
	void Melee();
	//�ˌ�
	void Shooting();
	//���E
	void Secession();
	//�����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* spFuncTable[])();
};