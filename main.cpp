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
	int val = 20221031;
	//�擪�̃Z���̐錾
	CELL head;
	head.next = nullptr; //Visual Stdio�ł�next�ɉ��炩�̒l����������Ԃŏ����������̂ŁAnullptr��������

	while (true)
	{
		scanf_s("% d", &val);

		//�Ō���ɃZ����ǉ�
		create(&head, 20221103);

		//���X�g�ꗗ�̕\��
		index(&head);
	}

	return 0;
}

//�Z����V�K�쐬����֐�
void create(CELL* head, int val) {
	CELL *cell;
	//�V�K�쐬����Z�����̃��������m�ۂ���
	cell = (CELL*)malloc(sizeof(CELL));

	cell->val = val;
	cell->next = nullptr;

	//�Ō�(�ŐV)�̃Z���̃A�h���X��1�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (&head->next != nullptr) {
		*head->next = *head->next->next;
	}

	*head->next = *cell;
}

//�Z���̈ꗗ��\������֐�
void index(CELL* head) {
	while (head->next != nullptr) {
		head->next = head->next->next;
		printf("%d\n", head->next->val);
	}
}