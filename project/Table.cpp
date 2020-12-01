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
		NewNode->PostHead = NULL;
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
		temp->Accessor.InsertAtBegining(&temp->PostHead, DocId);
		return;
	}
	if (temp->item != "NULL" && temp->item == key)
	{
		temp->item = key;
		temp->Accessor.InsertAtBegining(&temp->PostHead, DocId);
		return;
	}
	if (temp->item != "NULL")
	{
		while (temp->item != "NULL")
		{
			temp = temp->next;
		}
		temp->item = key;
		temp->Accessor.InsertAtBegining(&temp->PostHead, DocId);
		//Accessor.InsertAtBegining(&PostHead, DocId);
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
	int FoundFlag = 1;
	if (temp->item != key)
	{
		while (temp->item != key)
		{
			if (pos >= TotWords)
			{
				FoundFlag = 0;
				break;
			}
			temp = temp->next;
			pos++;
		}

		if (FoundFlag == 0)
		{
			cout << "The Given word"<< key <<" doesnt occur in the documents" << endl;
		}
		else
		{
			cout << "The Word Present at index "<< pos <<" " << key << " is present in the documents  ";
			//Accessor.PrintPostings(PostHead);
			temp->Accessor.PrintPostings(temp->PostHead);
			cout << endl;
		}
	}
	else
	{
		cout << "The Word Present at index " << pos << " " << key << " is present in the documents  ";
		temp->Accessor.PrintPostings(temp->PostHead);
		cout << endl;
	}

}