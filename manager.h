#pragma once
#include <iostream>
using namespace std;

//担当者データ
struct DataManager {
	//担当者ID
	int id;
	//担当者名
	string name;
	//クラス
	char classNumber[4];
	//データがあるかどうかのフラグ
	bool dataRetention = false;
};

//担当者クラス
class Manager {
public:
	//担当者データ作成
	void CreateManager();
	//担当者データ削除
	void DeleteManager();
	//担当者データ閲覧
	void BrowseData();
	//データ変更
	void ChangeManagerData(int changeID);
	//リスト表示
	void ViewList();
	//担当者データアクセス
	DataManager AccessData(int num);
private:
	//担当者格納
	DataManager managerData[1000];
	//コマンド指示のための変数
	int instructionsNum = 0;
	//データ格納数
	const int dataNum = 1000;
};
