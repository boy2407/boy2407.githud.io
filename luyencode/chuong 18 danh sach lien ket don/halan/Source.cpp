#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Node
{
	string data;
	struct Node* pNext;
};
typedef struct Node NODE;
struct Stack
{
	NODE* Top;
};
typedef struct Stack STACK;
void Init(STACK& s)
{
	s.Top = NULL;
}
NODE* GetNode(string x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		system("pause");
		return NULL;
	}

	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(STACK s)
{
	if (s.Top == NULL)
	{
		return true;
	}
	return false;
}
bool Push(STACK& s, NODE* p)
{
	if (s.Top == NULL)
	{
		s.Top = p;
		return true;
	}
	p->pNext = s.Top;
	s.Top = p;
	return true;
}
bool Pop(STACK& s, string& x)
{
	if (s.Top == NULL)
	{
		return false;
	}
	NODE* q = s.Top;
	x = q->data;
	s.Top = s.Top->pNext;
	delete q;
	return true;
}
bool Top(STACK s,string &x)
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.Top->data;
	return true;
}
void Input(STACK& s)
{
	ifstream FileIn;
	FileIn.open("input.txt", ios_base::in);
	if (!FileIn)
	{
		cout << "\nkhong tim thay File" << endl;
		system("pause");
		exit(0);
	}
	string str;
	getline(FileIn, str);
	Init(s);
	for (int i = 0; i < str.length(); ++i)
	{
		NODE* p = new NODE;
		if (str[i] == '(')
		{
			continue; // Bỏ lần lặp hiện tại.
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			char* Temp = new char;
			Temp[0] = str[i];
			Temp[1] = '\0';
			string a = Temp;

			p = GetNode(a);
			Push(s, p);
		}

		string Temp;
		int Start;
		int End;

		if (str[i] >= '0' && str[i] <= '9')
		{
			Start = i;

			for (int j = i + 1; j < str.length(); j++)
			{
				if (str[j] < '0' || str[j] > '9')
				{
					End = j;
					i = j;
					break;
				}
			}
			End - 1;
			Temp = str.substr(Start, End - Start);

			p = GetNode(Temp);
			Push(s, p);
		}
	}
	FileIn.close();
}
void OutPut(STACK s)
{
	while (!IsEmpty(s))
	{
		string str;
		Pop(s,str);
		cout << str << endl;
	}
}
int main()
{
	STACK s;
	Input(s);
	OutPut(s);
	system("pause");
}
