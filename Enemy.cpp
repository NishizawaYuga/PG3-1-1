#include "Enemy.h"

void (Enemy2::* Enemy2::spFuncTable[])() {
	&Enemy2::Melee,	//�v�f�ԍ�0
		& Enemy2::Shooting,	//�v�f�ԍ�1
		& Enemy2::Secession	//�v�f�ԍ�2
};

void Enemy2::Melee() {
	printf("�G�̋ߐڍU���I\n");
}

void Enemy2::Shooting() {
	printf("�G�̉������U���I\n");
}

void Enemy2::Secession() {
	printf("�G�͓����o�����I\n");
}