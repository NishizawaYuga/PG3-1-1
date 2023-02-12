#include "task.h"

void Task::CreateTask(Manager managerData) {
	//�f�[�^������ԍ�����
	int newNum = 0;
	for (int i = 0; i < dataNum; i++)
	{
		if (!taskData[i].dataRetention) {
			newNum = i;
			break;
		}
		else if (taskData[999].dataRetention)
		{
			//�S�Ẵf�[�^�����܂��Ă�����1000��Ԃ�
			newNum = 1000;
		}
	}

	//�f�[�^�ɋ󂫂�����ꍇ�̂�
	if (newNum < 1000)
	{
		cout << "�^�X�N�̐V�K�쐬���s���܂�" << endl;

		//�薼�쐬
		cout << "�^�X�N�̑薼����͂��Ă�������" << endl;
		cin >> taskData[newNum].name;

		//���e�쐬
		cout << "�^�X�N�̓��e����͂��Ă�������" << endl;
		cin >> taskData[newNum].content;

		//�S����
		while (true) {
			cout << "�^�X�N�̒S���҂���͂��Ă�������" << endl;
			cout << "�S����ID�Ŗ��O�f�[�^����͂��邱�Ƃ��ł��܂�" << endl;
			cout << "0 : �蓮�œ���" << endl;
			cout << "1 : �S����ID�œ���" << endl;
			cin >> instructionsNum;

			if (instructionsNum == 0) {
				cout << "�S���Җ�����͂��Ă�������" << endl;
				cin >> taskData[newNum].managerName;
				break;
			}
			else if (instructionsNum == 1) {
				cout << "�S����ID����͂��Ă�������" << endl;
				int managerID = 0;
				cin >> managerID;

				cout << "�S���҂�" << managerData.AccessData(managerID).name << "�ɂ��܂�" << endl;

				taskData[newNum].managerName = managerData.AccessData(managerID).name;
				break;
			}
			else {
				cout << "0��1�œ��͂��Ă�������" << endl;
			}
		}

		//�D��x
		while (true) {
			cout << "�D��x��ݒ肵�Ă�������" << endl;
			cout << "0 : ���� ||  1 : ���߂� ||  2 : �D�� ||  3 : ������" << endl;
			cin >> taskData[newNum].priority;
			if (taskData[newNum].priority > 3 || taskData[newNum].priority < 0) {
				cout << "�D��x��0�`3�̒l�Ō��߂Ă�������" << endl;
			}
			else { break; }
		}

		//����
		InputDate(newNum);

		while (true) {
			cout << "�^�X�N�̏�Ԃ�ݒ肵�܂�" << endl;
			cout << "0 : ������  || 1 : ����" << endl;
			cin >> taskData[newNum].state;
			if (taskData[newNum].state == 0 || taskData[newNum].state == 1)
			{
				break;
			}
			else {
				cout << "0��1�œ��͂��Ă�������" << endl;
			}
		}

		//id�͘A��
		//�����ɉ����ď����ύX
		if (newNum < 10) {
			taskData[newNum].id = "00" + newNum;
		}
		else if (newNum < 100) {
			taskData[newNum].id = "0" + newNum;
		}
		else {
			taskData[newNum].id = newNum;
		}

		cout << "���̓f�[�^�̊m�F���s���܂�" << endl;
		cout << "�yID�z" << endl;
		cout << taskData[newNum].id << "\n" << endl;
		cout << "�y�薼�z" << endl;
		cout << taskData[newNum].name << "\n" << endl;
		cout << "�y���e�z" << endl;
		cout << taskData[newNum].content << "\n" << endl;
		cout << "�y�S���ҁz" << endl;
		cout << taskData[newNum].managerName << "\n" << endl;
		cout << "�y�D��x�z" << endl;
		cout << ViewPriority(taskData[newNum].priority) << "\n" << endl;
		cout << "�y�����z" << endl;
		cout << taskData[newNum].deadlineYear << "/" <<
			taskData[newNum].deadlineMonth << "/" << 
			taskData[newNum].deadlineDay << "\n" << endl;
		cout << "�y�X�e�[�^�X�z" << endl;
		cout << ViewState(taskData[newNum].state) << "\n" << endl;

		while (true) {
			cout << "���Ȃ����0���A�C���������ꏊ������ꍇ��" << endl;
			cout << "1����͂��Ă�������" << endl;
			cin >> instructionsNum;
			if (instructionsNum == 0) {
				cout << "���̃f�[�^�ŕۑ����܂�" << endl;
				cout << "�C���������ӏ�������܂�����u�S���҃f�[�^�ύX�v����" << endl;
				cout << "���肢���܂�" << endl;
				//�f�[�^�̗L���t���O�I��
				taskData[newNum].dataRetention = true;
				break;
			}
			else if (instructionsNum == 1) {
				ChangeTask(newNum,managerData);
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

void Task::DeleteTask() {
	//�폜����ID�ԍ�
	int deleteNum = 0;
	cout << "�폜������ID�ԍ�����͂��Ă�������(001�Ȃǂ�1�Ɠ���)" << endl;
	cout << "�L�����Z���������ꍇ�́u1000�v�Ɠ��͂��Ă�������" << endl;
	cin >> deleteNum;

	if (deleteNum < 1000 && deleteNum > -1) {
		//�f�[�^�L���̃`�F�b�N
		if (!taskData[deleteNum].dataRetention) {
			cout << "����ID�ɂ̓f�[�^������܂���" << endl;
		}
		else {
			while (true) {
				cout << "����ID�ԍ��̃^�X�N�f�[�^���폜���܂����H" << endl;
				cout << "0 : �͂�" << endl;
				cout << "1 : ������" << endl;
				cin >> instructionsNum;
				if (instructionsNum == 0) {
					taskData[deleteNum].name = nullptr;
					taskData[deleteNum].content = nullptr;
					taskData[deleteNum].priority = 0;
					taskData[deleteNum].deadlineYear = 0;
					taskData[deleteNum].deadlineMonth = 0;
					taskData[deleteNum].deadlineDay = 0;
					taskData[deleteNum].state = 0;
					cout << "�^�X�N�f�[�^���폜���܂���" << endl;
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

void Task::BrowseTask() {
	//�{������ID�ԍ�
	int num = 0;
	cout << "�{��������ID�ԍ�����͂��Ă�������(001�Ȃǂ�1�Ɠ���)" << endl;
	cout << "�L�����Z���������ꍇ�́u1000�v�Ɠ��͂��Ă�������" << endl;
	cin >> num;

	if (num < 1000 && num > -1) {
		if (taskData[num].dataRetention) {
			cout << "�yID�z" << endl;
			cout << taskData[num].id << "\n" << endl;
			cout << "�y�薼�z" << endl;
			cout << taskData[num].name << "\n" << endl;
			cout << "�y���e�z" << endl;
			cout << taskData[num].content << "\n" << endl;
			cout << "�y�S���ҁz" << endl;
			cout << taskData[num].managerName << "\n" << endl;
			cout << "�y�D��x�z" << endl;
			cout << ViewPriority(taskData[num].priority) << "\n" << endl;
			cout << "�y�����z" << endl;
			cout << taskData[num].deadlineYear << "/" <<
				taskData[num].deadlineMonth << "/" <<
				taskData[num].deadlineDay << "\n" << endl;
			cout << "�y�X�e�[�^�X�z" << endl;
			cout << ViewState(taskData[num].state) << "\n" << endl;
		}
		else {
			cout << "����ID�̓f�[�^������܂���" << endl;
		}
	}
	else {
		cout << "�w�肳�ꂽ�ԍ��ȊO����͂��Ȃ��ł�������" << endl;
	}
}

void Task::ChangeTask(int taskID, Manager managerData) {
	cout << "�yID�z" << endl;
	cout << taskData[taskID].id << "\n" << endl;
	cout << "�y�薼�z" << endl;
	cout << taskData[taskID].name << "\n" << endl;
	cout << "�y���e�z" << endl;
	cout << taskData[taskID].content << "\n" << endl;
	cout << "�y�S���ҁz" << endl;
	cout << taskData[taskID].managerName << "\n" << endl;
	cout << "�y�D��x�z" << endl;
	cout << ViewPriority(taskData[taskID].priority) << "\n" << endl;
	cout << "�y�����z" << endl;
	cout << taskData[taskID].deadlineYear << "/" <<
		taskData[taskID].deadlineMonth << "/" <<
		taskData[taskID].deadlineDay << "\n" << endl;
	cout << "�y�X�e�[�^�X�z" << endl;
	cout << ViewState(taskData[taskID].state) << "\n" << endl;
	while (true) {
		cout << "�ύX���������ڂ�I�����Ă�������" << endl;
		cout << "0 : �薼" << endl;
		cout << "1 : ���e" << endl;
		cout << "2 : �S����" << endl;
		cout << "3 : �D��x" << endl;
		cout << "4 : ����" << endl;
		cout << "5 : �X�e�[�^�X" << endl;
		cout << "6 : �L�����Z��" << endl;
		cin >> instructionsNum;
		if (instructionsNum == 0) {
			cout << "�^�X�N�̑薼����͂��Ă�������" << endl;
			cin >> taskData[taskID].name;
		}
		else if (instructionsNum == 1) {
			cout << "�^�X�N�̓��e����͂��Ă�������" << endl;
			cin >> taskData[taskID].content;
		}
		else if (instructionsNum == 2) {
			while (true) {
				cout << "�^�X�N�̒S���҂���͂��Ă�������" << endl;
				cout << "�S����ID�Ŗ��O�f�[�^����͂��邱�Ƃ��ł��܂�" << endl;
				cout << "0 : �蓮�œ���" << endl;
				cout << "1 : �S����ID�œ���" << endl;
				cin >> instructionsNum;

				if (instructionsNum == 0) {
					cout << "�S���Җ�����͂��Ă�������" << endl;
					cin >> taskData[taskID].managerName;
					break;
				}
				else if (instructionsNum == 1) {
					cout << "�S����ID����͂��Ă�������" << endl;
					int managerID = 0;
					cin >> managerID;

					cout << "�S���҂�" << managerData.AccessData(managerID).name << "�ɂ��܂�" << endl;

					taskData[taskID].managerName = managerData.AccessData(managerID).name;
					break;
				}
				else {
					cout << "0��1�œ��͂��Ă�������" << endl;
				}
			}
		}
		else if (instructionsNum == 3) {
			while (true) {
				cout << "�D��x��ݒ肵�Ă�������" << endl;
				cout << "0 : ���� ||  1 : ���߂� ||  2 : �D�� ||  3 : ������" << endl;
				cin >> taskData[taskID].priority;
				if (taskData[taskID].priority > 3 || taskData[taskID].priority < 0) {
					cout << "�D��x��0�`3�̒l�Ō��߂Ă�������" << endl;
				}
				else { break; }
			}
		}
		else if (instructionsNum == 4) {
			InputDate(taskID);
		}
		else if (instructionsNum == 5) {
			while (true) {
				cout << "�^�X�N�̏�Ԃ�ݒ肵�܂�" << endl;
				cout << "0 : ������  || 1 : ����" << endl;
				cin >> taskData[taskID].state;
				if (taskData[taskID].state == 0 || taskData[taskID].state == 1)
				{
					break;
				}
				else {
					cout << "0��1�œ��͂��Ă�������" << endl;
				}
			}
		}
		else if (instructionsNum == 6) { break; }
		else {
			cout << "0�`6�̊Ԃœ��͂��Ă�������" << endl;
		}
		//�f�[�^�̊m�F
		cout << "���̓f�[�^�̊m�F���s���܂�" << endl;
		cout << "�yID�z" << endl;
		cout << taskData[taskID].id << "\n" << endl;
		cout << "�y�薼�z" << endl;
		cout << taskData[taskID].name << "\n" << endl;
		cout << "�y���e�z" << endl;
		cout << taskData[taskID].content << "\n" << endl;
		cout << "�y�S���ҁz" << endl;
		cout << taskData[taskID].managerName << "\n" << endl;
		cout << "�y�D��x�z" << endl;
		cout << ViewPriority(taskData[taskID].priority) << "\n" << endl;
		cout << "�y�����z" << endl;
		cout << taskData[taskID].deadlineYear << "/" <<
			taskData[taskID].deadlineMonth << "/" <<
			taskData[taskID].deadlineDay << "\n" << endl;
		cout << "�y�X�e�[�^�X�z" << endl;
		cout << ViewState(taskData[taskID].state) << "\n" << endl;

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
			break;
		}
	}
}

void Task::InputDate(int taskID) {
	cout << "������ݒ肵�Ă�������" << endl;
	cout << "�N����́i����j" << endl;
	cin >> taskData[taskID].deadlineYear;

	while (true) {
		cout << "������́i1�`12�͈̔́j" << endl;
		cin >> taskData[taskID].deadlineMonth;

		if (taskData[taskID].deadlineMonth < 1 || taskData[taskID].deadlineMonth > 12)
		{
			cout << "1�`12�͈̔͂œ��͂��Ă�������" << endl;
		}
		else {
			break;
		}
	}

	while (true) {
		cout << "���t����́i1�`31�͈̔́j�����ɂ���ĕς��܂�" << endl;
		cin >> taskData[taskID].deadlineDay;
		//���t�ɉ����ď�����ύX
		if (taskData[taskID].deadlineDay < 1 || taskData[taskID].deadlineDay > 31) {
			cout << "1�`31�̊Ԃœ��͂��Ă�������" << endl;
		}
		else {
			//���邤�N�̏���
			if (taskData[taskID].deadlineYear % 4 > 0) {
				if (taskData[taskID].deadlineMonth == 2) {
					if (taskData[taskID].deadlineDay > 28) {
						cout << "���̔N��28���܂łł�" << endl;
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
						cout << taskData[taskID].deadlineMonth << "����30���܂łł�" << endl;
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

	cout << "������" << taskData[taskID].deadlineYear << "�N" <<
		taskData[taskID].deadlineMonth << "��" <<
		taskData[taskID].deadlineDay << "���ɐݒ肵�܂���" << endl;
}

string Task::ViewPriority(int num) {
	if (num == 0) {
		return "����";
	}
	else if (num == 1) {
		return "���߂�";
	}
	else if (num == 2) {
		return "�D��";
	}
	else if (num == 3) {
		return "������";
	}
}

string Task::ViewState(int num) {
	if (num == 0) {
		return "������";
	}
	else if (num == 1) {
		return "����";
	}
}