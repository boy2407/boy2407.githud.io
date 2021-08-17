#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


int main()
{
	string str = "adcd";
	cout << str.capacity();
	int so;

	so=atoi((char *)str.c_str());
	system("pause");
	return 0;
}