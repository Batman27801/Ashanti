#include<iostream>
#include"List.h"
#include<vector>
#include"Table.h"
#include"Postings.h"
int main()
{  
	
	Table TableAccessor;
	Table* TableHead = NULL;
	TableAccessor.InitializeTotWords(6000);
	TableAccessor.InitializeTable(&TableHead);
	TableAccessor.BuildTable(&TableHead, "Doc1.txt",1);
	TableAccessor.BuildTable(&TableHead, "Doc2.txt",2);
	TableAccessor.BuildTable(&TableHead, "Doc3.txt",3);
	TableAccessor.BuildTable(&TableHead, "Doc4.txt",4);
	TableAccessor.BuildTable(&TableHead, "Doc5.txt",5);
	Table* temp = TableHead;
	TableAccessor.Search( "it sat as a dog", &TableHead);
	TableAccessor.Search("Fast really sucks ass ", &TableHead);
	TableAccessor.Search("limestone", &TableHead);
	TableAccessor.Search("thy", &TableHead);
	TableAccessor.Search("block", &TableHead);
	//TableAccessor.Search("Stay", &TableHead);
	//TableAccessor.Search("limestone", &TableHead);
	///TableAccessor.Search("A", &TableHead);
}