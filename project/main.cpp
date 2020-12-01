#include<iostream>
#include"List.h"
#include<vector>
#include"Table.h"
#include"Postings.h"
int main()
{
	Table TableAccessor;
	Table* TableHead = NULL;
	TableAccessor.InitializeTotWords(40000);
	TableAccessor.InsertAtBegining(&TableHead);
	TableAccessor.InitializeTable(&TableHead);
	TableAccessor.InsertWord(1, "Ist", &TableHead);
	TableAccessor.InsertWord(2, "tsI", &TableHead);
	TableAccessor.Search("Ist", &TableHead);
	TableAccessor.Search("tsI", &TableHead);
	//TableAccessor.Search("A", &TableHead);

}