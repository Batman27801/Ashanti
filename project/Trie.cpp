#include "Trie.h"
Trie*Trie:: BuildTrie(Trie* root)
{
	root = GetNode();
	fstream obj;
	obj.open("EngDic.txt", ios::in);
	string word;
	string meaning;
	for (int i = 0; i < 9467; i++)
	{
		getline(obj, word);
		if (word == "guess")
		{
			int y = 0;
		}
		getline(obj, meaning);
		Insert(root, word, meaning);
	pk:
		int y = 0;
	}
	return root;
}
Trie* Trie::GetNode()
{
	Trie* obj = new Trie();
	for (int i = 0; i < 26; i++)
	{
		obj->Alphabets[i] = NULL;
	}
	obj->Meaning = "NULL";
	obj->WordEnd = false;
	return obj;
}
void Trie::Insert(Trie* root, string key, string meaning)
{

	Trie* temp = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 97;
		if (index < 0 || index >26)
		{
			goto en;
		}
		if (temp->Alphabets[index] == NULL)
		{
			temp->Alphabets[index] = GetNode();
		}
		temp = temp->Alphabets[index];
	en:
		index = 0;
	}
	//temp = GetNode();
	temp->WordEnd = true;
	temp->Meaning = meaning;
}
bool Trie::Search(Trie* root, string word)
{
	Trie* temp = root;
	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 97;
		if (!temp->Alphabets[index])
		{
			return false;
		}
		temp = temp->Alphabets[index];
	}
	if (temp != NULL && temp->WordEnd == true)
	{
		cout << temp->Meaning << endl;
		return true;
	}
	else
	{
		return false;
	}
}