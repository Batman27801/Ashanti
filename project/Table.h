#include<iostream>
#include"List.h"
#include<vector>
#pragma once
using namespace std;
class Table {
	Postings* PostHead = NULL;
	Postings Accessor;
	int index;
	string item = "NULL";
	int TotWords;
	Table* next;
public:
	Table();
	void BuildTable(Table** head);
	void InsertAtBegining(Table** head);
	void InitializeTable(Table **head);
	void InitializeTotWords(int Words);
	int hash(string key);
	void InsertWord(int DocID,string key,Table **head);
	void Search(string key,Table **Head);

};