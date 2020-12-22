#include "Table.h"
#include"Trie.h"
#include <string>
#include <string.h>
using namespace std;
string StopWords[430];
Trie* root;
Table::Table()
{
	this->item = "NULL";
	this->PostHead = NULL;
}
Table::Table(const Table& obj)
{
	this->Accessor = obj.Accessor;
	this->item = obj.item;
	this->PostHead = obj.PostHead;
	this->TotWords = obj.TotWords;
}
string RemoveSpecialCharacter(string word)
{
	for (int i = 0; i < word.size(); i++) {

		if (word[i] < 'A' || word[i] > 'Z' && word[i] < 'a' || word[i] > 'z')
		{ 
			word.erase(i, 1);
			i--;
		}
	}
	return word;
}
void Table::BuildTable(Table** head, string file,int docId)
{
	static int i = 0;
	if (i == 0)
	{
		Trie Accessor;
		root = Accessor.GetNode();
		root=Accessor.BuildTrie(root);
		i++;
	}
	string temp;
	fstream fobj;
	fobj.open(file, ios::in);
	while (!fobj.eof())
	{
		fobj >> temp;
		temp = RemoveSpecialCharacter(temp);
		if (StopWordCheck(temp, 0, 430) == 0)
		{
			InsertWord(docId, temp, &(*head));
		}
	}
}
void Table::InsertAtBegining(Table **head)
{
	Table* temp = *head;
	Table* NewNode = new Table;
	*head = NewNode;
}
void Table::InitializeTable(Table **head)
{
	*head = new Table[60000];
	Table* temp = *head;
	/*for (int i = 0; i < 4000; i++)
	{
		(temp + i)->item = "NULL";
	}*/
	fstream file;
	file.open("StopWords.txt",ios::in);
	for (int i = 0; i < 430; i++)
	{
		string temp;
		file >> temp;
		StopWords[i] = temp;
	}
}
bool Table::StopWordCheck(string word,int lower,int upper)
{
	static int FoundFlag = 0;
	if (upper >= lower)
	{
		int mid = (lower + upper) / 2;
		string temp = StopWords[mid];
		if (word == StopWords[mid])
		{
			FoundFlag = 1;
			return true;
		}
		else if ( StopWords[mid]>word)
		{
			return StopWordCheck(word, lower, mid-1);
		}
		else 
		{
			return StopWordCheck(word, mid+1, upper);
		}
	}
	return false;
}
void Table::InitializeTotWords(int Words)
{
	this->TotWords = Words;
}
int Table::hash(string key)
{
	int var = 0;
	for (int i = 0; i < key.length(); i++)
	{
		int temp;
		if (key[i] > 64 && key[i] < 90)
		{
			temp = key[i] - 65;
		}
		else {
			temp = key[i] - 97;
		}	
		var += temp;
	}
	
	int pos = var % TotWords;
	return pos;
}

void Table::InsertWord(int DocId, string key, Table** head)
{
	
	static int bitch = 0;
	int pos = hash(key);
	Table* temp = *head;
	if ((temp + pos)->item != "NULL")
	{
		while ((temp + pos)->item != "NULL" )
		{
			if ((temp + pos)->item == key)
			{
				break;
			}
			pos++;
		}
	}
	if ((temp + pos)->item == "NULL" && (temp + pos)->item != key)
	{
		(temp + pos)->item = key;
		(temp + pos)->Accessor.InsertAtBegining(&(temp + pos)->PostHead, DocId);
		(temp + pos)->Accessor.IncrementFrequency(&(temp + pos)->PostHead, DocId);
		return;
	}
	if ((temp + pos)->item != "NULL" && (temp + pos)->item == key && (temp + pos)->PostHead->ReturnData() != DocId)
	{
		(temp + pos)->item = key;
		(temp + pos)->Accessor.InsertAtBegining(&(temp + pos)->PostHead, DocId);
		(temp + pos)->Accessor.IncrementFrequency(&(temp + pos)->PostHead, DocId);
		return;
	}
	if ((temp + pos)->item != "NULL" && (temp + pos)->item == key && (temp + pos)->PostHead->ReturnData() == DocId)
	{
		(temp + pos)->item = key;
		(temp + pos)->Accessor.IncrementFrequency(&(temp + pos)->PostHead, DocId);
		return;
	}

	
}
void Table::Search(string key,Table **head)
{
	Trie Accessor;
	
	int TotWords = 0;
	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] == ' ')
		{
			TotWords++;
		}
	}
	TotWords++;
	string* WordArr = new string[TotWords];
	int j = 0;
	WordArr[j] = key.substr(0, key.find(" "));
	j++;
	for (int i = 0; i < key.length(); i++)
	{
		if (key[i] == ' ')
		{
			
			i++;
			int k = i;
			while (key[k] != ' ')
			{
				k++;
				if (k > key.length())
				{
					k = key.length();
					break;
				}
			}
			WordArr[j] = key.substr(i, k-i);
			j++;
		}
	}
	int FoundFlag;
	int place;
	int pos;
	Table* temp;

	for (int i = 0; i < TotWords; i++)
	{
		if (StopWordCheck(WordArr[i], 0, 430) == 1)
		{
			goto end;
		}
		 pos = hash(WordArr[i]);
		 temp = *head;
		 FoundFlag = 1;
		if ((temp + pos)->item != WordArr[i])
		{
			 place = pos;
			while ((temp + pos)->item != WordArr[i])
			{

				if (pos==6000)//checking 25 places is more than enough as more then 5 amalgams are rare of a word 
				{
					FoundFlag = 0;
					break;
				}
				pos++;
			}

			if (FoundFlag == 0)
			{
				if (TotWords > 1)
				{
					cout << "The given string " << key << " doesnot occur in the doocuments" << endl;
					return;
				}
				else
				{
					cout << "The Given word " << WordArr[i] << " doesnot occur in the documents" << endl;
					return;
				}
			}
			else
			{
				cout << pos << " " << WordArr[i] << " ";
				Accessor.Search(root, WordArr[i]);
				(temp + pos)->Accessor.PrintPostings((temp + pos)->PostHead);
				cout << endl;
			}
		}
		else
		{
			cout << pos << " " << WordArr[i] << " ";
			Accessor.Search(root, WordArr[i]);
			(temp + pos)->Accessor.PrintPostings((temp + pos)->PostHead);
			cout << endl;
		}
	end:;
	}
	
	

}