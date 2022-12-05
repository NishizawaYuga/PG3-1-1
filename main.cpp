#include <stdio.h>
#include <stdlib.h>
#include "SceneManager.h"

int main() {
	int sceneNo = 0;

	while (true) {
		printf("Press Enter to Scene Change\n");
		if (getchar() == '\n') {
			SceneManager::GetInstance()->ChangeScene(sceneNo);
			sceneNo++;
			if (sceneNo > 3) {
				sceneNo = 0;
			}
		}
	}

	system("pause");
	return 0;
}