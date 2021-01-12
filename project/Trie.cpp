#include "Trie.h"
Trie::Trie()
{
	for (int i = 0; i < 26; i++)
	{
		Alphabets[i] = NULL;
	}
}
Trie::~Trie()
{
	for (int i = 25; i >= 0; i--)
	{
		delete (Alphabets[i]);
	}
}
Trie*Trie:: BuildTrie(Trie* root)
{
	fstream obj;
	obj.open("EngDic.txt", ios::in);
	string word;
	string meaning;
	for (int i = 0; i < 107745; i++)
	{
		getline(obj, word);
		if (word == "")
		{
			goto pk;
		}
		getline(obj, meaning);
		Insert(root, word, meaning);
	pk:;
		
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
	for (int i = 0; i < 100; i++)
	{
		obj->Meaning[i] = "NULL";
	}
	obj->WordEnd = false;
	obj->MeaningIndex = 0;
	return obj;
}
void Trie::Insert(Trie* root, string key, string meaning)
{

	Trie* temp = root;
	for (int i = 0; i < key.length(); i++)
	{
		int index;
		if (i == 0)
		{
			index = key[i] - 65;
		}
		else
		{
			index = key[i] - 97;
		}

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


	temp->WordEnd = true;
	if (temp->MeaningIndex < 100)
	{
		temp->Meaning[temp->MeaningIndex] = meaning;
	}
	if (temp->MeaningIndex != 100)
	{
		temp->MeaningIndex++;
	}
}
bool Trie::Search(Trie* root, string word)
{
	Trie* temp = root;
	for (int i = 0; i < word.length(); i++)
	{
		int index;
		if (word[i] >= 65 && word[i] <= 90)
		{
			index = word[i] - 65;
		}
		else
		{
			index = word[i] - 97;
		}
		if (!temp->Alphabets[index])
		{
			return false;
		}
		temp = temp->Alphabets[index];
	}
	if (temp != NULL && temp->WordEnd == true)
	{
		for (int i = 0; i < 40; i++)
		{
			if (temp->Meaning[i] != "NULL")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << temp->Meaning[i] << endl;
			}
		}

		return true;
	}
	else
	{
		return false;
	}

}