#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
	// int型配列 a (要素数:10)
	//int a[10];
	// int型の可変長配列 b (要素数:0)
	//vector<int> b;

	//vector

	//要素数の読み書き
	//float型の可変長配列 c (要素数:3)
	vector<float> c = { 0.0f,1.0f,2.0f };

	//添字1の要素を表示（1.0）
	printf(" %f\n", c[1]);

	//添字1の様子に-1.5を代入
	c[1] = -1.5f;

	//添字1の要素を表示（-1.5）
	printf(" %f\n", c[1]);

	//要素数の変更
	//int型の可変長配列 d (要素数：0)
	vector<int> d;

	//様子数を10個に変更（空白文字列で初期化される）
	d.resize(10);

	//要素数を取得
	int size = d.size();

	//全要素を表示
	for (int i = 0; i < size; i++) {
		printf("%d\n", d[i]);
	}

	////イテレータ
	//vector<int> e = { 1,2,3 };

	////int型の可変長配列用のイテレータ
	//vector<int>::iterator it;

	////eの先頭要素を指す
	//it = e.begin();

	////itが指している要素を表示
	//cout << *it << endl;

	////次の要素に移動
	//it++;

	////itが指している要素を表示
	//cout << *it << endl;

	//system("pause");
	return 0;
}