#include "Enemy.h"

void (Enemy::* Enemy::spFuncTable[])() {
	&Enemy::Melee,	//�v�f�ԍ�0
		& Enemy::Shooting,	//�v�f�ԍ�1
		& Enemy::Secession	//�v�f�ԍ�2
};

void Enemy::Melee() {
	printf("�G�̋ߐڍU���I\n");
}

void Enemy::Shooting() {
	printf("�G�̉������U���I\n");
}

void Enemy::Secession() {
	printf("�G�͓����o�����I\n");
}

void Enemy::ChangeFhase(int number) {
	(this->*spFuncTable[number])();
}