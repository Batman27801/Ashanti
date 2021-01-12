#include<iostream>
#include<fstream>
#include<cctype>
#pragma once
using namespace std;

class CleanQ
{
	string docs[6] = { "Doc1.txt", "Doc2.txt", "Doc3.txt", "Doc4.txt", "Doc5.txt", "Doc6.txt" };
	int front, rear, capacity, newlines, wordcount, charactercount;
	char* queue;
public:
	CleanQ();
	char& enqueue();
	char dequeue();
	char Qrecent();

	char Qfront();
	void replacedash();
	void filecleaner(string filename);
	~CleanQ();
};

