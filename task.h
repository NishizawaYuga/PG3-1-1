#pragma once
#include <iostream>
#include "manager.h"
using namespace std;

//タスクデータ
struct TaskData {
	//タスクid
	int id;
	//担当者
	string managerName;
	//タスク名
	string name;
	//内容
	string content;
	//優先度
	int priority;
	//期限
	int deadlineYear;
	int deadlineMonth;
	int deadlineDay;
	//ステータス
	int state;
	//データ有無
	bool dataRetention = false;
};

//タスククラス
class Task {
public:
	//タスク新規作成
	void CreateTask(Manager managerData);
	//タスク削除
	void DeleteTask();
	//タスク閲覧
	void BrowseTask();
	//タスク変更
	void ChangeTask(int taskID, Manager managerData);
	//リスト表示
	void ViewList();
private:
	//日付入力
	void InputDate(int taskID);
	//優先度表示
	string ViewPriority(int num);
	//状態表示
	string ViewState(int num);
private:
	//タスクリスト
	TaskData taskData[1000];
	//データ格納数
	const int dataNum = 1000;
	//コマンド指示のための変数
	int instructionsNum = 0;
};