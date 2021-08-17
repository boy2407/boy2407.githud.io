#include<stdio.h>
#include<conio.h>
struct Node {

	int data;
	struct Node* pNext;
};
typedef struct Node NODE;
struct List
{
	NODE* pHead;
	NODE* PTail;
};
typedef struct List LIST;

void Init(LIST& l)
{
	l.pHead = l.PTail = NULL;
}
NODE* GetNode(int DATA)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = DATA;
	p->pNext = NULL;
	return p;
 }
void AddHeap(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.PTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(LIST& l, NODE* p)
{
	if (l.PTail == NULL)
	{
		l.pHead = l.PTail = p;
	}
	else
	{
		l.PTail->pNext = p;
		l.PTail = p;
	}
}
void Input(LIST& l)
{
	int n;
	scanf_s("%d", &n);
	for (int i =0 ; i < n; ++i)
	{
		int x;
		scanf_s("%d", &x);
		NODE* p = GetNode(x);
	}
}
int main()
{

}