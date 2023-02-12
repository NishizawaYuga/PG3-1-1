#include "manager.h"

void Manager::CreateManager()
{
	//�f�[�^������ԍ�����
	int newNum = 0;
	for (int i = 0; i < dataNum; i++) {
		if (!managerData[i].dataRetention) {
			newNum = i;
			break;
		}
		else if (managerData[999].dataRetention)
		{
			//�S�Ẵf�[�^�����܂��Ă�����1000��Ԃ�
			newNum = 1000;
		}
	}

	//�f�[�^�ɋ󂫂�����ꍇ�̂�
	if (newNum < 1000) {
		//�N���X������
		cout << "�S���҂̐V�K�쐬���s���܂�" << endl;
		cout << "���Ȃ��̃N���X����͂��Ă�������" << endl;
		cin >> managerData[newNum].classNumber;

		//�S���Җ�����
		cout << "�S���҂̖��O����͂��Ă�������" << endl;
		cin >> managerData[newNum].name;
		cout << "" << endl;

		//id�͘A��
		managerData[newNum].id = newNum;

		//�f�[�^�̊m�F
		cout << "���̓f�[�^�̊m�F���s���܂�" << endl;
		cout << "�yID�z" << endl;
		cout << managerData[newNum].id << "\n" << endl;
		cout << "�y�N���X�z" << endl;
		cout << managerData[newNum].classNumber << "\n" << endl;
		cout << "�y���O�z" << endl;
		cout << managerData[newNum].name << "\n" << endl;
		//�f�[�^�̗L���t���O�I��
		managerData[newNum].dataRetention = true;

		while (true) {
			cout << "���Ȃ����0���A�C���������ꏊ������ꍇ��" << endl;
			cout << "1����͂��Ă�������" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "���̃f�[�^�ŕۑ����܂�" << endl;
				cout << "�C���������ӏ�������܂�����u�S���҃f�[�^�ύX�v����" << endl;
				cout << "���肢���܂�" << endl;
				break;
			}
			else if (instructionsNum == 1) {
				ChangeManagerData(newNum);
				break;
			}
			else {
				cout << "0��1�œ��͂��Ă�������" << endl;
			}
		}
	}
	else {
		cout << "�󂫃f�[�^������܂���A�����f�[�^���폜���Ă�������" << endl;
	}
}

void Manager::DeleteManager()
{
	//�폜����ID�ԍ�
	int deleteNum = 0;
	cout << "�폜������ID�ԍ�����͂��Ă�������(001�Ȃǂ�1�Ɠ���)" << endl;
	cout << "�L�����Z���������ꍇ�́u1000�v�Ɠ��͂��Ă�������" << endl;
	cin >> deleteNum;

	if (deleteNum < 1000 && deleteNum > -1) {
		//�f�[�^�L���̃`�F�b�N
		if (!managerData[deleteNum].dataRetention)
		{
			cout << "����ID�ɂ̓f�[�^������܂���" << endl;
		}
		else {
			while (true) {
				cout << "����ID�ԍ��̒S���҃f�[�^���폜���܂����H" << endl;
				cout << "0 : �͂�" << endl;
				cout << "1 : ������" << endl;
				cin >> instructionsNum;
				if (instructionsNum == 0) {
					for (int i = 0; i < 4; i++) {
						managerData[deleteNum].classNumber[i] = '0';
					}
					managerData[deleteNum].name = "";
					managerData[deleteNum].dataRetention = false;
					cout << "�S���҃f�[�^���폜���܂���" << endl;
					break;
				}
				else if (instructionsNum == 1) { break; }
				else {
					cout << "0��1�œ��͂��Ă�������" << endl;
				}
			}
		}
	}
	else {
		cout << "�w�肳�ꂽ�ԍ��ȊO����͂��Ȃ��ł�������" << endl;
	}
}

void Manager::BrowseData()
{
	//�{������ID�ԍ�
	int num = 0;
	cout << "�{��������ID�ԍ�����͂��Ă�������(001�Ȃǂ�1�Ɠ���)" << endl;
	cout << "�L�����Z���������ꍇ�́u1000�v�Ɠ��͂��Ă�������" << endl;
	cin >> num;

	if (num < 1000 && num > -1) {
		if (managerData[num].dataRetention) {
			cout << "�yID�z" << endl;
			cout << managerData[num].id << "\n" << endl;
			cout << "�y�N���X�z" << endl;
			cout << managerData[num].classNumber << "\n" << endl;
			cout << "�y���O�z" << endl;
			cout << managerData[num].name << "\n" << endl;
		}
		else {
			cout << "����ID�̓f�[�^������܂���" << endl;
		}
	}
	else {
		cout << "�w�肳�ꂽ�ԍ��ȊO����͂��Ȃ��ł�������" << endl;
	}
}

void Manager::ChangeManagerData(int changeID)
{
	if (managerData[changeID].dataRetention) {
		cout << "�yID�z" << endl;
		cout << managerData[changeID].id << "\n" << endl;
		cout << "�y�N���X�z" << "" << endl;
		cout << managerData[changeID].classNumber << "\n" << endl;
		cout << "�y���O�z" << "" << endl;
		cout << managerData[changeID].name << "\n" << endl;
		while (true) {
			cout << "�ύX�������ӏ���ԍ��œ��͂��Ă�������" << endl;
			cout << "0 : �N���X" << endl;
			cout << "1 : �S���Җ�" << endl;
			cout << "2 : �L�����Z��" << endl;

			cin >> instructionsNum;
			if (instructionsNum == 0) {
				//�N���X������
				cout << "�S���҂̐V�K�쐬���s���܂�" << endl;
				cout << "���Ȃ��̃N���X����͂��Ă�������" << endl;
				cin >> managerData[changeID].classNumber;
			}
			else if (instructionsNum == 1) {
				//�S���Җ�����
				cout << "�S���҂̖��O����͂��Ă�������" << endl;
				cin >> managerData[changeID].name;
				cout << "" << endl;
			}
			else if (instructionsNum == 2) {
				break;
			}
			else {
				cout << "0�`2�œ��͂��Ă�������" << endl;
			}
			//�f�[�^�̊m�F
			cout << "���̓f�[�^�̊m�F���s���܂�" << endl;
			cout << "�yID�z" << endl;
			cout << managerData[changeID].id << "\n" << endl;
			cout << "�y�N���X�z" << "" << endl;
			cout << managerData[changeID].classNumber << "\n" << endl;
			cout << "�y���O�z" << "" << endl;
			cout << managerData[changeID].name << "\n" << endl;

			while (true) {
				cout << "���Ȃ����0���A�C���������ꏊ������ꍇ��" << endl;
				cout << "1����͂��Ă�������" << endl;
				cin >> instructionsNum;
				if (instructionsNum == 0) {
					cout << "���̃f�[�^�ŕۑ����܂�" << endl;
					cout << "�C���������ӏ�������܂�����u�S���҃f�[�^�ύX�v����" << endl;
					cout << "���肢���܂�" << endl;
					break;
				}
				else if (instructionsNum == 1) {

				}
				else {
					cout << "0��1�œ��͂��Ă�������" << endl;
				}
			}
			if (instructionsNum == 0) {
				managerData[changeID].dataRetention = true;
				break;
			}
		}
	}
	else {
		cout << "�f�[�^������܂���" << endl;
	}
}

void Manager::ViewList() {
	for (int i = 0; i < dataNum; i++) {
		//�f�[�^�Ȃ��͏Ȃ�
		if (managerData[i].dataRetention) {
			cout << "�yID�z" << managerData[i].id << "\t�y�N���X�z" << managerData[i].classNumber <<
				"\t�y���O�z" << managerData[i].name << endl;
		}
	}
}

DataManager Manager::AccessData(int num) {
	while (true) {
		if (managerData[num].dataRetention) {
			break;
		}
		else {
			cout << "�f�[�^������܂���" << endl;
			cin >> num;
		}
	}
	return managerData[num];
}