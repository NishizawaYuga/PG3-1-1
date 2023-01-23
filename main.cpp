#include <stdio.h>
#include <functional>
#include <Windows.h>

typedef void (*pFunc)(int*, int*);

//結果発表関数
void Answer(int* numbers, int* answer) {
	if (&numbers == &answer) {
		printf("正解！");
	}
	else {
		printf("ハズレ！");
	}
}

void SetTime(pFunc p, int numbers, int answer) {
	//Sleep(2400);

	//結果発表の関数を呼び出す
	p(&numbers, &answer);
}

int main(void) {
	int numbers;
	while (1) {
		printf("奇数か偶数か、数字でお答えください（奇数なら1,偶数なら2)：");
		scanf_s("%d", &numbers);
		if (numbers < 1 || numbers > 2) {
			printf("\n1か2でお答えください\n");
		}
		else {
			break;
		}
	}

	//結果ランダム生成
	int answer = rand();
	if (answer % 2 == 0) {
		answer = 2;
	}
	else if (answer % 2 == 1) {
		answer = 1;
	}

	//結果発表
	pFunc p;
	p = Answer;
	//SetTime(p, numbers, answer);
	[&]() {Sleep(2400);p(&numbers, &answer); }();
	std::function<int(int)> judge = [=](int i) {return i * answer; };
	printf("\nサイコロの出目：%d",judge(rand() % 3 + 1));

	return 0;
}