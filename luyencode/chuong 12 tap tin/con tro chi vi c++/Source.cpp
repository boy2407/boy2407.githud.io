///Nguyen Trong Nghia

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
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
	string ten;
	int ngay, thang, nam;
	float tona, ly, hoa;
	getline(FileIn, ten, '-');
	ten.erase(ten.begin() + ten.length() - 1);
	/// <summary>
	///  24/7/2001- 7-  8 - 9
	/// </summary>
	/// <returns></returns>

	ofstream FileOut;
	FileOut.open("OUTPUT.TXT", ios_base::out);
	FileOut.close();

	return 0;
}