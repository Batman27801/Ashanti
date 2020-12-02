#include <iostream>
#pragma once
using namespace std;
class Postings
{
    int data;
    int freq=0;
    Postings* next;

public:
    void InsertAtBegining(Postings** head, int data);
    void InsertAtEnd(Postings** head, int data);
    void InsertAtPos(Postings** head, int data, int pos);
    void PrintPostings(Postings* head);
    void DeleteElement(Postings** head, int pos);
    void IncrementFrequency(Postings **head,int DocId);
    int ReturnData();
    
};
