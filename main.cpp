#include <stdlib.h>
#include <list>
#include <iostream>
using namespace std;

typedef struct cell 
{
	char name[20];
	struct cell* prev;
	struct cell* next;
}CELL;

//‰w–¼
struct StationName {
	char stationName[29][20] = {
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
		"Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo",
		"Shinjuku","Yoyogi","Harajuku","Ebisu","Meguro","Gotanda",
		"Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi",
		"Yurakucho","Nishi-Nippori","Takanawa-GateWay" };
};

void create(CELL* currenCell, char* name);
void index(CELL* endCell,int num);
CELL* getInsertCellAddress(CELL* endCELL, int iterator);

int main() {
	StationName name;
	CELL head;
	head.next = nullptr;
	head.prev = nullptr;

	CELL* insertCell;

	for (int i = 0; i < 26; i++) {
		insertCell = getInsertCellAddress(&head, i);
		create(insertCell, name.stationName[i]);
	}

	list<int> num{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };

	printf("until 1970\n");
	for (list<int>::iterator itr = num.begin(); itr != num.end(); itr++) {
			insertCell = getInsertCellAddress(&head, *itr);
			create(insertCell, name.stationName[*itr]);
	}
	index(&head,26);
	printf("\nuntil 2019\n");
	for (list<int>::iterator itr = num.begin(); itr != num.end(); itr++) {
		if (*itr == 7) {
			insertCell = getInsertCellAddress(&head, *itr);
			create(insertCell, name.stationName[27]);
			++itr;
		}
	}
	index(&head, 27);
	printf("\nsince 2020\n");
	for (list<int>::iterator itr = num.begin(); itr != num.end(); itr++) {
		if (*itr == 23) {
			insertCell = getInsertCellAddress(&head, *itr);
			create(insertCell, name.stationName[28]);
			++itr;
		}
	}
	index(&head, 28);


	return 0;
}

CELL* getInsertCellAddress(CELL* endCELL, int iterator) {
	for (int i = 0; i < iterator; i++) {
		if (endCELL->next) {
			endCELL = endCELL->next;
		}
		else {
			break;
		}
	}
	return endCELL;
}

void create(CELL* currenCell, char *name) {
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	for (int i = 0; i < 20; i++) {
		newCell->name[i] = name[i];
	}
	newCell->prev = currenCell;
	newCell->next = currenCell->next;

	if (currenCell->next) {
		CELL* nextCell = currenCell->next;
		nextCell->prev = newCell;
	}

	currenCell->next = newCell;
}

void index(CELL* endCell,int num) {
	int no = 1;
	for (int i = 0; i <= num;i++) {
		endCell = endCell->next;
		for (int j = 0; j < 20; j++) {
			printf("%c",endCell->name[j]);
		}
		printf("\n");
		no++;
	}
}