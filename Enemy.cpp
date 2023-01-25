#include "Enemy.h"

void (Enemy::* Enemy::spFuncTable[])() {
	&Enemy::Melee,	//—v‘f”Ô†0
		& Enemy::Shooting,	//—v‘f”Ô†1
		& Enemy::Secession	//—v‘f”Ô†2
};

void Enemy::Melee() {
	printf("“G‚Ì‹ßÚUŒ‚I\n");
}

void Enemy::Shooting() {
	printf("“G‚Ì‰“‹——£UŒ‚I\n");
}

void Enemy::Secession() {
	printf("“G‚Í“¦‚°o‚µ‚½I\n");
}

void Enemy::ChangeFhase(int number) {
	(this->*spFuncTable[number])();
}