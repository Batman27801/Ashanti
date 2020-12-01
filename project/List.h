#pragma once
#include"Postings.h"
#include<iostream>
using namespace std;

class List
{
	Postings *PostHead = NULL;
	Postings Accessor;
	int index;
	string item="NULL";
	List* next;
public:
	void InsertAtkey(List** head,int pos,string key,int DocID);
	void InitializeList(List **head);
	void InsertAtBeg(List** head);
	void GetItem(List** head,int pos,string key);
};

