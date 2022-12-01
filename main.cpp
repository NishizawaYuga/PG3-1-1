#include <stdio.h>
#include <stdlib.h>

//単方向リストの構造体の定義
typedef struct CELL {
	int year;
	int month;
	int day;
	struct CELL* next;
}CELL;

//データを追加する関数のプロトタイプ宣言
void create(CELL* head, int val);

//一覧を表示する関数のプロトタイプ宣言
void index(CELL* head);

//入力方法が合ってるかチェックする関数
void inputCheck(CELL* head, int val);

int main() {
	int val;
	//先頭のセルの宣言
	CELL head;
	head.next = nullptr; //Visual Stdioではnextに何らかの値が入った状態で初期化されるので、nullptrを代入する

	while (true)
	{
		printf("年月日を入力してください（例：20220101）\n");
		scanf_s("%d", &val);

		inputCheck(&head, val);
	}

	system("pause");
	return 0;
}

//入力方法が合ってるかチェックする関数
void inputCheck(CELL* head, int val) {

	if (val / 10000000 < 1 || val / 10000000 > 12) {
		printf("入力情報が間違っています\n");
	}
	else {
		//最後尾にセルを追加
		create(head, val);

		//リスト一覧の表示
		index(head);
	}
}

//セルを新規作成する関数
void create(CELL* head, int val) {
	CELL* cell;
	//新規作成するセル分のメモリを確保する
	cell = (CELL*)malloc(sizeof(CELL));

	//年の抽出
	int year = val / 10000;
	cell->year = year;
	//月の抽出
	int month = val % 10000;
	month = month / 100;
	cell->month = month;
	//日付の抽出
	int day = val % 100;
	cell->day = day;
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
	while (head->next != nullptr) {
		head = head->next;
		printf("%d/%d/%d\n", head->year, head->month, head->day);
	}
}