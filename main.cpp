#include <stdio.h>

int Recursive(int n) {
	if (n <= 0) {
		return (100);
	}
	return (Recursive(n - 1) * 2 - 50);
}

void main() {
	int time = 8;
	int total = 0;
	printf("��ʓI�Ȓ����̌n��%d���ԁF%d\n",time, 1072 * time);
	for (int i = 0; i < time; i++) {
		total += Recursive(i);
	}
	printf("�ċA�I�Ȓ����̌n��%d���ԁF%d",time, total);
}