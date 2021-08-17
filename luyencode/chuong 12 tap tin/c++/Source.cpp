#include<istream>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
/*
INPUT.txt 
Nguyen Tuan
Nguyen Phuoc Vinh Hung
Doan Vuong Binh Tu 
*/
int main()
{
	ifstream FileIn;

	FileIn.open("INPUT.TXT", ios_base::in);

	if (!FileIn)
	{
		cout << "\nKhong Tim thay tap tin INPUT.TXT";
		system("pause");
		return 0;
	}
	string timkiem;
	
	cout << "\nBan muon tim kiem tu khoa nao:";
	getline(cin , timkiem);
	int dem = 0;
	while (!FileIn.eof())
	{
		string str;
		FileIn >> str;
		if (str== timkiem)
		{
			dem++;
		}
	}
	FileIn.close();


	ofstream FileOut;
	FileOut.open("OUTPUT.TXT", ios_base::out);

	FileOut << timkiem << "=>" << dem << " lan";
	FileOut.close();
	return 0;
}