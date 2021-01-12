#include <iostream>
#include <string>
#include <string.h>
#include <Windows.h>
#pragma once
using namespace std;
class Postings
{
    int data;
    int freq=0;
    Postings* next;

public:
    Postings();
    void InsertAtBegining(Postings** head, int data);
    void InsertAtEnd(Postings** head, int data);
    void InsertAtPos(Postings** head, int data, int pos);
    void PrintPostings(Postings* head);
    void DeleteElement(Postings** head, int pos);
    void IncrementFrequency(Postings **head,int DocId);
    int ReturnData();
    ~Postings();
    
};
