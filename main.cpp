#include <stdio.h>
#include <functional>
#include <Windows.h>

typedef void (*pFunc)(int*, int*);

//���ʔ��\�֐�
void Answer(int* numbers, int* answer) {
	if (&numbers == &answer) {
		printf("�����I");
	}
	else {
		printf("�n�Y���I");
	}
}

void SetTime(pFunc p, int numbers, int answer) {
	//Sleep(2400);

	//���ʔ��\�̊֐����Ăяo��
	p(&numbers, &answer);
}

int main(void) {
	int numbers;
	while (1) {
		printf("����������A�����ł��������������i��Ȃ�1,�����Ȃ�2)�F");
		scanf_s("%d", &numbers);
		if (numbers < 1 || numbers > 2) {
			printf("\n1��2�ł�������������\n");
		}
		else {
			break;
		}
	}

	//���ʃ����_������
	int answer = rand();
	if (answer % 2 == 0) {
		answer = 2;
	}
	else if (answer % 2 == 1) {
		answer = 1;
	}

	//���ʔ��\
	pFunc p;
	p = Answer;
	//SetTime(p, numbers, answer);
	[&]() {Sleep(2400);p(&numbers, &answer); }();
	std::function<int(int)> judge = [=](int i) {return i * answer; };
	printf("\n�T�C�R���̏o�ځF%d",judge(rand() % 3 + 1));

	return 0;
}