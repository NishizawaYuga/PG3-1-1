#include <stdio.h>

int Recursive(int n) {
	if (n <= 1) {
		return (100);
	}

	return (Recursive(n - 1) * 2 - 50);
}

void main() {
	printf("一般的な賃金体系で5時間：%d\n", 1072 * 5);
	printf("再起的な賃金体系で5時間：%d", Recursive(5));
}