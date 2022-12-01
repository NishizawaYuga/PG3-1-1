#include <stdio.h>
#include <stdlib.h>

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	int year;
	int month;
	int day;
	struct CELL* next;
}CELL;

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* head, int val);

//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* head);

//���͕��@�������Ă邩�`�F�b�N����֐�
void inputCheck(CELL* head, int val);

int main() {
	int val;
	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr; //Visual Stdio�ł�next�ɉ��炩�̒l����������Ԃŏ����������̂ŁAnullptr��������

	while (true)
	{
		printf("�N��������͂��Ă��������i��F20220101�j\n");
		scanf_s("%d", &val);

		inputCheck(&head, val);
	}

	system("pause");
	return 0;
}

//���͕��@�������Ă邩�`�F�b�N����֐�
void inputCheck(CELL* head, int val) {

	if (val / 10000000 < 1 || val / 10000000 > 12) {
		printf("���͏�񂪊Ԉ���Ă��܂�\n");
	}
	else {
		//�Ō���ɃZ����ǉ�
		create(head, val);

		//���X�g�ꗗ�̕\��
		index(head);
	}
}

//�Z����V�K�쐬����֐�
void create(CELL* head, int val) {
	CELL* cell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	cell = (CELL*)malloc(sizeof(CELL));

	//�N�̒��o
	int year = val / 10000;
	cell->year = year;
	//���̒��o
	int month = val % 10000;
	month = month / 100;
	cell->month = month;
	//���t�̒��o
	int day = val % 100;
	cell->day = day;
	cell->next = nullptr;

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (head->next != (CELL*)nullptr) {
		head = head->next;
	}

	head->next = cell;
}

//�Z���̈ꗗ��\������֐�
void index(CELL* head) {
	printf("\n");
	while (head->next != nullptr) {
		head = head->next;
		printf("%d/%d/%d\n", head->year, head->month, head->day);
	}
}