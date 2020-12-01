#include <iostream>
#pragma once
using namespace std;
class Postings
{
    int data;
    int freq;
    Postings* next;

public:
    void InsertAtBegining(Postings** head, int data);
    void InsertAtEnd(Postings** head, int data);
    void InsertAtPos(Postings** head, int data, int pos);
    void PrintPostings(Postings* head);
    void DeleteElement(Postings** head, int pos);
    
};
