#include "form.h"
#include <iostream>
#include <string.h>
#include <iostream>
using namespace std;

form::form(string model_of_car, int speed, int horsepower) {
	this->model_of_car = model_of_car;
	this->speed = 0;
	this->horsepower = 0;
}
form::form(string model_of_car) {
	this->model_of_car = model_of_car;
}
form::form() {
	this->model_of_car = "tank";
	this->speed = 200;
	this->horsepower = 300;
}
form::~form() {

}
void form::input() {
	cout << "Введите в какой транспорт превращается ваш трансформер(sportcar, truck, tank, jeep): ";
	cin >> model_of_car;
	cout << "Введите количество лошадиных сил у транспорта, в который превращается ваш трансформер(от 100 до 1000): ";
	cin >> horsepower;
	cout << "Введите максимальную скорость транспорта(в км/ч), в который превращается ваш трансформер(от 120 до 400): ";
	cin >> speed;
}
void form::output() {
	cout << "Транспорт, в который превращается ваш трансформер: " << model_of_car << endl;
	cout << "Количество лошадиных сил транспорта, в который превращается ваш трансформер: " << horsepower << endl;;
	cout << "Максимальная скорость транспорта, в который превращается ваш трансформер: " << speed << endl;
}