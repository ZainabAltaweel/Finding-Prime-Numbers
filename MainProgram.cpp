// File Name: MainProgram.cpp
// Author: Zainab Alaweel
// Date: 10/ 04/ 2018
// Compiler Used: Default compiler (MSVC)
// MainProgram.cpp : This file contains the 'main' function. Program execution begins and ends there. A number is read randomly from 
// a test file and the mode of displaying is also read from the same file. Then the prime numbers are found using class functions

#include <iostream>
#include <fstream>
#include<iostream>
#include"SieveOfErastosthenes.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	fstream fin;
	fin.open("InputFile.txt");

	if (!fin.is_open())      // if it is failed to open the file
	{
		cout << "Sorry, the file could not be opened";
		cout << "program Terminating.\n ";
		exit(EXIT_FAILURE);
	}

	int Num;
	string mode;
	srand(time(NULL));
	int ran = (rand() % 5) + 1;
	cout << ran;
	for (int y = 0; y < ran + 1 ; y++)
	{
		fin >> Num;
		fin >> mode;
	}
	string S1 = "hello";
	cout << S1;
	cout << S1.length;

	cout << "Num = " << Num << endl; 
	cout << " Mode is: " << mode << endl;
	fin.close();


	SeiveOfErastosthenes Allocation(5, Num);

	 Allocation.Find_Primes(Num);


	if (mode == "EntireContents")
	{
		Allocation.Display_List();
		Allocation.Display_Primes();
	}

	if (mode == "NumberList")
	{
		Allocation.Display_Primes();
	}


	cin.get();
	return 0;
}