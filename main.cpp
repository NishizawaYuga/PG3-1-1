#include <stdio.h>

template <typename T>
T Min(T a, T b) {
	if (a <= b) {
		return static_cast<T>(a);
	}
		return static_cast<T>(b);
}
template <>
char Min<char>(char a, char b) {
	return printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ");
}

void main() {
	printf("%d\n", Min<int>(10, 15));
	printf("%f\n", Min<float>(10, 15));
	printf("%lf\n", Min<double>(10, 15));
	printf("%c", Min<char>(10, 15));
}