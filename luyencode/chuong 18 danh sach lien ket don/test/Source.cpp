#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Node
{
	string Data;
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


NODE* GetNode(string DATA)
{
	NODE* p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";

		return NULL;
	}
	p->Data = DATA; // bỏ Data vào trong Node p
	p->pNext = NULL; // Thiết lập mối liên kết
	return p; // trả Node p về
}

bool KiemTraStackRong(STACK s)
{
	if (s.Top == NULL)
	{
		return true; // rỗng
	}
	return false; // không rỗng
}


bool Push(STACK& s, NODE* p)
{
	/*if (p == NULL)
	{
		return false;
	}	*/
	if (s.Top == NULL)
	{
		s.Top = p;
		return true;
	}

		p->pNext = s.Top;
		s.Top = p;
		return true;		
}


 bool Pop(STACK&s,string &a)
{
	if (s.Top ==NULL)
	{
		return false;
	}
	NODE* p = s.Top;
	a = p->Data;
	s.Top = s.Top->pNext; 
	delete p;
	return true;
}

bool Top(STACK s,string &x)
{
	if (s.Top == NULL)
	{
		return false;
	}
	x = s.Top->Data;
	return true;
}

void InPut(STACK& s)
{
	ifstream FileIn;
	FileIn.open("input.txt", ios_base::in);


	if (!FileIn)
	{
		cout << "\nKhong tim thay tap tin input.txt";
		system("pause");
		return; // Kết thúc.
	}

	string str;
	getline(FileIn, str);

	FileIn.close();

	Init(s);

	string p1, p2, p3;
	int KetQua = 0;
	int demphantu = 0;
	int demdau = 0;
	for (int i = 0; i < str.length(); i++)
	{
		NODE* p = new NODE;
		if (str[i] == '(')
		{
			demdau++;
			continue;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			demphantu++;
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
					i = j - 1;
					break;
				}
			}
			End - 1;
			Temp = str.substr(Start, End - Start);

			p = GetNode(Temp);
			Push(s, p);
			demphantu++;
		}
		if (str[i] == ')')
		{
			Pop(s, p1);
			Pop(s, p2);
			Pop(s, p3);

			int Num3, Num1;
			Num3 = atoi(p3.c_str());
			Num1 = atoi(p1.c_str());

			if (p2 == "+")
			{
				KetQua = Num3 + Num1;

			}
			else if (p2 == "-")
			{
				KetQua = Num3 - Num1;

			}
			else if (p2 == "*")
			{
				KetQua = Num3 * Num1;

			}
			else if (p2 == "/")
			{
				KetQua = Num3 / Num1;

			}
			else if (p2 == "%")
			{
				KetQua = Num3 % Num1;

			}
			string a = to_string(KetQua);
			Node* q = GetNode(a);
			Push(s, q);

		}

	}
	cout << s.Top->Data;
	if (s.Top!=NULL)
	{
		Pop(s, p1);
		Pop(s, p2);
		Pop(s, p3);

		int Num3, Num1;
		Num3 = atoi(p3.c_str());
		Num1 = atoi(p1.c_str());

		if (p2 == "+")
		{
			KetQua = Num3 + Num1;
		}
		else if (p2 == "-")
		{
			KetQua = Num3 - Num1;
		}
		else if (p2 == "*")
		{
			KetQua = Num3 * Num1;
		}
		else if (p2 == "/")
		{
			KetQua = Num3 / Num1;
		}
		else if (p2 == "%")
		{
			KetQua = Num3 % Num1;
		}
		string a = to_string(KetQua);
		Node* q = GetNode(a);
		Push(s, q);
	}
	cout<<"ket qua :" << KetQua << endl;
	cout <<"phan tu :" << demphantu << endl;
}



void OutPut(STACK &s)
{
	while (!KiemTraStackRong(s))
	{
		string a;
		Pop(s, a);
		cout<<a<<endl;
	}


}
int main()
{
	STACK s;
	InPut(s);
	OutPut(s);
	system("pause");
}