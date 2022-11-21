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
	int val = 20221031;
	//先頭のセルの宣言
	CELL head;
	head.next = nullptr; //Visual Stdioではnextに何らかの値が入った状態で初期化されるので、nullptrを代入する

	while (true)
	{
		scanf_s("% d", &val);

		//最後尾にセルを追加
		create(&head, 20221103);

		//リスト一覧の表示
		index(&head);
	}

	return 0;
}

//セルを新規作成する関数
void create(CELL* head, int val) {
	CELL *cell;
	//新規作成するセル分のメモリを確保する
	cell = (CELL*)malloc(sizeof(CELL));

	cell->val = val;
	cell->next = nullptr;

	//最後(最新)のセルのアドレスの1つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当する
	while (&head->next != nullptr) {
		*head->next = *head->next->next;
	}

	*head->next = *cell;
}

//セルの一覧を表示する関数
void index(CELL* head) {
	while (head->next != nullptr) {
		head->next = head->next->next;
		printf("%d\n", head->next->val);
	}
}