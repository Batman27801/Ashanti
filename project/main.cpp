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
	TableAccessor.BuildTable(&TableHead, "doc1.txt");
	Table* temp = TableHead;
	while (temp != NULL)
	{
		temp = temp->next;
	}
	TableAccessor.Search( "Thank", &TableHead );
	TableAccessor.Search("istinja", &TableHead);
	TableAccessor.Search("Pence", &TableHead);
	//TableAccessor.Search("A", &TableHead);
}