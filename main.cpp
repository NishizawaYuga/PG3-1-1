#include <stdio.h>
#include <stdlib.h>

//単方向リストの構造体の定義
typedef struct CELL {
	int val;
	struct CELL* next;
}CELL;

//データを追加する関数のプロトタイプ宣言
void create(CELL* head, int val);

//一覧を表示する関数のプロトタイプ宣言
void index(CELL* head);

int main() {
	int val;
	//先頭のセルの宣言
	CELL head;
	head.next = nullptr; //Visual Stdioではnextに何らかの値が入った状態で初期化されるので、nullptrを代入する

	while (true)
	{
		printf("好きな数字を入力してください\n");
		scanf_s("%d", &val);

		create(&head, val);

		index(&head);
	}

	system("pause");
	return 0;
}

//セルを新規作成する関数
void create(CELL* head, int val) {
	CELL* cell;
	//新規作成するセル分のメモリを確保する
	cell = (CELL*)malloc(sizeof(CELL));

	cell->val = val;
	cell->next = nullptr;

	//最後(最新)のセルのアドレスの1つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当する
	while (head->next != (CELL*)nullptr) {
		head = head->next;
	}

	head->next = cell;
}

//セルの一覧を表示する関数
void index(CELL* head) {
	printf("\n");
	printf("[");
	while (head->next != nullptr) {
		head = head->next;
		printf("%d", head->val);
		if (head->next != nullptr) {
			printf(",");
		}
	}
	printf("]/\n");
}