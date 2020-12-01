#include "Table.h"
Table::Table()
{
}
void Table::InsertAtBegining(Table **head)
{
	Table* temp = *head;
	Table* NewNode = new Table;
	NewNode->index = 0;
	NewNode->next = *head;
	*head = NewNode;
}
void Table::InitializeTable(Table **head)
{
	Table* temp = *head;
	for (int i = 1; i < 40000; i++)
	{
		Table* NewNode = new Table;
		NewNode->index = i;
		temp->next = NewNode;
		temp = NewNode;
	}
}
void Table::InitializeTotWords(int Words)
{
	this->TotWords = Words;
}
int Table::hash(string key)
{
	int var = 0;
	for (int i = 0; i < key.length(); i++)
	{
		var += key[i];

	}
	int pos = var % TotWords;
	return pos;
}
void Table::InsertWord(int DocId, string key, Table** head)
{
	int pos = hash(key);
	Table* temp = *head;
	for (int i = 0; i <= pos; i++)
	{
		temp = temp->next;
	}
	if (temp->item == "NULL" && temp->item != key)
	{
		temp->item = key;
		Accessor.InsertAtBegining(&PostHead, DocId);
		return;
	}
	if (temp->item != "NULL" && temp->item == key)
	{
		temp->item = key;
		Accessor.InsertAtBegining(&PostHead, DocId);
		return;
	}
}
void Table::Search(string key,Table **head)
{
	int pos = hash(key);
	Table* temp = *head;
	for (int i = 0; i <= pos; i++)
	{
		temp = temp->next;
	}
	cout << "The Word " << key << " is present in the documents  ";
	Accessor.PrintPostings(PostHead);

}