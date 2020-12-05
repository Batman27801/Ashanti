#include<iostream>
#include"List.h"
#include<vector>
#include"Table.h"
#include"Postings.h"
int main()
{  
	
	Table TableAccessor;
	Table* TableHead = NULL;
	TableAccessor.InitializeTotWords(4000);
	TableAccessor.InsertAtBegining(&TableHead);
	TableAccessor.InitializeTable(&TableHead);
	TableAccessor.BuildTable(&TableHead, "doc1.txt",1);
	TableAccessor.BuildTable(&TableHead, "doc2.txt",2);
	Table* temp = TableHead;
	TableAccessor.Search( "It sat as a dog", &TableHead);
	TableAccessor.Search("Fast really sucks ass ", &TableHead);
	TableAccessor.Search("limestone", &TableHead);
	//TableAccessor.Search("Stay", &TableHead);
	//TableAccessor.Search("limestone", &TableHead);
	///TableAccessor.Search("A", &TableHead);
}