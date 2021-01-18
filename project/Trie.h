#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include <string.h>
using namespace std;
class Trie {
	Trie* Alphabets[26];
	bool WordEnd;
	string Meaning[100];
	int MeaningIndex = 0;
public:
	Trie();
	Trie* BuildTrie(Trie* root);
	Trie* GetNode();
	void Insert(Trie* root, string key, string meaning);
	bool Search(Trie* root, string word);
	~Trie();
};


