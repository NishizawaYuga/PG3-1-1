#include <iostream>
#include "manager.h"
#include "task.h"
using namespace std;


void main() {
	//��̃N���X�錾
	Task task;
	Manager manager;

	//���͐���p�ԍ�
	int instructionsNum = 0;

	while (true) {
		cout << "�s�����������I��ł�������" << endl;
		cout << "0 : �S���҃f�[�^�̍쐬" << endl;
		cout << "1 : �S���҃f�[�^�̕ύX" << endl;
		cout << "2 : �S���҃f�[�^�̉{��" << endl;
		cout << "3 : �S���҃f�[�^�̍폜" << endl;
		cout << "4 : �^�X�N�f�[�^�̍쐬" << endl;
		cout << "5 : �^�X�N�f�[�^�̕ύX" << endl;
		cout << "6 : �^�X�N�f�[�^�̉{��" << endl;
		cout << "7 : �^�X�N�f�[�^�̍폜" << endl;
		cout << "8 : �S���҂̃f�[�^���X�g" << endl;
		cout << "9 : �^�X�N�̃f�[�^���X�g" << endl;
		cout << "10 : �I��" << endl;

		//�ԍ����͂Ŏw��
		cin >> instructionsNum;
		if (instructionsNum == 0) {
			manager.CreateManager();
		}
		else if (instructionsNum == 1) {
			cout << "�ύX�������S����ID����͂��Ă�������" << endl;
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
			cout << "�ύX�������^�X�NID����͂��Ă�������" << endl;
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
			cout << "�w�肳�ꂽ�ԍ�����͂��Ă�������" << endl;
		}
	}
}
