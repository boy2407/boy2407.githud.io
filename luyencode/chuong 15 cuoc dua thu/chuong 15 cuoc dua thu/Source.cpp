#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
#define SUTU_THOIGIANBATDAU 9
#define THO_THOIGIANBATDAU 8
#define RUA_THOIGIANBATDAU 7

#define SUTU_QUANGDUONNGCHAY 210
#define THO_QUANGDUONGCHAY 210
#define RUA_QUANGDUONGCHAY 135

struct ConVat
{
	string MaSo;
	int TocDo, TrangBi;
};
typedef struct ConVat CONVAT;

void NhapConVat(ifstream& FileIn, CONVAT& cv)
{
	FileIn >> cv.MaSo >> cv.TocDo >> cv.TrangBi;
}

void XuatConVat(ofstream& FileOut, CONVAT cv)
{
	FileOut << cv.MaSo << " " << cv.TocDo << " " << cv.TrangBi;

}
void NhapDanhSach(ifstream& FileIn, vector<CONVAT>& DanhSach)
{
	int n;
	FileIn >> n;
	for (int i = 0; i < n; i++)
	{
		CONVAT cv;
		NhapConVat(FileIn, cv);
		DanhSach.push_back(cv);
	}
}
void XuatDanhSach(ofstream& FileOut, vector<CONVAT>DanhSach)
{
	int n = DanhSach.size();
	for (int i = 0; i < n; i++)
	{
		XuatConVat(FileOut, DanhSach[i]);
		FileOut << endl;
	}
}
int TimVanTocThucSu(CONVAT cv)
{
	if (cv.TrangBi == 0)
	{
		return cv.TocDo;
	}
	if (cv.TrangBi == 1)
	{
		if (cv.MaSo[0] == 'L')
		{
			return cv.TocDo * 2;
		}
		else if (cv.MaSo[0] == 'R')
		{
			return cv.TocDo + 30;
		}
		else if (cv.MaSo[0] == 'T')
		{
			return cv.TocDo * 5;
		}
	}
}
double TimThoiGianDiHetQuangDuong(CONVAT cv)
{
	int tocdothucsu = TimVanTocThucSu(cv);
	if (cv.MaSo[0] == 'L')
	{
		return (double)SUTU_QUANGDUONNGCHAY / tocdothucsu;
	}
	else if (cv.MaSo[0] == 'R')
	{
		return (double)THO_QUANGDUONGCHAY / tocdothucsu;
	}
	else if (cv.MaSo[0] == 'T')
	{
		return (double)RUA_QUANGDUONGCHAY / tocdothucsu;
	}
}
double TimThoiGianVeDich(CONVAT cv)
{
	double thoigianchay = TimThoiGianDiHetQuangDuong(cv);
	if (cv.MaSo[0] == 'L')
	{
		return SUTU_THOIGIANBATDAU + thoigianchay;
	}
	else if (cv.MaSo[0] == 'R')
	{
		return THO_THOIGIANBATDAU + thoigianchay;
	}
	else if (cv.MaSo[0] == 'T')
	{
		return RUA_THOIGIANBATDAU + thoigianchay;
	}
}
void HoanVi(CONVAT& a, CONVAT& b)
{
	CONVAT temp = a;
	a = b;
	b = temp;

}
void SapXepDanhSach(vector<CONVAT> &DanhSach)
{

	int n = DanhSach.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double thoivedich1 = TimThoiGianVeDich(DanhSach[i]);
			double thoivedich2 = TimThoiGianVeDich(DanhSach[j]);
	
			if (thoivedich1 > thoivedich2)
				{
					HoanVi(DanhSach[i], DanhSach[j]);
			}				
		}
	}

}
int main()
{
	ifstream FileIn("INPUT.TXT");

	if (!FileIn)
	{
		cout << "Tap khong ton tai";
		return 0;
	}

	vector <CONVAT> DanhSach;
	NhapDanhSach(FileIn, DanhSach);
	FileIn.close();
	int n = DanhSach.size();
	ofstream FileOut("OUTPUT.TXT");
	int dem = 0;
	FileOut << dem << endl;
	SapXepDanhSach(DanhSach);
	for (int i = 0; i < n; i++)
	{
		
		if (TimThoiGianVeDich(DanhSach[i]) <= 12)
		{
				++dem;
				
				FileOut << i + 1<<". ";
				XuatConVat(FileOut, DanhSach[i]);
				FileOut << endl;
		}				
		
	}
	FileOut.seekp(0, SEEK_SET);
	FileOut << dem ;
	FileOut.close();


	return 0;
}