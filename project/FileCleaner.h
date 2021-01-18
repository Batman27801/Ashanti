#include<iostream>
#include<fstream>
#include<cctype>
#pragma once
using namespace std;

class CleanQ
{
	string docs[6];
	int front, rear, capacity, newlines, wordcount, charactercount;
	char* queue;
public:
	CleanQ();
	char& enqueue();
	char dequeue();
	char Qrecent();
	char Qfront();
	void setDocs(string* names);
	void replacedash();
	void filecleaner(string filename);
	~CleanQ();
};

