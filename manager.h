#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

//�S���҃f�[�^
struct DataManager {
	//�S����ID
	string id;
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
	//�S���҃f�[�^�A�N�Z�X
	DataManager AccessData(int num);
private:
	//�f�[�^�ύX
	void ChangeManagerData(int changeID);
private:
	//�S���Ҋi�[
	DataManager managerData[1000];
	//�R�}���h�w���̂��߂̕ϐ�
	int instructionsNum = 0;
	//�f�[�^�i�[��
	const int dataNum = 1000;
	//�N���X�F�؁i��v������̂̂ݒʂ��悤�ɂ��邽�߁j
	const char classNum[4] = { 1,2,3,4 };
	const char classChar[5] = "ABCD";
};
