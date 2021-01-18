#include "VisualsFunctions.h"
void VisualsFunctions::center_newline()
{
	cout << "\n\n\n\t\t\t\t\t\t";
}
void VisualsFunctions::center_continue()
{
	cout << "\n\t\t\t\t\t\t";
}
void VisualsFunctions::clear_screen()
{
	char ch;
	system("CLS");
	ifstream is;
	is.open("AshantiHeader.txt");
	while (is.get(ch))
	{
		cout << ch;
	}
}
void VisualsFunctions::normal_spacing()
{
	cout << "\n\n\n\n\t\t";
}
void VisualsFunctions::normally_continue()
{
	cout << "\n\t\t";
}
void VisualsFunctions::home_page()
{
	char ch;
	ifstream is;
	is.open("AshantiHome.txt");
	while (is.get(ch))
	{
		cout << ch;
	}
	cout << endl;
	system("pause");
}
void VisualsFunctions::end_page()
{
	char ch;
	system("CLS");
	ifstream is("ProjectEnd.txt");
	while (is.get(ch))
	{
		cout << ch;
	}
	cout << endl;
	system("pause");
}
void VisualsFunctions::loading()
{
	ifstream is("LoadingMsg.txt");
	char ch;
	while (is.get(ch))
	{
		cout << ch;
	}
}
void VisualsFunctions::project_Runner()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	loading();
	center_continue();
	center_continue();
	Table TableAccessor;
	Table* TableHead = NULL;
	TableAccessor.InitializeTotWords(25000);
	TableAccessor.InitializeTable(&TableHead);
	TableAccessor.BuildTable(&TableHead, "Doc1.txt", 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	center_continue();
	cout << "Document 1 Loaded!";
	TableAccessor.BuildTable(&TableHead, "Doc2.txt", 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	center_continue();
	cout << "Document 2 Loaded!";
	TableAccessor.BuildTable(&TableHead, "Doc3.txt", 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	center_continue();
	cout << "Document 3 Loaded!";
	TableAccessor.BuildTable(&TableHead, "Doc4.txt", 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	center_continue();
	cout << "Document 4 Loaded!";
	TableAccessor.BuildTable(&TableHead, "Doc5.txt", 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	center_continue();
	cout << "Document 5 Loaded!";
	TableAccessor.BuildTable(&TableHead, "Doc6.txt", 6);
	center_continue();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Document 6 Loaded!";
	center_continue();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	system("Pause");
	system("CLS");
	Table* temp = TableHead;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	int choice;
	char sent[200];
	string Sentence;
	home_page();
	while (true)
	{
		clear_screen();
		center_newline();
		center_continue();
		cout << "1. Go To Term Search";
		center_continue();
		cout << "2. Go To File Cleaner";
		center_continue();
		cout << "3. Exit Project";
		center_continue();
		cout << "Your Choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1)
		{
			clear_screen();
			center_newline();
			cout << "ENTER THE TERM YOU WANT TO SEARCH: ";
			fflush(stdin);
			getline(cin, Sentence);
			TableAccessor.Search(Sentence, &TableHead);
			center_continue();
			system("pause");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		}
		else if (choice == 3)
		{
			end_page();
			break;
		}
		else if (choice == 2)
		{
			string filename,*otherfiles;
			clear_screen();
			center_newline();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Enter name of the file you want to clean and break into six sub documents(only .txt suported): ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			getline(cin, filename);
			center_continue();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Enter The Names of Six documents you wish to recieve(only .txt suported): ";
			otherfiles = new string[6];
			for (int i = 0; i < 6; i++)
			{
				center_continue();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "File # " << i + 1 << ": ";
				fflush(stdin);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				getline(cin, otherfiles[i]);
			}
			CleanQ obj;
			obj.setDocs(otherfiles);
			obj.filecleaner(filename);
			center_continue();
			system("pause");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		}
		else
		{
			center_continue();
			cout << "YOU ENTERED WRONG INPUT!";
			center_continue();
			system("pause");
			continue;
		}
	}

}
