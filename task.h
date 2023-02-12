#pragma once
#include <iostream>
#include "manager.h"
using namespace std;

//�^�X�N�f�[�^
struct TaskData {
	//�^�X�Nid
	int id;
	//�S����
	string managerName;
	//�^�X�N��
	string name;
	//���e
	string content;
	//�D��x
	int priority;
	//����
	int deadlineYear;
	int deadlineMonth;
	int deadlineDay;
	//�X�e�[�^�X
	int state;
	//�f�[�^�L��
	bool dataRetention = false;
};

//�^�X�N�N���X
class Task {
public:
	//�^�X�N�V�K�쐬
	void CreateTask(Manager managerData);
	//�^�X�N�폜
	void DeleteTask();
	//�^�X�N�{��
	void BrowseTask();
	//�^�X�N�ύX
	void ChangeTask(int taskID, Manager managerData);
	//���X�g�\��
	void ViewList();
private:
	//���t����
	void InputDate(int taskID);
	//�D��x�\��
	string ViewPriority(int num);
	//��ԕ\��
	string ViewState(int num);
private:
	//�^�X�N���X�g
	TaskData taskData[1000];
	//�f�[�^�i�[��
	const int dataNum = 1000;
	//�R�}���h�w���̂��߂̕ϐ�
	int instructionsNum = 0;
};