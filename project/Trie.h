#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Trie {
	Trie* Alphabets[26];
	bool WordEnd;
	string Meaning[100];
	int MeaningIndex = 0;
public:
	Trie* BuildTrie(Trie* root);
	Trie* GetNode();
	void Insert(Trie* root, string key, string meaning);
	bool Search(Trie* root, string word);
};
//int main()
//{
//	string s = "istinja";
//	int n = s.find('z');
//	Trie Accessor;
//	Trie* root = Accessor.GetNode();
//	root = Accessor.BuildTrie(root);
//	Accessor.Search(root, "jargon");
//
//}

/*root->Insert(root,"rock", "perfect tool for istinja");
root->Insert(root, "fast", "a place which you learn to hate as the years progress");
root->Insert(root, "sex", "goof");
root->Search(root, "rock");
root->Search(root, "sex");
root->Search(root, "fast");
root->Search(root, "nauman");
}*/

