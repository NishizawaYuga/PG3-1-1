#include "SceneManager.h"
#include <stdio.h>

SceneManager::SceneManager() {}
SceneManager::~SceneManager(){}

SceneManager* SceneManager::GetInstance() {
	//ŠÖ”“àstatic•Ï”‚Æ‚µ‚ÄéŒ¾‚·‚é
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo) {
	if (sceneNo == 0) {
		printf("SceneNo: %d\n", sceneNo);
		printf("SceneName: Title\n\n");
	}
	else if (sceneNo == 1) {
		printf("SceneNo: %d\n", sceneNo);
		printf("SceneName: NewGame\n\n");
	}
	else if (sceneNo == 2) {
		printf("SceneNo: %d\n", sceneNo);
		printf("SceneName: GamePlay\n\n");
	}
	else if (sceneNo == 3) {
		printf("SceneNo: %d\n", sceneNo);
		printf("SceneName: GameClear\n\n");
	}
}