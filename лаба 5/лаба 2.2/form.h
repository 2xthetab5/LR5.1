#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class form
{
	public:
		string model_of_car;
		int speed;
		int horsepower;
		form(string model_of_car, int speed, int horsepower);
		form(string model_of_car);
		form();
		~form();
		void input();
		void output();
};

