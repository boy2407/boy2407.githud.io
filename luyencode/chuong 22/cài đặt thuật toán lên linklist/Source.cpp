#include<iostream>
#include<random>
using namespace std;

struct Node
{
	int Data;
	struct Node* pNext;
};
typedef struct Node NODE;
struct List
{
	NODE* pHead, *pTail;
};
typedef struct List LIST;

void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}
NODE* GetNode(int x)
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;

	p ->Data = x;
	p->pNext = NULL;
	return p;
}
void AddHead(LIST& l, NODE*p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail= p;
	}
	else 
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext=p;
		l.pTail = p;
	}
}
void InPut(LIST& l)
{
	int n;
	cout << "\nNhap vao n";
	cin >> n;
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{	
		int x = -100 + rand() % (201);
		NODE* p = GetNode(x);
		AddTail(l,p);
	}
}
void GiaiPhongDanhSach(LIST& l)
{
	while (l.pHead!=NULL)
	{
		NODE* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void OutPut(LIST l)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->Data<<" ";
	}
}
int main()
{
	int* x = new int ;
	int* b=x;
	

	cout << x<<endl;
	cout << &b << endl;
	cout << b << endl;
}