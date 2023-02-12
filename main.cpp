#include <iostream>
#include "manager.h"
#include "task.h"
using namespace std;


void main() {
	//二つのクラス宣言
	Task task;
	Manager manager;

	//入力制御用番号
	int instructionsNum = 0;

	while (true) {
		cout << "行いたい操作を選んでください" << endl;
		cout << "0 : 担当者データの作成" << endl;
		cout << "1 : 担当者データの変更" << endl;
		cout << "2 : 担当者データの閲覧" << endl;
		cout << "3 : 担当者データの削除" << endl;
		cout << "4 : タスクデータの作成" << endl;
		cout << "5 : タスクデータの変更" << endl;
		cout << "6 : タスクデータの閲覧" << endl;
		cout << "7 : タスクデータの削除" << endl;
		cout << "8 : 担当者のデータリスト" << endl;
		cout << "9 : タスクのデータリスト" << endl;
		cout << "10 : 終了" << endl;

		//番号入力で指示
		cin >> instructionsNum;
		if (instructionsNum == 0) {
			manager.CreateManager();
		}
		else if (instructionsNum == 1) {
			cout << "変更したい担当者IDを入力してください" << endl;
			cin >> instructionsNum;
			manager.ChangeManagerData(instructionsNum);
		}
		else if (instructionsNum == 2) {
			manager.BrowseData();
		}
		else if (instructionsNum == 3) {
			manager.DeleteManager();
		}
		else if (instructionsNum == 4) {
			task.CreateTask(manager);
		}
		else if (instructionsNum == 5) {
			cout << "変更したいタスクIDを入力してください" << endl;
			cin >> instructionsNum;
			task.ChangeTask(instructionsNum,manager);
		}
		else if (instructionsNum == 6) {
			task.BrowseTask();
		}
		else if (instructionsNum == 7) {
			task.DeleteTask();
		}
		else if (instructionsNum == 8) {
			manager.ViewList();
		}
		else if (instructionsNum == 9) {
			task.ViewList();
		}
		else if (instructionsNum == 10) {
			break;
		}
		else {
			cout << "指定された番号を入力してください" << endl;
		}
	}
}
