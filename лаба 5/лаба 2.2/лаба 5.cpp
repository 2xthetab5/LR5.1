#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <conio.h>
#include "melee.h"
#include "weapon.h"
#include "kind.h"
#include "form.h"
#include "transformer.h"
#include "windows.h"
using namespace std;

//ПЕРЕГРУЗКА +//
class overload_plus {
private:
	int min, sec;
public:
	void Init(int m, int s);
	overload_plus operator+ (overload_plus b);
};

void overload_plus::Init(int m, int s) {
	min = m;
	sec = s;
}

overload_plus overload_plus::operator+(overload_plus b) {
	overload_plus c;
	c.min = this->min + b.min;
	c.sec = this->sec + b.sec;
	if (c.sec >= 60) {
		c.min++;
		c.sec -= 60;
	}
	return c;
}
////////////
///ПЕРЕГРУЗКА ++/////
class overload_plusplus {
private:
	int min, sec;
public:
	void Init(int m, int s);
	overload_plusplus& operator ++();
	overload_plusplus operator ++(int unused);
};

void overload_plusplus::Init(int m, int s) {
	min = m;
	sec = s;
}

overload_plusplus& overload_plusplus::operator ++() { //ПРЕФИКС
	this->min++;
	return *this;
}

overload_plusplus overload_plusplus::operator++(int unused) { //ПОСТФИКС
	overload_plusplus c = *this;
	++* this;
	return c;
}


int main() {
	setlocale(LC_ALL, "RUS");
	int summa1, summa2;
	int i = 0;
	string strinput;
	int intinput;
	int count_1, count_2, count_3;
	count_1 = 0;
	count_2 = 0;
	count_3 = 0;
	intinput = 0;
	//ПЕРЕГРУЗКА++//
	overload_plusplus a, b;
	a.Init(2, 35);
	b = ++a;       //a: min=3 sec=35  b: min=3 sec=35
	printf("Pref=%d\n", b);
	a.Init(2, 35);
	b = a++;       //a: min=3 sec=35 b: min=2 sec=35
	printf("Postf=%d", b);
	////////////////
	//ПЕРЕГРУЗКА +//
	overload_plus ap, bp, cp, dp;
	ap.Init(2, 25);
	bp.Init(2, 45);
	cp.Init(3, 5);
	dp = ap + bp + cp;  //  d: min = 8 sec = 15
	printf("\nD=%d\n", dp);


	auto *your_transformer = new transformer[20];
	auto *your_transformer_2 = new transformer[20][20];
	kind your_kind = kind();
	melee your_melee = melee();
	weapon your_weapon = weapon();
	form your_form = form();
	your_transformer[i] = transformer(your_kind, your_melee, your_weapon, your_form);

	while (intinput != 5) {
		cout << " Введите: 1 - для создания вашего трансформера " << endl;
		cout << " 2 - для вывода всех ваших трансформеров " << endl;
		cout << " 3 -  для создания двумерного массива из трансформера " << endl;
		cout << " 4 - для вывода двумерного массива из трансформера " << endl;
		cout << " 5 - выхода" << endl;
		/////TRY БЛОК/////
		cin >> strinput;
		try {
			intinput = stoi(strinput);
			if (intinput > 5 || intinput < 1)
				throw ("invalid range");
		}
		catch (invalid_argument e) {
			cout << ("Нужно вводить цифру");
		}
		catch (char const* s) {
			cout << ("Диапазон 1-5\n");
		}
		switch (intinput) {
		case 1:
		{
			your_transformer[i].input();
			your_transformer[i].output();
			your_transformer[i].weapon_details_counter(*your_transformer);
			your_transformer[i].color(*your_transformer);
			your_transformer[i].speed_type(*your_transformer);
			//Дружественная функция
			components(*your_transformer);
			i++;
			count_1++;
			break;
		}
		case 2: {
			for (int j = 0; j < count_1; j++) {
				your_transformer[j].output();
				your_transformer[j].weapon_details_counter(*your_transformer);
				your_transformer[j].color(*your_transformer);
				your_transformer[j].speed_type(*your_transformer);
				components(*your_transformer);
				puts("");
			}
			break;
		}
		case 3: {
			//ДВУМЕРНЫЙ МАССИВ ОБЪЕКТОВ//
			for (int k = 0; k < 1; k++) {
				count_2++;
				for (int j = 0; j < 1; j++) {
					kind your_kind = kind();
					melee your_melee = melee();
					weapon your_weapon = weapon();
					form your_form = form();

					your_transformer_2[i][j] = transformer(your_kind, your_melee, your_weapon, your_form);
					your_transformer_2[i][j].input();
					your_transformer_2[i][j].output();
					your_transformer_2[i][j].weapon_details_counter(*your_transformer);
					your_transformer_2[i][j].color(*your_transformer);
					your_transformer_2[i][j].speed_type(*your_transformer);
					count_3++;
				}
			}
			break;
		}
		case 4: {
			//ДВУМЕРНЫЙ МАССИВ ОБЪЕКТОВ - ВЫВОД//
			for (int k = 0; k < count_2; k++) {
				for (int j = 0; j < count_3; j++) {
					your_transformer_2[i][j].output();
					your_transformer_2[i][j].weapon_details_counter(*your_transformer);
					your_transformer_2[i][j].color(*your_transformer);
					your_transformer_2[i][j].speed_type(*your_transformer);
					puts("");
				}
			}
			break;
		}
			  fflush(stdin);
			  for (int i = 0; i < 1; i++) {
				  delete your_transformer;
			  }
			  delete[] your_transformer;

		}
	}
}