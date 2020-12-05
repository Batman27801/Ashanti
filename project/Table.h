#include<iostream>
#include"List.h"
#include<vector>
#include<fstream>
#include<string.h>
#include<string>
#pragma once
using namespace std;
class Table {
public:
	string item = "NULL";
	int index;
	Postings* PostHead ;
	Postings Accessor;
	
	int TotWords;
	Table* next;
	string StopWords[430];
public:
	Table();
	void BuildTable(Table** head,string doc,int DocId);
	bool StopWordCheck(string word,int lower,int upper);
	void InsertAtBegining(Table** head);
	void InitializeTable(Table **head);
	void InitializeTotWords(int Words);
	int hash(string key);
	void InsertWord(int DocID,string key,Table **head);
	void Search(string key,Table **Head);

};