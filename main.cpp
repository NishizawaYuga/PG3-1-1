#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	char word[100];
	struct CELL* next;
}CELL;

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* head, int val);

//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* head);

int main() {
	char word[100];
	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr; //Visual Stdio�ł�next�ɉ��炩�̒l����������Ԃŏ����������̂ŁAnullptr��������

	while (true)
	{
		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("2.�Ō���ɗv�f�̑}��\n");
		printf("3.�Ō���̗v�f�̍폜\n\n");
		printf("-------------------------------------------\n");
		printf("�����I�����Ă�������\n");
		scanf_s("%d", &val);

		if (val == 1) {
			index(&head);
		}
		create(&head, val);
		printf("\n-------------------------------------------\n");
		printf("0.������ʂɖ߂�\n");
		scanf_s("%d", &val);
		if (val != 0) {
			break;
		}
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
	int num = 0;
	printf("\n[�v�f�ꗗ�̕\��]\n");
	printf("�v�f�ꗗ:{\n");
	while (head->next != nullptr) {
		head = head->next;
		printf(" %d: """);
		for (int i = 0; i < strlen(head->word); i++) {
			printf("%c", head->word[i]);
		}
		if (head->next != nullptr) {
			printf(",\n");
		}
		else {
			printf("\n}");
		}
		num++;
	}
	printf("\n�v�f��: %d\n",num);
}