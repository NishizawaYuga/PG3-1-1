#pragma once
#include <iostream>
using namespace std;

//�S���҃f�[�^
struct DataManager {
	//�S����ID
	int id;
	//�S���Җ�
	string name;
	//�N���X
	char classNumber[4];
	//�f�[�^�����邩�ǂ����̃t���O
	bool dataRetention = false;
};

//�S���҃N���X
class Manager {
public:
	//�S���҃f�[�^�쐬
	void CreateManager();
	//�S���҃f�[�^�폜
	void DeleteManager();
	//�S���҃f�[�^�{��
	void BrowseData();
	//�f�[�^�ύX
	void ChangeManagerData(int changeID);
	//���X�g�\��
	void ViewList();
	//�S���҃f�[�^�A�N�Z�X
	DataManager AccessData(int num);
private:
	//�S���Ҋi�[
	DataManager managerData[1000];
	//�R�}���h�w���̂��߂̕ϐ�
	int instructionsNum = 0;
	//�f�[�^�i�[��
	const int dataNum = 1000;
};
