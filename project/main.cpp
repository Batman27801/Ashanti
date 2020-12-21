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
	TableAccessor.Search( "into mere illusion his craving for supreme", &TableHead);
	system("PAUSE");
	system("CLS");
	TableAccessor.Search("Fast really sucks ass ", &TableHead);
	system("PAUSE");
	system("CLS");
	TableAccessor.Search("limestone", &TableHead);
	system("PAUSE");
	system("CLS");
	TableAccessor.Search("thy", &TableHead);
	system("PAUSE");
	system("CLS");
	TableAccessor.Search("block", &TableHead);
	system("PAUSE");
	system("CLS");
	TableAccessor.Search("into a tail bleached blond", &TableHead);
	//TableAccessor.Search("Stay", &TableHead);
	//TableAccessor.Search("limestone", &TableHead);
	///TableAccessor.Search("A", &TableHead);
}