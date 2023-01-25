#include <stdlib.h>
#include <list>
using namespace std;

//‰w–¼
struct StationName {
	char stationName[29][20] = {
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
		"Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo",
		"Shinjuku","Yoyogi","Harajuku","Ebisu","Meguro","Gotanda",
		"Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi",
		"Yurakucho","Nishi-Nippori","Takanawa-GateWay"};
};

int main() {
	StationName name;

	list <int> stationNum{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
	23,24,25,26};

	printf("until 1970\n");
	for (list<int>::iterator itr = stationNum.begin(); itr != stationNum.end(); itr++) {
		for (int i = 0; i < 20; i++) {
			printf("%c", name.stationName[*itr][i]);
		}
		printf("\n");
	}
	printf("\nuntil 2019\n");
	for (list<int>::iterator itr = stationNum.begin(); itr != stationNum.end(); itr++) {
		if (*itr == 7) {
			itr = stationNum.insert(itr, 27);
			for (int i = 0; i < 20; i++) {
				printf("%c", name.stationName[*itr][i]);
			}
			printf("\n");
			++itr;
		}
		for (int i = 0; i < 20; i++) {
			printf("%c", name.stationName[*itr][i]);
		}
		printf("\n");
	}
	printf("\nsince 2020\n");
	for (list<int>::iterator itr = stationNum.begin(); itr != stationNum.end(); itr++) {
		if (*itr == 23) {
			itr = stationNum.insert(itr, 28);
			for (int i = 0; i < 20; i++) {
				printf("%c", name.stationName[*itr][i]);
			}
			printf("\n");
			++itr;
		}
		for (int i = 0; i < 20; i++) {
			printf("%c", name.stationName[*itr][i]);
		}
		printf("\n");
	}


	return 0;
}