#include <stdlib.h>
#include <list>
#include <iostream>
using namespace std;

//âwñº
struct StationName {
	char stationName[29][20] = {
		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
		"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
		"Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo",
		"Shinjuku","Yoyogi","Harajuku","Ebisu","Meguro","Gotanda",
		"Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi",
		"Yurakucho","Nishi-Nippori","Takanawa-GateWay" };

	char tokyo[6] = "Tokyo";
	char kanda[6] = "Kanda";
	char akihabara[10] = "Akihabara";
	char okachimachi[12] = "Okachimachi";
	char ueno[5] = "Ueno";
	char uguisudani[11] = "Uguisudani";
	char nipppri[8] = "Nippori";
	char tabata[7] = "Tabata";
	char komagome[9] = "Komagome";
	char sugamo[7] = "Sugamo";
	char otsuka[7] = "Otsuka";
	char ikebukuro[10] = "Ikebukuro";
	char mejiro[7] = "Mejiro";
	char takadanobaba[13] = "Takadanobaba";
	char shin_okubo[11] = "Shin-Okubo";
	char shinjuku[9] = "Shinjuku";
	char yoyogi[7] = "Yoyogi";
	char harajuku[9] = "Harajuku";
	char ebisu[6] = "Ebisu";
	char meguro[7] = "Meguro";
	char gotanda[8] = "Gotanda";
	char osaki[6] = "Osaki";
	char shinagawa[10] = "Shinagawa";
	char tamachi[8] = "Tamachi";
	char hamamatsucho[13] = "Hamamatsucho";
	char shimbashi[10] = "Shimbashi";
	char yurakucho[10] = "Yurakucho";
	char nishi_nippori[14] = "Nishi-Nippori";
	char takanawa_gateway[17] = "Takanawa-GateWay";
};

int main() {
	StationName name;

	//listÇ∆òAî‘ÇÕëäê´Ç™à´Ç¢ÅHÇ∆Ç…Ç‡Ç©Ç≠Ç…Ç‡Ç±Ç±Ç™à´Ç¢ÇÁÇµÇ¢
	list <int> stationNum{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
	23,24,25,26 };

	printf("until 1970\n");
	for (list<int>::iterator itr = stationNum.begin(); itr != stationNum.end(); itr++) {
		for (int i = 0; i < 20; i++) {
			std::cout << name.stationName[*itr][i];
			//printf("%c", name.stationName[*itr][i]);
		}
		printf("\n");
	}
	printf("\nuntil 2019\n");
	for (list<int>::iterator itr = stationNum.begin(); itr != stationNum.end(); itr++) {
		if (*itr == 7) {
			itr = stationNum.insert(itr, 27);
			for (int i = 0; i < 20; i++) {
				std::cout << name.stationName[*itr][i];
			}
			printf("\n");
			++itr;
		}
		for (int i = 0; i < 20; i++) {
			std::cout << name.stationName[*itr][i];
		}
		printf("\n");
	}
	printf("\nsince 2020\n");
	for (list<int>::iterator itr = stationNum.begin(); itr != stationNum.end(); itr++) {
		if (*itr == 23) {
			itr = stationNum.insert(itr, 28);
			for (int i = 0; i < 20; i++) {
				std::cout << name.stationName[*itr][i];
			}
			printf("\n");
			++itr;
		}
		for (int i = 0; i < 20; i++) {
			std::cout << name.stationName[*itr][i];
		}
		printf("\n");
	}


	return 0;
}

//int main() {
//	StationName stationName;
//
//	/*list <int> stationNum{ 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,
//	23,24,25,26};*/
//
//	//list<char[29], char[20]> stationName{
//	//	{"Tokyo"},{"Kanda"},{"Akihabara"},{"Okachimachi"},{"Ueno"},
//	//	{"Uguisudani"},{"Nippori"},{"Tabata"},{"Komagome"},{"Sugamo"},
//	//	{"Otsuka"},{"Ikebukuro"},{"Mejiro"},{"Takadanobaba"},{"Shin-Okubo"},
//	//	{"Shinjuku"},{"Yoyogi"},{"Harajuku"},{"Ebisu"},{"Meguro"},{"Gotanda"},
//	//	{"Osaki"},{"Shinagawa"},{"Tamachi"},{"Hamamatsucho"},{"Shimbashi"},
//	//	{"Yurakucho"},{"Nishi-Nippori"},{"Takanawa-GateWay"}
//	//};
//
//	list<char>name[20];
//
//	for (int i = 0; i < 20; i++) {
//		name[i] = { stationName.tokyo[i],stationName.kanda[i],stationName.akihabara[i],stationName.okachimachi[i],
//	stationName.ueno[i],stationName.uguisudani[i],stationName.nipppri[i],stationName.tabata[i],
//	stationName.komagome[i],stationName.sugamo[i],stationName.otsuka[i],stationName.ikebukuro[i],
//	stationName.mejiro[i],stationName.takadanobaba[i],stationName.shin_okubo[i],stationName.shinjuku[i],
//	stationName.yoyogi[i],stationName.harajuku[i],stationName.ebisu[i],stationName.meguro[i],
//	stationName.gotanda[i],stationName.osaki[i],stationName.shinagawa[i],stationName.tamachi[i],
//	stationName.hamamatsucho[i],stationName.shimbashi[i],stationName.yurakucho[i]};
//	}
//
//	
//
//	printf("until 1970\n");
//	for (int i = 0; i < 20; i++) {
//		for (list<char>::iterator itr = name[i].begin(); itr != name[i].end(); ++itr) {
//			printf("%c", &itr);
//			//std::cout << *itr << "\n";
//			//printf("\n");
//		}
//		printf("\n");
//	}
//	printf("\nuntil 2019\n");
//	for (int i = 0; i < 20; i++) {
//		for (list<char>::iterator itr = name[i].begin(); itr != name[i].end(); ++itr) {
//			if (*itr == 7) {
//				itr = name[i].insert(itr, stationName.nishi_nippori[i]);
//				printf("%c", &itr);
//				//std::cout << *itr << "\n";
//				//printf("\n");
//				++itr;
//			}
//			//printf("%c", *itr);
//			printf("%c", &itr);
//			//printf("\n");
//		}
//		printf("\n");
//	}
//	printf("\nsince 2020\n");
//	for (int i = 0; i < 20; i++) {
//		for (list<char>::iterator itr = name[i].begin(); itr != name[i].end(); ++itr) {
//			if (*itr == 23) {
//				itr = name[i].insert(itr, stationName.takanawa_gateway[i]);
//				//printf("%c", *itr);
//				printf("%c", &itr);
//				//printf("\n");
//				++itr;
//			}
//			//printf("%c", *itr);
//			printf("%c", &itr);
//			//printf("\n");
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}

//struct StationName {
//	char stationName[30][20] = {
//		"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
//		"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
//		"Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo",
//		"Shinjuku","Yoyogi","Harajuku","Ebisu","Meguro","Gotanda",
//		"Osaki","Shinagawa","Tamachi","Hamamatsucho","Shimbashi",
//		"Yurakucho","Nishi-Nippori","Takanawa-GateWay"};
//};