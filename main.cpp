#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
	// int�^�z�� a (�v�f��:10)
	//int a[10];
	// int�^�̉ϒ��z�� b (�v�f��:0)
	//vector<int> b;

	//vector

	//�v�f���̓ǂݏ���
	//float�^�̉ϒ��z�� c (�v�f��:3)
	vector<float> c = { 0.0f,1.0f,2.0f };

	//�Y��1�̗v�f��\���i1.0�j
	printf(" %f\n", c[1]);

	//�Y��1�̗l�q��-1.5����
	c[1] = -1.5f;

	//�Y��1�̗v�f��\���i-1.5�j
	printf(" %f\n", c[1]);

	//�v�f���̕ύX
	//int�^�̉ϒ��z�� d (�v�f���F0)
	vector<int> d;

	//�l�q����10�ɕύX�i�󔒕�����ŏ����������j
	d.resize(10);

	//�v�f�����擾
	int size = d.size();

	//�S�v�f��\��
	for (int i = 0; i < size; i++) {
		printf("%d\n", d[i]);
	}

	////�C�e���[�^
	//vector<int> e = { 1,2,3 };

	////int�^�̉ϒ��z��p�̃C�e���[�^
	//vector<int>::iterator it;

	////e�̐擪�v�f���w��
	//it = e.begin();

	////it���w���Ă���v�f��\��
	//cout << *it << endl;

	////���̗v�f�Ɉړ�
	//it++;

	////it���w���Ă���v�f��\��
	//cout << *it << endl;

	//system("pause");
	return 0;
}