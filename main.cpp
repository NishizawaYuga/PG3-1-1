#include <stdio.h>
#include <stdlib.h>

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	int val;
	struct CELL* next;
}CELL;

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* head, int val);

//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* head);

int main() {
	int val;
	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr; //Visual Stdio�ł�next�ɉ��炩�̒l����������Ԃŏ����������̂ŁAnullptr��������

	while (true)
	{
		printf("�D���Ȑ�������͂��Ă�������\n");
		scanf_s("%d", &val);

		create(&head, val);

		index(&head);
	}

	system("pause");
	return 0;
}

//�Z����V�K�쐬����֐�
void create(CELL* head, int val) {
	CELL* cell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	cell = (CELL*)malloc(sizeof(CELL));

	cell->val = val;
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
	printf("[");
	while (head->next != nullptr) {
		head = head->next;
		printf("%d", head->val);
		if (head->next != nullptr) {
			printf(",");
		}
	}
	printf("]/\n");
}