#include <stdio.h>

int Recursive(int n) {
	if (n <= 1) {
		return (100);
	}

	return (Recursive(n - 1) * 2 - 50);
}

void main() {
	printf("��ʓI�Ȓ����̌n��5���ԁF%d\n", 1072 * 5);
	printf("�ċN�I�Ȓ����̌n��5���ԁF%d", Recursive(5));
}