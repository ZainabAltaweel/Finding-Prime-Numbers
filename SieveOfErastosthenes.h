// File Name: SieveOfErastosthenes.h
// Author: Zainab Alaweel
// Date: 10/ 04/ 2018
// Compiler Used: Default compiler (MSVC)
//<This file is the header, which is the class definition, the header file include functions prototype and data representation>

#pragma once
#include<iostream>;
#include<fstream>;
#include<string>;

using namespace std;

class SeiveOfErastosthenes
{
public:
	SeiveOfErastosthenes();
	SeiveOfErastosthenes(int n, int m);
	void Resize_Array();
	void Display_Primes();
	void Display_List();
	void Initialize_Array(int d);
	~SeiveOfErastosthenes();
	void Find_Primes(int n);

private:
	bool End = false;
	int N;
	int ** a;
	int ** temp;
	int rows;
	int col;
	int val = 0;
	int Num_of_Rows = 0;

};

