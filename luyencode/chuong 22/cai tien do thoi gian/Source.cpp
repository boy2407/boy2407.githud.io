#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
using namespace std;

bool DocuLieTuTapTin(string tentaptin, int*& a, int& n)
{
	ifstream FileIn;
	FileIn.open(tentaptin, ios_base::in);
	if (FileIn)
	{
		FileIn >> n;
		a = new int[n];
		for (int i = 0; i < n; i++)
		{
			FileIn >> a[i];
		}
	
		FileIn.close();
		return true;
	}
	cout << "\nkhong tim thay tap tin" << tentaptin;
	return false;
}

template <class abc> // abc là tên bất kỳ ta đặt đại diện cho kiểu dữ liệu
void XuatMang(abc* a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("\n%d = %4d", i, a[i]);

}
template <class T>
void HoanVi(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;

	//printf("\ngan trong ham HoanVi => gan = %d", gan);
}

// kieusapxep là true: tăng - false: giảm
template <class T>
void SelectionSort(T*& a, int n, bool kieusapxep = true)
{
	for (int i = 0; i < n - 1; ++i) // Vị trí dãy hiện hành để tìm Min bắt đầu từ i
	{
		int vitriMin = i; // bắt đầu xét từ phần tử đầu dãy hiện hành là i

		//printf("\ngan vong lap i => i = %d => gan = %d", i, gan);

		for (int j = i + 1; j < n; ++j) // Xét các phần tử kế tiếp để tìm Min
		{
			if (a[j] < a[vitriMin] == kieusapxep) // Nếu phần tử nào nhỏ hơn => cập nhật lại vị trí Min
			{
				vitriMin = j; // cập nhật lại vị trí Min

				//printf("\ngan vong lap j => j = %d => gan = %d", j, gan);
			}
		}
		HoanVi(a[i], a[vitriMin]); // đưa phần tử tại vị trí Min đó về đầu dãy hiện hành (tức là tại vị trí i hiện tại)
	}
}
template <class T>
void ExchangeSort(T* a, int n, bool kieusapxep = true)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[i])
			{
				HoanVi(a[j], a[i]);
			}
		}
	}
}
int main()
{
	int* a;
	int n ;
	
	vector<string>DanhSachCacThuatToanSapXepCanThongKe;
	DanhSachCacThuatToanSapXepCanThongKe.push_back( "SeletionSort");
	DanhSachCacThuatToanSapXepCanThongKe.push_back("InterchangeSort");
	int size_DSTT = DanhSachCacThuatToanSapXepCanThongKe.size();


	vector<string>DanhSachCacTapDuLieu;
	DanhSachCacTapDuLieu.push_back("10.000.txt");
	DanhSachCacTapDuLieu.push_back("50.000.txt");
	/*DanhSachCacTapDuLieu.push_back("80.000.txt");
	DanhSachCacTapDuLieu.push_back("1000.000.txt");*/
	int size_DSDL = DanhSachCacTapDuLieu.size();
	int solenchayDothoigian = 3;
	ofstream FileOut;
	FileOut.open("BangthongKeThoiGian.txt", ios_base::out);
	for (int i = 0; i < size_DSTT; ++i)//xuat ten thuat toan
	{
		if (i != 0)
		{
			FileOut << "\n\n";
		}
		FileOut << "\t\t\t\t" << DanhSachCacThuatToanSapXepCanThongKe[i];
		FileOut << "\nTap Du Lieu";
		for (int m = 1; m <= solenchayDothoigian; ++m)
		{
			FileOut << "\t" <<"Lan chay "<<m;
		}
		FileOut << "\tTrung Binh";
		for (int j = 0;  j < size_DSDL;  j++)
		{
			double tongthoigianchay = 0;
			int length = DanhSachCacTapDuLieu[j].length();
			FileOut << "\n" << DanhSachCacTapDuLieu[j].substr(0,length-4)<<"\t\t";
			for (int k = 0; k < solenchayDothoigian; ++k)
			{
				int* a;
				int n = 0;			
				bool kiemtradoc = DocuLieTuTapTin(DanhSachCacTapDuLieu[j], a, n);
				if (kiemtradoc)
				{
					clock_t start = clock();
					if (DanhSachCacThuatToanSapXepCanThongKe[i] == "SeletionSort")
					{
						SelectionSort(a, n);
					}
					else if(DanhSachCacThuatToanSapXepCanThongKe[i]=="InterchangeSort")
					{
						ExchangeSort(a, n);
					}
					clock_t end = clock();
					double thoigianchay = (double)(end-start)/ CLOCKS_PER_SEC;
					tongthoigianchay += thoigianchay;
					FileOut << fixed << setprecision(3) << thoigianchay<<"s" << "\t\t";				 
				}
				delete[]a;				
			}
			FileOut << fixed << setprecision(3) << tongthoigianchay/3 << "s";
		}
	}
	
}