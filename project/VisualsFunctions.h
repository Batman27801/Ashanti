#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include"List.h"
#include<vector>
using namespace std;
void center_newline()
{
	cout << "\n\n\n\n\t\t\t\t\t\t";
}
void center_continue()
{
	cout << "\n\t\t\t\t\t\t";
}
void clear_screen()
{
	system("CLS");
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
	cout << "ASHANTI PROJECT";
	cout << "\t\t\t\t\t";
	cout << "BY: (FAWAD JAVED) (ZAID SHAHAB) (ARUN JAI)";
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
	//clear_screen();
	center_newline();
	center_continue();
	cout << "\tWELCOME TO ASHANTI PROJECT";
	center_continue();
	center_continue();
	center_continue();
	cout << "\tDEVELOPERS: ";
	center_continue();
	cout << "\t\t  FAWAD JAVED FATEH";
	center_continue();
	cout << "\t\t  ZAID BIN SHAHAB";
	center_continue();
	cout << "\t\t  ARUN JAI";
	center_continue();
	center_continue();
	system("pause");
}
void end_page()
{
	system("CLS");
	center_newline();
	center_continue();
	center_continue();
	center_continue();
	cout << "THANK YOU SO MUCH FOR VISITING";
	center_continue();
	system("pause");
}
void project_Runner()
{
	Table TableAccessor;
	Table* TableHead = NULL;
	TableAccessor.InitializeTotWords(6000);
	TableAccessor.InitializeTable(&TableHead);
	TableAccessor.BuildTable(&TableHead, "Doc1.txt", 1);
	TableAccessor.BuildTable(&TableHead, "Doc2.txt", 2);
	TableAccessor.BuildTable(&TableHead, "Doc3.txt", 3);
	TableAccessor.BuildTable(&TableHead, "Doc4.txt", 4);
	TableAccessor.BuildTable(&TableHead, "Doc5.txt", 5);
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
		cout << "1. Go To String Search";
		center_continue();
		cout << "2. Exit Project";
		center_continue();
		cout << "Your Choice: ";
		cin >> choice;
		if (choice == 1)
		{
			clear_screen();
			center_newline();
			cout << "ENTER THE STRING YOU WANT TO SEARCH: ";
			fflush(stdin);
			cin >> Sentence;
			TableAccessor.Search(Sentence, &TableHead);
			center_continue();
			system("pause");
		}
		else if (choice == 2)
		{
			end_page();
			break;
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

