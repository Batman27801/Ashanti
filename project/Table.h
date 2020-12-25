#include<iostream>
#include"List.h"
#include<vector>
#include<fstream>
#include<string.h>
#include<string>
#include <Windows.h>
#pragma once
using namespace std;
class Table {
public:
	string item ;
	//int index;
	Postings* PostHead ;
	Postings Accessor;
	int TotWords;
	//Table* next;
public:
	Table();
	Table(const Table& obj);
	void BuildTable(Table** head,string doc,int DocId);
	bool StopWordCheck(string word,int lower,int upper);
	void InsertAtBegining(Table** head);
	void InitializeTable(Table **head);
	void InitializeTotWords(int Words);
	int hash(string key);
	void InsertWord(int DocID,string key,Table **head);
	void Search(string key,Table **Head);
	~Table();

};