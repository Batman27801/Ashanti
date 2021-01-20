#include<iostream>
#include <Windows.h>
#include"List.h"
#include<vector>
#include"Table.h"
#include"Postings.h"
#include "VisualsFunctions.h"
#include <string>
#include <string.h>

int main()
{
	
	
	VisualsFunctions Visuals;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	Visuals.project_Runner();
}