#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void HoanVi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SapXep(vector<int> &a,char phanloai)
{
	int n = a.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (phanloai == 't')
			{
				if (a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
			else if (phanloai == 'g')
			{
				if (a[i] < a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}
void Docfile(ifstream &FileIn)
{
	
	FileIn.open("INPUT.TXT", ios_base::in);

	if (!FileIn)
	{
		cout<<"\nKhong tim thay tap tin INPUT.TXT ! Xin kiem tra lai !";
		exit(0);
	}
}
int main()
{
	
	ifstream FileIn;
	Docfile(FileIn);
	vector<int>arr;
	
	while (!FileIn.eof())
	{
		int Number;
		FileIn >> Number;
		arr.push_back(Number);
	}
	

	FileIn.close();
	SapXep(arr,'t');

	ofstream FileOut;
	FileOut.open("OUTPUT.TXT",ios_base::out);
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		FileOut << arr[i] << " ";
	}
	FileOut.close();
	return 0;
}
