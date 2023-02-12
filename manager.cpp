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
		//でたらめに入力するとループする
		while (true) {
			//ループ脱出フラグ
			bool breakLoop = false;

			cout << "担当者の新規作成を行います" << endl;
			cout << "あなたのクラスを入力してください" << endl;
			cout << "クラス番号下二桁は" << endl;
			cout << "1～4の番号、A～Dのアルファベットで指定" << endl;
			cin >> managerData[newNum].classNumber;
			//クラス番号チェック
			for (int i = 0; i < 4; i++) {
				if (managerData[newNum].classNumber[2] == classNum[i])
				{
					for (int j = 0; j < 4; j++) {
						if (managerData[newNum].classNumber[3] == classChar[j])
						{
							//1～4、A～Dでそれぞれ一致すればループ脱出フラグをオンにする
							breakLoop = true;
						}
					}
				}
			}
			//ループフラグがオンなら脱出
			if (breakLoop)
			{
				break;
			}
			//ここで脱出できてないとクラス入力が間違えてることになる
			cout << "クラス入力で間違っているところがあります" << endl;
			cout << "正しいクラスを入力してください" << endl;
		}

		//担当者名入力
		cout << "担当者の名前を入力してください" << endl;
		cin >> managerData[newNum].name;
		cout << "" << endl;

		//idは連番
		//桁数に応じて処理変更
		if (newNum < 10) {
			managerData[newNum].id = "00" + newNum;
		}
		else if (newNum < 100) {
			managerData[newNum].id = "0" + newNum;
		}
		else {
			managerData[newNum].id = newNum;
		}

		//データの確認
		cout << "入力データの確認を行います" << endl;
		cout << "【ID】" << endl;
		cout << managerData[newNum].id << "\n" << endl;
		cout << "【クラス】" << endl;
		cout << managerData[newNum].classNumber << "\n" << endl;
		cout << "【名前】" << endl;
		cout << managerData[newNum].name << "\n" << endl;

		while (true) {
			cout << "問題なければ0を、修正したい場所がある場合は" << endl;
			cout << "1を入力してください" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "このデータで保存します" << endl;
				cout << "修正したい箇所がありましたら「担当者データ変更」から" << endl;
				cout << "お願いします" << endl;
				//データの有無フラグオン
				managerData[newNum].dataRetention = true;
				break;
			}
			else if (instructionsNum == 1) {
				ChangeManagerData(newNum);
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
					managerData[deleteNum].name = nullptr;
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
	else{
		cout << "指定された番号以外を入力しないでください" << endl;
	}
}

void Manager::ChangeManagerData(int changeID)
{
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
			//でたらめに入力するとループする
			while (true) {
				//ループ脱出フラグ
				bool breakLoop = false;

				cout << "あなたのクラスを入力してください" << endl;
				cout << "クラス番号下二桁は" << endl;
				cout << "1～4の番号、A～Dのアルファベットで指定" << endl;
				cin >> managerData[changeID].classNumber;
				//クラス番号チェック
				for (int i = 0; i < 4; i++) {
					if (managerData[changeID].classNumber[2] == classNum[i])
					{
						for (int j = 0; j < 4; j++) {
							if (managerData[changeID].classNumber[3] == classChar[j])
							{
								//1～4、A～Dでそれぞれ一致すればループ脱出フラグをオンにする
								breakLoop = true;
							}
						}
					}
				}
				//ループフラグがオンなら脱出
				if (breakLoop)
				{
					break;
				}
				//ここで脱出できてないとクラス入力が間違えてることになる
				cout << "クラス入力で間違っているところがあります" << endl;
				cout << "正しいクラスを入力してください" << endl;
			}
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
			break;
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