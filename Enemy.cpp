#include "Enemy.h"

void (Enemy2::* Enemy2::spFuncTable[])() {
	&Enemy2::Melee,	//—v‘f”Ô†0
		& Enemy2::Shooting,	//—v‘f”Ô†1
		& Enemy2::Secession	//—v‘f”Ô†2
};

void Enemy2::Melee() {
	printf("“G‚Ì‹ßÚUŒ‚I\n");
}

void Enemy2::Shooting() {
	printf("“G‚Ì‰“‹——£UŒ‚I\n");
}

void Enemy2::Secession() {
	printf("“G‚Í“¦‚°o‚µ‚½I\n");
}