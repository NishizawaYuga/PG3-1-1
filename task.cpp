#include "task.h"

void Task::CreateTask(Manager managerData) {
	//ƒf[ƒ^‚ğ“ü‚ê‚é”Ô†ŒŸõ
	int newNum = 0;
	for (int i = 0; i < dataNum; i++)
	{
		if (!taskData[i].dataRetention) {
			newNum = i;
			break;
		}
		else if (taskData[999].dataRetention)
		{
			//‘S‚Ä‚Ìƒf[ƒ^‚ª–„‚Ü‚Á‚Ä‚¢‚½‚ç1000‚ğ•Ô‚·
			newNum = 1000;
		}
	}

	//ƒf[ƒ^‚É‹ó‚«‚ª‚ ‚éê‡‚Ì‚İ
	if (newNum < 1000)
	{
		cout << "ƒ^ƒXƒN‚ÌV‹Kì¬‚ğs‚¢‚Ü‚·" << endl;

		//‘è–¼ì¬
		cout << "ƒ^ƒXƒN‚Ì‘è–¼‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cin >> taskData[newNum].name;

		//“à—eì¬
		cout << "ƒ^ƒXƒN‚Ì“à—e‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cin >> taskData[newNum].content;

		//’S“–Ò
		while (true) {
			cout << "ƒ^ƒXƒN‚Ì’S“–Ò‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			cout << "’S“–ÒID‚Å–¼‘Oƒf[ƒ^‚ğ“ü—Í‚·‚é‚±‚Æ‚à‚Å‚«‚Ü‚·" << endl;
			cout << "0 : è“®‚Å“ü—Í" << endl;
			cout << "1 : ’S“–ÒID‚Å“ü—Í" << endl;
			cin >> instructionsNum;

			if (instructionsNum == 0) {
				cout << "’S“–Ò–¼‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				cin >> taskData[newNum].managerName;
				break;
			}
			else if (instructionsNum == 1) {
				cout << "’S“–ÒID‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				int managerID = 0;
				cin >> managerID;

				cout << "’S“–Ò‚ğ" << managerData.AccessData(managerID).name << "‚É‚µ‚Ü‚·" << endl;

				taskData[newNum].managerName = managerData.AccessData(managerID).name;
				break;
			}
			else {
				cout << "0‚©1‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			}
		}

		//—Dæ“x
		while (true) {
			cout << "—Dæ“x‚ğİ’è‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			cout << "0 : •’Ê ||  1 : ‘‚ß‚É ||  2 : —Dæ ||  3 : ¡‚·‚®" << endl;
			cin >> taskData[newNum].priority;
			if (taskData[newNum].priority > 3 || taskData[newNum].priority < 0) {
				cout << "—Dæ“x‚Í0`3‚Ì’l‚ÅŒˆ‚ß‚Ä‚­‚¾‚³‚¢" << endl;
			}
			else { break; }
		}

		//ŠúŒÀ
		InputDate(newNum);

		while (true) {
			cout << "ƒ^ƒXƒN‚Ìó‘Ô‚ğİ’è‚µ‚Ü‚·" << endl;
			cout << "0 : –¢Š®—¹  || 1 : Š®—¹" << endl;
			cin >> taskData[newNum].state;
			if (taskData[newNum].state == 0 || taskData[newNum].state == 1)
			{
				break;
			}
			else {
				cout << "0‚©1‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			}
		}

		//id‚Í˜A”Ô
		//Œ…”‚É‰‚¶‚Äˆ—•ÏX
		if (newNum < 10) {
			taskData[newNum].id = "00" + newNum;
		}
		else if (newNum < 100) {
			taskData[newNum].id = "0" + newNum;
		}
		else {
			taskData[newNum].id = newNum;
		}

		cout << "“ü—Íƒf[ƒ^‚ÌŠm”F‚ğs‚¢‚Ü‚·" << endl;
		cout << "yIDz" << endl;
		cout << taskData[newNum].id << "\n" << endl;
		cout << "y‘è–¼z" << endl;
		cout << taskData[newNum].name << "\n" << endl;
		cout << "y“à—ez" << endl;
		cout << taskData[newNum].content << "\n" << endl;
		cout << "y’S“–Òz" << endl;
		cout << taskData[newNum].managerName << "\n" << endl;
		cout << "y—Dæ“xz" << endl;
		cout << ViewPriority(taskData[newNum].priority) << "\n" << endl;
		cout << "yŠúŒÀz" << endl;
		cout << taskData[newNum].deadlineYear << "/" <<
			taskData[newNum].deadlineMonth << "/" << 
			taskData[newNum].deadlineDay << "\n" << endl;
		cout << "yƒXƒe[ƒ^ƒXz" << endl;
		cout << ViewState(taskData[newNum].state) << "\n" << endl;

		while (true) {
			cout << "–â‘è‚È‚¯‚ê‚Î0‚ğAC³‚µ‚½‚¢êŠ‚ª‚ ‚éê‡‚Í" << endl;
			cout << "1‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "‚±‚Ìƒf[ƒ^‚Å•Û‘¶‚µ‚Ü‚·" << endl;
				cout << "C³‚µ‚½‚¢‰ÓŠ‚ª‚ ‚è‚Ü‚µ‚½‚çu’S“–Òƒf[ƒ^•ÏXv‚©‚ç" << endl;
				cout << "‚¨Šè‚¢‚µ‚Ü‚·" << endl;
				//ƒf[ƒ^‚Ì—L–³ƒtƒ‰ƒOƒIƒ“
				taskData[newNum].dataRetention = true;
				break;
			}
			else if (instructionsNum == 1) {
				ChangeTask(newNum,managerData);
			}
			else {
				cout << "0‚©1‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			}
		}
	}
	else {
	cout << "‹ó‚«ƒf[ƒ^‚ª‚ ‚è‚Ü‚¹‚ñAŠù‘¶ƒf[ƒ^‚ğíœ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	}
}

void Task::DeleteTask() {
	//íœ‚·‚éID”Ô†
	int deleteNum = 0;
	cout << "íœ‚µ‚½‚¢ID”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(001‚È‚Ç‚Í1‚Æ“ü—Í)" << endl;
	cout << "ƒLƒƒƒ“ƒZƒ‹‚µ‚½‚¢ê‡‚Íu1000v‚Æ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	cin >> deleteNum;

	if (deleteNum < 1000 && deleteNum > -1) {
		//ƒf[ƒ^—L–³‚Ìƒ`ƒFƒbƒN
		if (!taskData[deleteNum].dataRetention) {
			cout << "‚±‚ÌID‚É‚Íƒf[ƒ^‚ª‚ ‚è‚Ü‚¹‚ñ" << endl;
		}
		else {
			while (true) {
				cout << "‚±‚ÌID”Ô†‚Ìƒ^ƒXƒNƒf[ƒ^‚ğíœ‚µ‚Ü‚·‚©H" << endl;
				cout << "0 : ‚Í‚¢" << endl;
				cout << "1 : ‚¢‚¢‚¦" << endl;
				cin >> instructionsNum;
				if (instructionsNum == 0) {
					taskData[deleteNum].name = nullptr;
					taskData[deleteNum].content = nullptr;
					taskData[deleteNum].priority = 0;
					taskData[deleteNum].deadlineYear = 0;
					taskData[deleteNum].deadlineMonth = 0;
					taskData[deleteNum].deadlineDay = 0;
					taskData[deleteNum].state = 0;
					cout << "ƒ^ƒXƒNƒf[ƒ^‚ğíœ‚µ‚Ü‚µ‚½" << endl;
					break;
				}
				else if (instructionsNum == 1) { break; }
				else {
					cout << "0‚©1‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				}
			}
		}
	}
	else {
		cout << "w’è‚³‚ê‚½”Ô†ˆÈŠO‚ğ“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢" << endl;
	}
}

void Task::BrowseTask() {
	//‰{——‚·‚éID”Ô†
	int num = 0;
	cout << "‰{——‚µ‚½‚¢ID”Ô†‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(001‚È‚Ç‚Í1‚Æ“ü—Í)" << endl;
	cout << "ƒLƒƒƒ“ƒZƒ‹‚µ‚½‚¢ê‡‚Íu1000v‚Æ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	cin >> num;

	if (num < 1000 && num > -1) {
		if (taskData[num].dataRetention) {
			cout << "yIDz" << endl;
			cout << taskData[num].id << "\n" << endl;
			cout << "y‘è–¼z" << endl;
			cout << taskData[num].name << "\n" << endl;
			cout << "y“à—ez" << endl;
			cout << taskData[num].content << "\n" << endl;
			cout << "y’S“–Òz" << endl;
			cout << taskData[num].managerName << "\n" << endl;
			cout << "y—Dæ“xz" << endl;
			cout << ViewPriority(taskData[num].priority) << "\n" << endl;
			cout << "yŠúŒÀz" << endl;
			cout << taskData[num].deadlineYear << "/" <<
				taskData[num].deadlineMonth << "/" <<
				taskData[num].deadlineDay << "\n" << endl;
			cout << "yƒXƒe[ƒ^ƒXz" << endl;
			cout << ViewState(taskData[num].state) << "\n" << endl;
		}
		else {
			cout << "‚±‚ÌID‚Íƒf[ƒ^‚ª‚ ‚è‚Ü‚¹‚ñ" << endl;
		}
	}
	else {
		cout << "w’è‚³‚ê‚½”Ô†ˆÈŠO‚ğ“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢" << endl;
	}
}

void Task::ChangeTask(int taskID, Manager managerData) {
	cout << "yIDz" << endl;
	cout << taskData[taskID].id << "\n" << endl;
	cout << "y‘è–¼z" << endl;
	cout << taskData[taskID].name << "\n" << endl;
	cout << "y“à—ez" << endl;
	cout << taskData[taskID].content << "\n" << endl;
	cout << "y’S“–Òz" << endl;
	cout << taskData[taskID].managerName << "\n" << endl;
	cout << "y—Dæ“xz" << endl;
	cout << ViewPriority(taskData[taskID].priority) << "\n" << endl;
	cout << "yŠúŒÀz" << endl;
	cout << taskData[taskID].deadlineYear << "/" <<
		taskData[taskID].deadlineMonth << "/" <<
		taskData[taskID].deadlineDay << "\n" << endl;
	cout << "yƒXƒe[ƒ^ƒXz" << endl;
	cout << ViewState(taskData[taskID].state) << "\n" << endl;
	while (true) {
		cout << "•ÏX‚µ‚½‚¢€–Ú‚ğ‘I‘ğ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cout << "0 : ‘è–¼" << endl;
		cout << "1 : “à—e" << endl;
		cout << "2 : ’S“–Ò" << endl;
		cout << "3 : —Dæ“x" << endl;
		cout << "4 : ŠúŒÀ" << endl;
		cout << "5 : ƒXƒe[ƒ^ƒX" << endl;
		cout << "6 : ƒLƒƒƒ“ƒZƒ‹" << endl;
		cin >> instructionsNum;
		if (instructionsNum == 0) {
			cout << "ƒ^ƒXƒN‚Ì‘è–¼‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			cin >> taskData[taskID].name;
		}
		else if (instructionsNum == 1) {
			cout << "ƒ^ƒXƒN‚Ì“à—e‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			cin >> taskData[taskID].content;
		}
		else if (instructionsNum == 2) {
			while (true) {
				cout << "ƒ^ƒXƒN‚Ì’S“–Ò‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				cout << "’S“–ÒID‚Å–¼‘Oƒf[ƒ^‚ğ“ü—Í‚·‚é‚±‚Æ‚à‚Å‚«‚Ü‚·" << endl;
				cout << "0 : è“®‚Å“ü—Í" << endl;
				cout << "1 : ’S“–ÒID‚Å“ü—Í" << endl;
				cin >> instructionsNum;

				if (instructionsNum == 0) {
					cout << "’S“–Ò–¼‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
					cin >> taskData[taskID].managerName;
					break;
				}
				else if (instructionsNum == 1) {
					cout << "’S“–ÒID‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
					int managerID = 0;
					cin >> managerID;

					cout << "’S“–Ò‚ğ" << managerData.AccessData(managerID).name << "‚É‚µ‚Ü‚·" << endl;

					taskData[taskID].managerName = managerData.AccessData(managerID).name;
					break;
				}
				else {
					cout << "0‚©1‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				}
			}
		}
		else if (instructionsNum == 3) {
			while (true) {
				cout << "—Dæ“x‚ğİ’è‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				cout << "0 : •’Ê ||  1 : ‘‚ß‚É ||  2 : —Dæ ||  3 : ¡‚·‚®" << endl;
				cin >> taskData[taskID].priority;
				if (taskData[taskID].priority > 3 || taskData[taskID].priority < 0) {
					cout << "—Dæ“x‚Í0`3‚Ì’l‚ÅŒˆ‚ß‚Ä‚­‚¾‚³‚¢" << endl;
				}
				else { break; }
			}
		}
		else if (instructionsNum == 4) {
			InputDate(taskID);
		}
		else if (instructionsNum == 5) {
			while (true) {
				cout << "ƒ^ƒXƒN‚Ìó‘Ô‚ğİ’è‚µ‚Ü‚·" << endl;
				cout << "0 : –¢Š®—¹  || 1 : Š®—¹" << endl;
				cin >> taskData[taskID].state;
				if (taskData[taskID].state == 0 || taskData[taskID].state == 1)
				{
					break;
				}
				else {
					cout << "0‚©1‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
				}
			}
		}
		else if (instructionsNum == 6) { break; }
		else {
			cout << "0`6‚ÌŠÔ‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		}
		//ƒf[ƒ^‚ÌŠm”F
		cout << "“ü—Íƒf[ƒ^‚ÌŠm”F‚ğs‚¢‚Ü‚·" << endl;
		cout << "yIDz" << endl;
		cout << taskData[taskID].id << "\n" << endl;
		cout << "y‘è–¼z" << endl;
		cout << taskData[taskID].name << "\n" << endl;
		cout << "y“à—ez" << endl;
		cout << taskData[taskID].content << "\n" << endl;
		cout << "y’S“–Òz" << endl;
		cout << taskData[taskID].managerName << "\n" << endl;
		cout << "y—Dæ“xz" << endl;
		cout << ViewPriority(taskData[taskID].priority) << "\n" << endl;
		cout << "yŠúŒÀz" << endl;
		cout << taskData[taskID].deadlineYear << "/" <<
			taskData[taskID].deadlineMonth << "/" <<
			taskData[taskID].deadlineDay << "\n" << endl;
		cout << "yƒXƒe[ƒ^ƒXz" << endl;
		cout << ViewState(taskData[taskID].state) << "\n" << endl;

		while (true) {
			cout << "–â‘è‚È‚¯‚ê‚Î0‚ğAC³‚µ‚½‚¢êŠ‚ª‚ ‚éê‡‚Í" << endl;
			cout << "1‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "‚±‚Ìƒf[ƒ^‚Å•Û‘¶‚µ‚Ü‚·" << endl;
				cout << "C³‚µ‚½‚¢‰ÓŠ‚ª‚ ‚è‚Ü‚µ‚½‚çu’S“–Òƒf[ƒ^•ÏXv‚©‚ç" << endl;
				cout << "‚¨Šè‚¢‚µ‚Ü‚·" << endl;
				break;
			}
			else if (instructionsNum == 1) {

			}
			else {
				cout << "0‚©1‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
			}
		}
		if (instructionsNum == 0) {
			break;
		}
	}
}

void Task::InputDate(int taskID) {
	cout << "ŠúŒÀ‚ğİ’è‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	cout << "”N‚ğ“ü—Íi¼—ïj" << endl;
	cin >> taskData[taskID].deadlineYear;

	while (true) {
		cout << "Œ‚ğ“ü—Íi1`12‚Ì”ÍˆÍj" << endl;
		cin >> taskData[taskID].deadlineMonth;

		if (taskData[taskID].deadlineMonth < 1 || taskData[taskID].deadlineMonth > 12)
		{
			cout << "1`12‚Ì”ÍˆÍ‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "“ú•t‚ğ“ü—Íi1`31‚Ì”ÍˆÍj¦Œ‚É‚æ‚Á‚Ä•Ï‚í‚è‚Ü‚·" << endl;
		cin >> taskData[taskID].deadlineDay;
		//“ú•t‚É‰‚¶‚Äˆ—‚ğ•ÏX
		if (taskData[taskID].deadlineDay < 1 || taskData[taskID].deadlineDay > 31) {
			cout << "1`31‚ÌŠÔ‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		}
		else {
			//‚¤‚é‚¤”N‚Ìˆ—
			if (taskData[taskID].deadlineYear % 4 > 0) {
				if (taskData[taskID].deadlineMonth == 2) {
					if (taskData[taskID].deadlineDay > 28) {
						cout << "‚»‚Ì”N‚Í28“ú‚Ü‚Å‚Å‚·" << endl;
					}
					else {
						break;
					}
				}
			}
			else
				if (taskData[taskID].deadlineMonth == 4 || taskData[taskID].deadlineMonth == 6 ||
					taskData[taskID].deadlineMonth == 9 || taskData[taskID].deadlineMonth == 11) {
					if (taskData[taskID].deadlineDay == 31) {
						cout << taskData[taskID].deadlineMonth << "Œ‚Í30“ú‚Ü‚Å‚Å‚·" << endl;
					}
					else {
						break;
					}
				}
				else {
					break;
				}
		}
	}

	cout << "ŠúŒÀ‚ğ" << taskData[taskID].deadlineYear << "”N" <<
		taskData[taskID].deadlineMonth << "Œ" <<
		taskData[taskID].deadlineDay << "“ú‚Éİ’è‚µ‚Ü‚µ‚½" << endl;
}

string Task::ViewPriority(int num) {
	if (num == 0) {
		return "•’Ê";
	}
	else if (num == 1) {
		return "‘‚ß‚É";
	}
	else if (num == 2) {
		return "—Dæ";
	}
	else if (num == 3) {
		return "¡‚·‚®";
	}
}

string Task::ViewState(int num) {
	if (num == 0) {
		return "–¢Š®—¹";
	}
	else if (num == 1) {
		return "Š®—¹";
	}
}