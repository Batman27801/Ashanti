#include "Postings.h"
int Postings::ReturnData()
{
    return data;
}

void Postings::IncrementFrequency(Postings **head,int DocId)
{
    Postings* temp = *head;
    if (temp->data != DocId)
    {
        while (temp->data != DocId)
        {
            if (temp == NULL)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp != NULL)
        {
            temp->freq++;
            return;
        }
    }
    (*(head))->freq++;
    return;
    

    
}
void Postings::InsertAtBegining(Postings** head, int data)
{
    Postings* temp = new Postings;
    temp->data = data;
    temp->next = *head;
    *head = temp;
    return;
}
void Postings::InsertAtEnd(Postings** head, int data)
{
    Postings* temp1 = new Postings;
    temp1->data = data;
    temp1->next = NULL;
    Postings* temp2 = *head;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    return;
}
void Postings:: InsertAtPos(Postings** head, int data, int pos)
{
    Postings* temp1 = new Postings;
    temp1->data = data;
    temp1->next = NULL;
    if (pos == 1)
    {
        temp1->next = *head;
        *head = temp1;
        return;
    }
    Postings* temp2 = *head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp2 = temp2->next;
    }
    if (temp2->next == NULL)
    {
        temp2->next = temp1;
        return;
    }
    else
    {
        Postings* temp3 = temp2->next;
        temp2->next = temp1;
        temp1->next = temp3;
        return;
    }
}
void Postings::PrintPostings(Postings* head)
{
    while (head != NULL)
    {
        cout << " "<<head->data << " Frequency = "<<head->freq;
        head = head->next;
    }
    return;
}
void Postings::DeleteElement(Postings** head, int pos)
{
    Postings* temp1 = *head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    Postings* temp2;
    temp2 = temp1->next;
    if (temp2->next == NULL)
    {
        temp1->next = NULL;
        return;
    }
    temp1->next = temp2->next;
    return;
}