#include "Table.h"
using namespace std;
Table::Table()
{
	
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
	NewNode->index = 0;
	NewNode->next = *head;
	*head = NewNode;
}
void Table::InitializeTable(Table **head)
{
	Table* temp = *head;
	for (int i = 1; i < 4000; i++)
	{
		Table* NewNode = new Table;
		NewNode->index = i;
		NewNode->PostHead = NULL;
		temp->next = NewNode;
		temp = NewNode;
	}
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
	int pos = hash(key);
	Table* temp = *head;

	for (int i = 0; i <= pos; i++)
	{
		temp = temp->next;
	}
	if (temp->item == "NULL" && temp->item != key)
	{
		temp->item = key;
		temp->Accessor.InsertAtBegining(&temp->PostHead, DocId);
		temp->Accessor.IncrementFrequency(&temp->PostHead,DocId);
		return;
	}
	if (temp->item != "NULL" && temp->item == key && temp->PostHead->ReturnData() != DocId)
	{
		temp->item = key;
		temp->Accessor.InsertAtBegining(&temp->PostHead, DocId);
		temp->Accessor.IncrementFrequency(&temp->PostHead,DocId);
		return;
	}
	if (temp->item != "NULL" && temp->item == key  && temp->PostHead->ReturnData()==DocId)
	{
		temp->item = key;
		temp->Accessor.IncrementFrequency(&temp->PostHead,DocId);
		return;
	}
	if (temp->item != "NULL")
	{
		while (temp->item != "NULL")
		{
			temp = temp->next;
		}
		temp->item = key;
		temp->Accessor.InsertAtBegining(&temp->PostHead, DocId);
		//Accessor.InsertAtBegining(&PostHead, DocId);
	}
}
void Table::Search(string key,Table **head)
{
	
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
		for (int i = 0; i <= pos; i++)
		{
			temp = temp->next;
		}
		 FoundFlag = 1;
		if (temp->item != WordArr[i])
		{
			 place = pos;
			while (temp->item != WordArr[i])
			{

				if (pos - 25 == place) //checking 25 places is more than enough as more then 5 amalgams are rare of a word 
				{
					FoundFlag = 0;
					break;
				}
				temp = temp->next;
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
				temp->Accessor.PrintPostings(temp->PostHead);
				cout << endl;
			}
		}
		else
		{
			cout << pos << " " << WordArr[i] << " ";
			temp->Accessor.PrintPostings(temp->PostHead);
			cout << endl;
		}
	end:;
	}
	
	

}