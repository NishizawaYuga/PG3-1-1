#include "task.h"

void Task::CreateTask(Manager managerData) {
	//データを入れる番号検索
	int newNum = 0;
	for (int i = 0; i < dataNum; i++)
	{
		if (!taskData[i].dataRetention) {
			newNum = i;
			break;
		}
		else if (taskData[999].dataRetention)
		{
			//全てのデータが埋まっていたら1000を返す
			newNum = 1000;
		}
	}

	//データに空きがある場合のみ
	if (newNum < 1000)
	{
		cout << "タスクの新規作成を行います" << endl;

		//題名作成
		cout << "タスクの題名を入力してください" << endl;
		cin >> taskData[newNum].name;

		//内容作成
		cout << "タスクの内容を入力してください" << endl;
		cin >> taskData[newNum].content;

		//担当者
		while (true) {
			cout << "タスクの担当者を入力してください" << endl;
			cout << "担当者IDで名前データを入力することもできます" << endl;
			cout << "0 : 手動で入力" << endl;
			cout << "1 : 担当者IDで入力" << endl;
			cin >> instructionsNum;

			if (instructionsNum == 0) {
				cout << "担当者名を入力してください" << endl;
				cin >> taskData[newNum].managerName;
				break;
			}
			else if (instructionsNum == 1) {
				cout << "担当者IDを入力してください" << endl;
				int managerID = 0;
				cin >> managerID;

				cout << "担当者を" << managerData.AccessData(managerID).name << "にします" << endl;

				taskData[newNum].managerName = managerData.AccessData(managerID).name;
				break;
			}
			else {
				cout << "0か1で入力してください" << endl;
			}
		}

		//優先度
		while (true) {
			cout << "優先度を設定してください" << endl;
			cout << "0 : 普通 ||  1 : 早めに ||  2 : 優先 ||  3 : 今すぐ" << endl;
			cin >> taskData[newNum].priority;
			if (taskData[newNum].priority > 3 || taskData[newNum].priority < 0) {
				cout << "優先度は0〜3の値で決めてください" << endl;
			}
			else { break; }
		}

		//期限
		InputDate(newNum);

		while (true) {
			cout << "タスクの状態を設定します" << endl;
			cout << "0 : 未完了  || 1 : 完了" << endl;
			cin >> taskData[newNum].state;
			if (taskData[newNum].state == 0 || taskData[newNum].state == 1)
			{
				break;
			}
			else {
				cout << "0か1で入力してください" << endl;
			}
		}

		//idは連番
		taskData[newNum].id = newNum;

		cout << "入力データの確認を行います" << endl;
		cout << "【ID】" << endl;
		cout << taskData[newNum].id << "\n" << endl;
		cout << "【題名】" << endl;
		cout << taskData[newNum].name << "\n" << endl;
		cout << "【内容】" << endl;
		cout << taskData[newNum].content << "\n" << endl;
		cout << "【担当者】" << endl;
		cout << taskData[newNum].managerName << "\n" << endl;
		cout << "【優先度】" << endl;
		cout << ViewPriority(taskData[newNum].priority) << "\n" << endl;
		cout << "【期限】" << endl;
		cout << taskData[newNum].deadlineYear << "/" <<
			taskData[newNum].deadlineMonth << "/" <<
			taskData[newNum].deadlineDay << "\n" << endl;
		cout << "【ステータス】" << endl;
		cout << ViewState(taskData[newNum].state) << "\n" << endl;
		//データの有無フラグオン
		taskData[newNum].dataRetention = true;

		while (true) {
			cout << "問題なければ0を、修正したい場所がある場合は" << endl;
			cout << "1を入力してください" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "このデータで保存します" << endl;
				cout << "修正したい箇所がありましたら「タスクデータ変更」から" << endl;
				cout << "お願いします" << endl;
				break;
			}
			else if (instructionsNum == 1) {
				ChangeTask(newNum, managerData);
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

void Task::DeleteTask() {
	//削除するID番号
	int deleteNum = 0;
	cout << "削除したいID番号を入力してください(001などは1と入力)" << endl;
	cout << "キャンセルしたい場合は「1000」と入力してください" << endl;
	cin >> deleteNum;

	if (deleteNum < 1000 && deleteNum > -1) {
		//データ有無のチェック
		if (!taskData[deleteNum].dataRetention) {
			cout << "このIDにはデータがありません" << endl;
		}
		else {
			while (true) {
				cout << "このID番号のタスクデータを削除しますか？" << endl;
				cout << "0 : はい" << endl;
				cout << "1 : いいえ" << endl;
				cin >> instructionsNum;
				if (instructionsNum == 0) {
					taskData[deleteNum].name = "";
					taskData[deleteNum].content = "";
					taskData[deleteNum].priority = 0;
					taskData[deleteNum].deadlineYear = 0;
					taskData[deleteNum].deadlineMonth = 0;
					taskData[deleteNum].deadlineDay = 0;
					taskData[deleteNum].state = 0;
					taskData[deleteNum].dataRetention = false;
					cout << "タスクデータを削除しました" << endl;
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

void Task::BrowseTask() {
	//閲覧するID番号
	int num = 0;
	cout << "閲覧したいID番号を入力してください(001などは1と入力)" << endl;
	cout << "キャンセルしたい場合は「1000」と入力してください" << endl;
	cin >> num;

	if (num < 1000 && num > -1) {
		if (taskData[num].dataRetention) {
			cout << "【ID】" << endl;
			cout << taskData[num].id << "\n" << endl;
			cout << "【題名】" << endl;
			cout << taskData[num].name << "\n" << endl;
			cout << "【内容】" << endl;
			cout << taskData[num].content << "\n" << endl;
			cout << "【担当者】" << endl;
			cout << taskData[num].managerName << "\n" << endl;
			cout << "【優先度】" << endl;
			cout << ViewPriority(taskData[num].priority) << "\n" << endl;
			cout << "【期限】" << endl;
			cout << taskData[num].deadlineYear << "/" <<
				taskData[num].deadlineMonth << "/" <<
				taskData[num].deadlineDay << "\n" << endl;
			cout << "【ステータス】" << endl;
			cout << ViewState(taskData[num].state) << "\n" << endl;
		}
		else {
			cout << "このIDはデータがありません" << endl;
		}
	}
	else {
		cout << "指定された番号以外を入力しないでください" << endl;
	}
}

void Task::ChangeTask(int taskID, Manager managerData) {
	if (taskData[taskID].dataRetention) {
		cout << "【ID】" << endl;
		cout << taskData[taskID].id << "\n" << endl;
		cout << "【題名】" << endl;
		cout << taskData[taskID].name << "\n" << endl;
		cout << "【内容】" << endl;
		cout << taskData[taskID].content << "\n" << endl;
		cout << "【担当者】" << endl;
		cout << taskData[taskID].managerName << "\n" << endl;
		cout << "【優先度】" << endl;
		cout << ViewPriority(taskData[taskID].priority) << "\n" << endl;
		cout << "【期限】" << endl;
		cout << taskData[taskID].deadlineYear << "/" <<
			taskData[taskID].deadlineMonth << "/" <<
			taskData[taskID].deadlineDay << "\n" << endl;
		cout << "【ステータス】" << endl;
		cout << ViewState(taskData[taskID].state) << "\n" << endl;
		while (true) {
			cout << "変更したい項目を選択してください" << endl;
			cout << "0 : 題名" << endl;
			cout << "1 : 内容" << endl;
			cout << "2 : 担当者" << endl;
			cout << "3 : 優先度" << endl;
			cout << "4 : 期限" << endl;
			cout << "5 : ステータス" << endl;
			cout << "6 : キャンセル" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "タスクの題名を入力してください" << endl;
				cin >> taskData[taskID].name;
			}
			else if (instructionsNum == 1) {
				cout << "タスクの内容を入力してください" << endl;
				cin >> taskData[taskID].content;
			}
			else if (instructionsNum == 2) {
				while (true) {
					cout << "タスクの担当者を入力してください" << endl;
					cout << "担当者IDで名前データを入力することもできます" << endl;
					cout << "0 : 手動で入力" << endl;
					cout << "1 : 担当者IDで入力" << endl;
					cin >> instructionsNum;

					if (instructionsNum == 0) {
						cout << "担当者名を入力してください" << endl;
						cin >> taskData[taskID].managerName;
						break;
					}
					else if (instructionsNum == 1) {
						cout << "担当者IDを入力してください" << endl;
						int managerID = 0;
						cin >> managerID;

						cout << "担当者を" << managerData.AccessData(managerID).name << "にします" << endl;

						taskData[taskID].managerName = managerData.AccessData(managerID).name;
						break;
					}
					else {
						cout << "0か1で入力してください" << endl;
					}
				}
			}
			else if (instructionsNum == 3) {
				while (true) {
					cout << "優先度を設定してください" << endl;
					cout << "0 : 普通 ||  1 : 早めに ||  2 : 優先 ||  3 : 今すぐ" << endl;
					cin >> taskData[taskID].priority;
					if (taskData[taskID].priority > 3 || taskData[taskID].priority < 0) {
						cout << "優先度は0〜3の値で決めてください" << endl;
					}
					else { break; }
				}
			}
			else if (instructionsNum == 4) {
				InputDate(taskID);
			}
			else if (instructionsNum == 5) {
				while (true) {
					cout << "タスクの状態を設定します" << endl;
					cout << "0 : 未完了  || 1 : 完了" << endl;
					cin >> taskData[taskID].state;
					if (taskData[taskID].state == 0 || taskData[taskID].state == 1)
					{
						break;
					}
					else {
						cout << "0か1で入力してください" << endl;
					}
				}
			}
			else if (instructionsNum == 6) { break; }
			else {
				cout << "0〜6の間で入力してください" << endl;
			}
			//データの確認
			cout << "入力データの確認を行います" << endl;
			cout << "【ID】" << endl;
			cout << taskData[taskID].id << "\n" << endl;
			cout << "【題名】" << endl;
			cout << taskData[taskID].name << "\n" << endl;
			cout << "【内容】" << endl;
			cout << taskData[taskID].content << "\n" << endl;
			cout << "【担当者】" << endl;
			cout << taskData[taskID].managerName << "\n" << endl;
			cout << "【優先度】" << endl;
			cout << ViewPriority(taskData[taskID].priority) << "\n" << endl;
			cout << "【期限】" << endl;
			cout << taskData[taskID].deadlineYear << "/" <<
				taskData[taskID].deadlineMonth << "/" <<
				taskData[taskID].deadlineDay << "\n" << endl;
			cout << "【ステータス】" << endl;
			cout << ViewState(taskData[taskID].state) << "\n" << endl;

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
				taskData[taskID].dataRetention = true;
				break;
			}
		}
	}
	else {
		cout << "データがありません" << endl;
	}
}

void Task::ViewList() {
	for (int i = 0; i < dataNum; i++) {
		//データなしは省く
		if (taskData[i].dataRetention) {
			cout << "【ID】" << taskData[i].id << "\t【題名】" <<
				taskData[i].name << "\t【優先度】" <<
				ViewPriority(taskData[i].priority) << "\t【ステータス】" <<
				ViewState(taskData[i].state) << endl;
		}
	}
}

void Task::InputDate(int taskID) {
	cout << "期限を設定してください" << endl;
	cout << "年を入力（西暦）" << endl;
	cin >> taskData[taskID].deadlineYear;

	while (true) {
		cout << "月を入力（1〜12の範囲）" << endl;
		cin >> taskData[taskID].deadlineMonth;

		if (taskData[taskID].deadlineMonth < 1 || taskData[taskID].deadlineMonth > 12)
		{
			cout << "1〜12の範囲で入力してください" << endl;
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "日付を入力（1〜31の範囲）※月によって変わります" << endl;
		cin >> taskData[taskID].deadlineDay;
		//日付に応じて処理を変更
		if (taskData[taskID].deadlineDay < 1 || taskData[taskID].deadlineDay > 31) {
			cout << "1〜31の間で入力してください" << endl;
		}
		else if (taskData[taskID].deadlineDay >= 1 && taskData[taskID].deadlineDay <= 31) {
			//うるう年の処理
			if (taskData[taskID].deadlineYear % 4 > 0) {
				if (taskData[taskID].deadlineMonth == 2) {
					if (taskData[taskID].deadlineDay > 28) {
						cout << "その年は28日までです" << endl;
					}
					else {
						break;
					}
				}
			}
			if (taskData[taskID].deadlineMonth == 4 || taskData[taskID].deadlineMonth == 6 ||
				taskData[taskID].deadlineMonth == 9 || taskData[taskID].deadlineMonth == 11) {
				if (taskData[taskID].deadlineDay == 31) {
					cout << taskData[taskID].deadlineMonth << "月は30日までです" << endl;
				}
				else {
					break;
				}
			}
			if (taskData[taskID].deadlineMonth == 1 || taskData[taskID].deadlineMonth == 3 ||
				taskData[taskID].deadlineMonth == 5 || taskData[taskID].deadlineMonth == 7 || taskData[taskID].deadlineMonth == 8
				|| taskData[taskID].deadlineMonth == 10 || taskData[taskID].deadlineMonth == 12) {
				break;
			}
		}
	}

	cout << "期限を" << taskData[taskID].deadlineYear << "年" <<
		taskData[taskID].deadlineMonth << "月" <<
		taskData[taskID].deadlineDay << "日に設定しました" << endl;
}

string Task::ViewPriority(int num) {
	if (num == 0) {
		return "普通";
	}
	else if (num == 1) {
		return "早めに";
	}
	else if (num == 2) {
		return "優先";
	}
	else if (num == 3) {
		return "今すぐ";
	}
}

string Task::ViewState(int num) {
	if (num == 0) {
		return "未完了";
	}
	else if (num == 1) {
		return "完了";
	}
}