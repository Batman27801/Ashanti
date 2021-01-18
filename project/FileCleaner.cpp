#include "FileCleaner.h"
CleanQ::CleanQ()
{
	charactercount = 0;
	wordcount = 1;
	newlines = 0;
	front = 0;
	rear = -1;
	capacity = 50;
	queue = new char[capacity];
}
CleanQ::~CleanQ()
{
	delete this->queue;
}
char CleanQ::dequeue()
{
	if (rear == -1)
		cout << "Queue underflow/empty";
	else
	{
		char c = queue[0];
		for (int i = 0; i < rear; i++)
		{
			queue[i] = queue[i + 1];
		}
		rear--;
		return c;
	}
}
char& CleanQ::enqueue()
{
	if (capacity == rear)
	{
		cout << "Queue overflow";
	}
	else
	{
		rear++;
		return queue[rear];
	}
}
char CleanQ::Qrecent()
{
	char c = queue[rear];
	return c;
}
char CleanQ::Qfront()
{
	char c = queue[front];
	return c;
}
void CleanQ::setDocs(string* names)
{
	for (int i = 0; i < 6; i++)
	{
		docs[i] = names[i];
	}
}
void CleanQ::replacedash()
{
	queue[front] = ' ';

}
void CleanQ::filecleaner(string filename)
{
	char c;
	int i = 0;
	ifstream input(filename);
	ofstream output(docs[i]);
	while (!input.eof())
	{
		input.get(enqueue());

		if (input.eof())
			goto cnt;

		if (Qrecent() == ' ' || Qrecent() == '-')
		{
		cnt:
			while (rear != -1)
			{
				if ((Qfront() >= 'a' && Qfront() <= 'z') || (Qfront() >= 'A' && Qfront() <= 'Z') || Qfront() == '\n' || Qfront() == ' ' || Qfront() == '-')
				{
					if (Qfront() == '\n')
						newlines++;
					if (Qfront() == '-')
						replacedash();

					if (newlines >= 1000)
					{
						i++;
						newlines = 0;
						output.close();
						output.open(docs[i]);
					}

					if ((Qfront() == ' ' || Qfront() == '\n') && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
						wordcount++;

					c = Qfront();
					charactercount++;
					output.put(tolower(dequeue()));
				}
				else
					dequeue();
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "The total characters stored in all files were :";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << charactercount << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "The total words stored in all files are : ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << wordcount;
}