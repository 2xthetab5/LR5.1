#include "transformer.h"
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

//Дружественная функция
void components(transformer &x){
	cout << "Состовляющих трансформера: " << x.comps << endl;
}
transformer::transformer(kind your_kind, melee your_melee, weapon your_weapon, form your_form) {
	this->your_melee = your_melee;
	this->your_weapon = your_weapon;
	this->your_kind = your_kind;
	this->your_form = your_form;
}
transformer::transformer(melee your_melee) {
	this->your_melee = your_melee;
}
transformer::transformer() {

}
transformer::~transformer() {

}
void transformer::input() {
	your_kind.input();
	your_melee.input();
	your_weapon.input();
	your_form.input();
}
void transformer::output() {
	your_kind.output();
	your_melee.output();
	your_weapon.output();
	your_form.output();
}
void transformer::color(transformer your_transformer) {
	if (your_transformer.your_melee.color_of_melee.compare(your_transformer.your_weapon.color_of_weapon) == your_transformer.your_melee.color_of_melee.compare(your_transformer.your_kind.color_of_transformer))
		cout << "Ваш трансформер одноцветный" << endl;
	else
		cout << "Ваш трансформер разноцветный" << endl;
}
void transformer::speed_type(transformer your_transformer) {
	if ((your_transformer.your_form.speed >= 120) && (your_transformer.your_form.speed < 200))
		cout << "У вашего трансформера маленькая скорость" << endl;
	if ((your_transformer.your_form.speed >= 200) && (your_transformer.your_form.speed < 300))
		cout << "У вашего трансформера средняя скорость" << endl;
	if ((your_transformer.your_form.speed >= 300) && (your_transformer.your_form.speed <= 400))
		cout << "У вашего трансформера большая скорость" << endl;
}
void transformer::weapon_details_counter(transformer your_transformer) {
	if ((your_transformer.your_melee.melee_counter != 0) && (your_transformer.your_weapon.weapon_counter != 0))
		cout << "У вашего трансформера присутствуют оба типа оружия" << endl;
}
//Демонстрация возврата значения из метода через указатель (*) и через ссылку (&)
void transformer::summa(transformer your_transformer, int *summa1) {
	*summa1 = your_transformer.your_melee.cost_melee + your_transformer.your_weapon.cost_weapon;
}
void transformer::summa(transformer your_transformer, int &summa2) {
	summa2 = your_transformer.your_melee.cost_melee + your_transformer.your_weapon.cost_weapon;
}