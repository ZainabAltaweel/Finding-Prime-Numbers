// File Name: SieveOfErastosthenes.cpp
// Author: Zainab Alaweel
// Date: 10/ 04/ 2018
// Compiler Used: Default compiler (MSVC)
//<This file is the implementation of LottoTicket class, which include functions' definition>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "SieveOfErastosthenes.h"
#include <windows.h>


using namespace std;

SeiveOfErastosthenes::SeiveOfErastosthenes()    // Default Constructer
{
}

SeiveOfErastosthenes::SeiveOfErastosthenes(int r, int c )      // Parametrized Constructor to allocate the Prime Array
{
	rows = r;
	col = c;
	a = new int*[rows];
	for (int i = 0; i < rows; i++)
		a[i] = new int[col-1];
}

void SeiveOfErastosthenes::Find_Primes(int n)      // Find prime numbers, It returns true when size exceeded
{
	N = n;
	for (int s = 0; s < N - 1; s++) // initialize the first row
	{
		a[0][s] = s + 2; 
	}
	val = a[0][0]; //initialize the fist prime number which is always 2
	Initialize_Array(1);
	while (End == false)
	{
		Resize_Array();
	}
}

void SeiveOfErastosthenes::Resize_Array()
{
	MessageBox(nullptr, TEXT("Array Resized"), TEXT("Message"), MB_OK); // send Array Resized message to the screen

	int** temp = new int*[rows];                // Allocating temprory array
	for (int i = 0; i < rows; i++)
		temp[i] = new int[col - 1];

	for (int x = 0; x < rows; x++) 
	{
		for (int y = 0; y < col; y++)
		{
			temp[x][y] = a[x][y];              // copying the content to the temprory array
		}
	}

	for (int i = 0; i < rows; i++)             // deallocating a array
		delete[] a[i];
	delete[] a;

	rows = rows + 5;

	a = new int*[rows];                       // allocating new arrar a with new size
	for (int i = 0; i < rows; i++)
		a[i] = new int[col - 1];

	for (int x = 0; x < rows - 5; x++)
	{
		for (int y = 0; y < col; y++)
		{
			a[x][y] = temp[x][y];              // copy the content of temp to a 
		}
	}


	Initialize_Array(Num_of_Rows + 1);         // complete initializing the new rows
}


void SeiveOfErastosthenes::Display_Primes()
{
	cout << "Prime numbers up to " << N << " :";                // dispaly prime numbers only
	for (int d = 0; d < N - 1; d++)
	{
		if (a[Num_of_Rows][d] != 0)
			cout << a[Num_of_Rows][d] << "  ";
		else
			continue;
	}
	cout << "\n";
}

void SeiveOfErastosthenes::Display_List()
{
	for (int j = 0; j < Num_of_Rows +1 ; j++)                   // Display the entire content
	{
		for (int i = 0; i < N - 1; i++)
			cout << a[j][i] << "  ";
		cout << "\n";
	}
}

void SeiveOfErastosthenes::Initialize_Array(int f)
{
	for (int m = f; m < rows; m++)
	{
		for (int d = 0; d < N - 1; d++)
		{
			if ((a[m - 1][d] != val) && (a[m - 1][d] % val == 0)) // initializing the other rows in the list
				a[m][d] = 0;                                      // crossing numbers
			else
				a[m][d] = a[m - 1][d];
		}
		for (int d = 0; d < N - 1; d++)
		{
			if (a[m][d] * a[m][d] <= N)
			{
				if ((a[m][d] > val))
				{
					val = a[m][d];
					break;
				}
				else
					continue;
			}
			else if (a[m][d] * a[m][d] > N)
			{
				End = true;
				break;
			}
		}

		Num_of_Rows = m;



		if (End == true)
			break;
	}
}
	SeiveOfErastosthenes::~SeiveOfErastosthenes()    // Destructer
	{

		for (int i = 0; i < rows; i++)
			delete[] a[i];
		delete[] a;

		for (int i = 0; i < rows; i++)
			delete[] temp[i];
		delete[] temp;
	}



