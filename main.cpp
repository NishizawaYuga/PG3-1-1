#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//単方向リストの構造体の定義
typedef struct CELL {
	char word[100];
	struct CELL* next;
}CELL;

//データを追加する関数のプロトタイプ宣言
void create(CELL* head, int val);

//一覧を表示する関数のプロトタイプ宣言
void index(CELL* head);

int main() {
	char word[100];
	//先頭のセルの宣言
	CELL head;
	head.next = nullptr; //Visual Stdioではnextに何らかの値が入った状態で初期化されるので、nullptrを代入する

	while (true)
	{
		printf("[要素の操作]\n");
		printf("1.要素の一覧表示\n");
		printf("2.最後尾に要素の挿入\n");
		printf("3.最後尾の要素の削除\n\n");
		printf("-------------------------------------------\n");
		printf("操作を選択してください\n");
		scanf_s("%d", &val);

		if (val == 1) {
			index(&head);
		}
		create(&head, val);
		printf("\n-------------------------------------------\n");
		printf("0.初期画面に戻る\n");
		scanf_s("%d", &val);
		if (val != 0) {
			break;
		}
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
	int num = 0;
	printf("\n[要素一覧の表示]\n");
	printf("要素一覧:{\n");
	while (head->next != nullptr) {
		head = head->next;
		printf(" %d: """);
		for (int i = 0; i < strlen(head->word); i++) {
			printf("%c", head->word[i]);
		}
		if (head->next != nullptr) {
			printf(",\n");
		}
		else {
			printf("\n}");
		}
		num++;
	}
	printf("\n要素数: %d\n",num);
}