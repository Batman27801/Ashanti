#include "Postings.h"
Postings::Postings()
{
    this->next = NULL;
}
int Postings::ReturnData()
{
    return data;
}
Postings::~Postings()
{
    this->next = NULL;
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
    char ch = 219;
    int count = 0, * Doc_IDs, * frequencies, max_freq;
    Postings* temp1 = head;
    while (head != NULL)
    {
        cout << " Doc Id: " << head->data << " Freq: " << head->freq;
        head = head->next;
        count++;
    }
    if (count == 0) return;
    Doc_IDs = new int[count];
    frequencies = new int[count];
    for (int i = 0; i < count; i++, temp1 = temp1->next)
    {
        Doc_IDs[i] = temp1->data;
        frequencies[i] = temp1->freq;
    }
    max_freq = frequencies[0];
    for (int i = 0; i < count; i++)
    {
        if (frequencies[i] > max_freq) max_freq = frequencies[i];
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "\n\n\n\n\t\t\t\t\t\t";
    cout << "Frequency Graph: ";
    cout << "\n\t\t\t\t\t\t";
    cout << "\n\t\t\t\t\t\t";
    cout << "\n\t\t\t\t\t\t";

    for (int i = max_freq; i >= 1; i--)
    {
        cout << "\t      ";
        for (int j = 0; j < count; j++)
        {
            if (frequencies[j] >= i) cout << ch << ' ';
            else cout << "  ";
        }
        cout << "\n\t\t\t\t\t\t";

    }
    cout << "\tDoc   ";
    for (int i = 0; i < count; i++)
    {
        cout << Doc_IDs[i] << ' ';
    }
    cout << "\n\t\t\t\t\t\t";

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