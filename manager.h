#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

//担当者データ
struct DataManager {
	//担当者ID
	string id;
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
	//担当者データアクセス
	DataManager AccessData(int num);
private:
	//データ変更
	void ChangeManagerData(int changeID);
private:
	//担当者格納
	DataManager managerData[1000];
	//コマンド指示のための変数
	int instructionsNum = 0;
	//データ格納数
	const int dataNum = 1000;
	//クラス認証（一致するもののみ通すようにするため）
	const char classNum[4] = { 1,2,3,4 };
	const char classChar[5] = "ABCD";
};
