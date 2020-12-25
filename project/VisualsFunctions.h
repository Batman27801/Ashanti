#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include"List.h"
#include<vector>
#include <fstream>
#include"Headers.h"
using namespace std;
void center_newline()
{
	cout << "\n\n\n\t\t\t\t\t\t";
}
void center_continue()
{
	cout << "\n\t\t\t\t\t\t";
}
void clear_screen()
{
	char ch;
	system("CLS");
	ifstream is;
	is.open("AshantiHeader.txt");
	while (is.get(ch))
	{
		cout << ch;
	}
}
void normal_spacing()
{
	cout << "\n\n\n\n\t\t";
}
void normally_continue()
{
	cout << "\n\t\t";
}
void home_page()
{
	char ch;
	ifstream is;
	is.open("AshantiHome.txt");
	while (is.get(ch))
	{
		cout << ch;
	}
	cout << endl;
	system("pause");
}
void end_page()
{
	char ch;
	system("CLS");
	ifstream is("ProjectEnd.txt");
	while (is.get(ch))
	{
		cout << ch;
	}
	cout << endl;
	system("pause");
}
void project_Runner()
{
	Table TableAccessor;
	Table* TableHead = NULL;
	TableAccessor.InitializeTotWords(15000);
	TableAccessor.InitializeTable(&TableHead);
	TableAccessor.BuildTable(&TableHead, "Doc1.txt", 1);
	TableAccessor.BuildTable(&TableHead, "Doc2.txt", 2);
	TableAccessor.BuildTable(&TableHead, "Doc3.txt", 3);
	TableAccessor.BuildTable(&TableHead, "Doc4.txt", 4);
	TableAccessor.BuildTable(&TableHead, "Doc5.txt", 5);
	TableAccessor.BuildTable(&TableHead, "Doc6.txt", 6);
	Table* temp = TableHead;

	int choice;
	char sent[200];
	string Sentence;
	home_page();
	while (true)
	{
		clear_screen();
		center_newline();
		center_continue();
		cout << "1. Go To Term Search";
		center_continue();
		cout << "2. Go To File Cleaner";
		center_continue();
		cout << "3. Exit Project";
		center_continue();
		cout << "Your Choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1)
		{
			clear_screen();
			center_newline();
			cout << "ENTER THE TERM YOU WANT TO SEARCH: ";
			fflush(stdin);
			getline(cin,Sentence);
			TableAccessor.Search(Sentence, &TableHead);
			center_continue();
			system("pause");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		}
		else if (choice == 3)
		{
			end_page();
			break;
		}
		else if (choice == 2)
		{
			string filename;
			clear_screen();
			center_newline();
			cout << "Enter name of the file with its extension(only .txt suported)";
			getline(cin, filename);
			CleanQ obj;
			obj.filecleaner(filename);
			center_continue();
			system("pause");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		}
		else
		{
			center_continue();
			cout << "YOU ENTERED WRONG INPUT!";
			center_continue();
			system("pause");
			continue;
		}
	}

}

