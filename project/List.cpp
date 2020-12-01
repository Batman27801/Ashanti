#include "List.h"

void List::InitializeList(List** head)
{
	
	List* temp = *head;
	for (int i = 1; i < 40000; i++)
	{
		List* NewNode = new List;
		NewNode->index = i;
		temp->next= NewNode;
		temp = NewNode;
	}
}
void List::InsertAtBeg(List** head)
{
	List* NewNode = new List;
	NewNode->index = 0;
	NewNode->next = *head;
	*head = NewNode;
	
}
void List::InsertAtkey(List** head, int pos, string key,int DocID)
{
	List* temp = *head;
	for (int i = 0; i <= pos; i++)
	{
		temp = temp->next;
	}
	if (temp->item == "NULL" && temp->item != key)
	{
		temp->item = key;
		Accessor.InsertAtBegining(&PostHead, DocID);
		return;
	}

}
void List::GetItem(List** head, int pos,string key)
{
	List* temp = *head;
	for (int i = 0; i <= pos; i++)
	{
		temp = temp->next;
	}
	cout << "The Word " << key << " is present in the documents ";
	Accessor.PrintPostings(PostHead);
}