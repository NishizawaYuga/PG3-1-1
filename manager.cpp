#include "manager.h"
//#include <fstream>

void Manager::CreateManager()
{
	//データを入れる番号検索
	int newNum = 0;
	for (int i = 0; i < dataNum; i++) {
		if (!managerData[i].dataRetention) {
			newNum = i;
			break;
		}
		else if (managerData[999].dataRetention)
		{
			//全てのデータが埋まっていたら1000を返す
			newNum = 1000;
		}
	}

	//データに空きがある場合のみ
	if (newNum < 1000) {
		//クラス名入力
		cout << "担当者の新規作成を行います" << endl;
		cout << "あなたのクラスを入力してください" << endl;
		cin >> managerData[newNum].classNumber;

		//担当者名入力
		cout << "担当者の名前を入力してください" << endl;
		cin >> managerData[newNum].name;
		cout << "" << endl;

		//idは連番
		managerData[newNum].id = newNum;

		//データの確認
		cout << "入力データの確認を行います" << endl;
		cout << "【ID】" << endl;
		cout << managerData[newNum].id << "\n" << endl;
		cout << "【クラス】" << endl;
		cout << managerData[newNum].classNumber << "\n" << endl;
		cout << "【名前】" << endl;
		cout << managerData[newNum].name << "\n" << endl;
		//データの有無フラグオン
		managerData[newNum].dataRetention = true;

		while (true) {
			cout << "問題なければ0を、修正したい場所がある場合は" << endl;
			cout << "1を入力してください" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "このデータで保存します" << endl;
				cout << "修正したい箇所がありましたら「担当者データ変更」から" << endl;
				cout << "お願いします" << endl;
				break;
			}
			else if (instructionsNum == 1) {
				ChangeManagerData(newNum);
				break;
			}
			else {
				cout << "0か1で入力してください" << endl;
			}
		}
	}
	else {
		cout << "空きデータがありません、既存データを削除してください" << endl;
	}
}

void Manager::DeleteManager()
{
	//削除するID番号
	int deleteNum = 0;
	cout << "削除したいID番号を入力してください(001などは1と入力)" << endl;
	cout << "キャンセルしたい場合は「1000」と入力してください" << endl;
	cin >> deleteNum;

	if (deleteNum < 1000 && deleteNum > -1) {
		//データ有無のチェック
		if (!managerData[deleteNum].dataRetention)
		{
			cout << "このIDにはデータがありません" << endl;
		}
		else {
			while (true) {
				cout << "このID番号の担当者データを削除しますか？" << endl;
				cout << "0 : はい" << endl;
				cout << "1 : いいえ" << endl;
				cin >> instructionsNum;
				if (instructionsNum == 0) {
					for (int i = 0; i < 4; i++) {
						managerData[deleteNum].classNumber[i] = '0';
					}
					managerData[deleteNum].name = "";
					managerData[deleteNum].dataRetention = false;
					cout << "担当者データを削除しました" << endl;
					break;
				}
				else if (instructionsNum == 1) { break; }
				else {
					cout << "0か1で入力してください" << endl;
				}
			}
		}
	}
	else {
		cout << "指定された番号以外を入力しないでください" << endl;
	}
}

void Manager::BrowseData()
{
	//閲覧するID番号
	int num = 0;
	cout << "閲覧したいID番号を入力してください(001などは1と入力)" << endl;
	cout << "キャンセルしたい場合は「1000」と入力してください" << endl;
	cin >> num;

	if (num < 1000 && num > -1) {
		if (managerData[num].dataRetention) {
			cout << "【ID】" << endl;
			cout << managerData[num].id << "\n" << endl;
			cout << "【クラス】" << endl;
			cout << managerData[num].classNumber << "\n" << endl;
			cout << "【名前】" << endl;
			cout << managerData[num].name << "\n" << endl;
		}
		else {
			cout << "このIDはデータがありません" << endl;
		}
	}
	else {
		cout << "指定された番号以外を入力しないでください" << endl;
	}
}

void Manager::ChangeManagerData(int changeID)
{
	if (managerData[changeID].dataRetention) {
		cout << "【ID】" << endl;
		cout << managerData[changeID].id << "\n" << endl;
		cout << "【クラス】" << "" << endl;
		cout << managerData[changeID].classNumber << "\n" << endl;
		cout << "【名前】" << "" << endl;
		cout << managerData[changeID].name << "\n" << endl;
		while (true) {
			cout << "変更したい箇所を番号で入力してください" << endl;
			cout << "0 : クラス" << endl;
			cout << "1 : 担当者名" << endl;
			cout << "2 : キャンセル" << endl;

			cin >> instructionsNum;
			if (instructionsNum == 0) {
				//クラス名入力
				cout << "担当者の新規作成を行います" << endl;
				cout << "あなたのクラスを入力してください" << endl;
				cin >> managerData[changeID].classNumber;
			}
			else if (instructionsNum == 1) {
				//担当者名入力
				cout << "担当者の名前を入力してください" << endl;
				cin >> managerData[changeID].name;
				cout << "" << endl;
			}
			else if (instructionsNum == 2) {
				break;
			}
			else {
				cout << "0～2で入力してください" << endl;
			}
			//データの確認
			cout << "入力データの確認を行います" << endl;
			cout << "【ID】" << endl;
			cout << managerData[changeID].id << "\n" << endl;
			cout << "【クラス】" << "" << endl;
			cout << managerData[changeID].classNumber << "\n" << endl;
			cout << "【名前】" << "" << endl;
			cout << managerData[changeID].name << "\n" << endl;

			while (true) {
				cout << "問題なければ0を、修正したい場所がある場合は" << endl;
				cout << "1を入力してください" << endl;
				cin >> instructionsNum;
				if (instructionsNum == 0) {
					cout << "このデータで保存します" << endl;
					cout << "修正したい箇所がありましたら「担当者データ変更」から" << endl;
					cout << "お願いします" << endl;
					break;
				}
				else if (instructionsNum == 1) {

				}
				else {
					cout << "0か1で入力してください" << endl;
				}
			}
			if (instructionsNum == 0) {
				managerData[changeID].dataRetention = true;
				break;
			}
		}
	}
	else {
		cout << "データがありません" << endl;
	}
}

void Manager::ViewList() {
	for (int i = 0; i < dataNum; i++) {
		//データなしは省く
		if (managerData[i].dataRetention) {
			cout << "【ID】" << managerData[i].id << "\t【クラス】" << managerData[i].classNumber <<
				"\t【名前】" << managerData[i].name << endl;
		}
	}
}

DataManager Manager::AccessData(int num) {
	while (true) {
		if (managerData[num].dataRetention) {
			break;
		}
		else {
			cout << "データがありません" << endl;
			cin >> num;
		}
	}
	return managerData[num];
}