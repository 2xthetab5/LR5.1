#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class kind
{
    public:
		string color_of_transformer;
		string genus;
		int age_of_transformer;
		kind(string color_of_transformer, string genus, int age_of_transformer);
		kind(string color_of_transformer);
		kind();
		~kind();
		void input();
		void output();
};

