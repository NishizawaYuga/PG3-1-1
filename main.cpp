#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�P�������X�g�̍\���̂̒�`
typedef struct CELL {
	char word[100];
	struct CELL* next;
}CELL;

//�f�[�^��ǉ�����֐��̃v���g�^�C�v�錾
void create(CELL* head, char* word);

//�ꗗ��\������֐��̃v���g�^�C�v�錾
void index(CELL* head);

//�f�[�^���폜����֐��̃v���g�^�C�v�錾
void clear(CELL* head);

int main() {
	char word[100];
	int val;
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
		if (val == 2) {
			printf("\n�ǉ�����v�f�̒l����͂��Ă�������\n");
			scanf_s("%s", word);
			create(&head, word);
			printf("\n\n�v�f""");
			for (int i = 0; i < strlen(word); i++) {
				printf("%c", word[i]);
			}
			printf("""�����X�g�̍Ō���ɑ}������܂���\n");
		}
		/*if (val == 3) {
			clear(&head);
		}*/
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
void create(CELL* head, char* word) {
	CELL* cell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	cell = (CELL*)malloc(sizeof(CELL));

	for (int i = 0; i < strlen(word); i++) {
		cell->word[i] = word[i];
	}
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
		printf(" %d: \"", num);
		for (int i = 0; i < strlen(head->word); i++) {
			printf("%c", head->word[i]);
		}
		printf("\"");
		if (head->next != nullptr) {
			printf(",\n");
		}
		else {
			printf("\n}");
		}
		num++;
	}
	printf("\n�v�f��: %d\n", num);
}

//�Z�����폜����֐�
void clear(CELL* head) {
	CELL* prev;
	prev = head;
}