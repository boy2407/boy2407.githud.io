#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


void PhatSinhDaySo(int n,int a,int b, char* tentaptin,char* mode)//n là các số được Random
{
	FILE* f = fopen(tentaptin, mode);	
	srand(time(0));
	for (int i = 1; i <= n; ++i)
	{			
		int x = a + rand() % (b-a+1);
		fprintf(f, "%d\n", x);
	}
	printf("\nDa ghi la tap tin %s", tentaptin);
	fclose(f);
}
bool DocuLieTuTapTin(char* tentaptin, char* mode, int * &a, int& n)
{
	FILE* f = fopen(tentaptin, mode);

	if (f != NULL)
	{
		a = new int[n];
		int i = 0;
		while (!feof(f))
		{

			fscanf(f, "%d", &a[i]);
			i++;
		}
		
		return true;
		fclose(f);
	}
	return false;
}

template <class abc> // abc là tên bất kỳ ta đặt đại diện cho kiểu dữ liệu
void XuatMang(abc *a, int n)
{
	for (int i = 0; i < n; ++i)
		printf("\n%d = %4d", i,a[i]);
		
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
void SelectionSort(T *&a, int n, bool kieusapxep = true)
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
	
	//PhatSinhDaySo(50000,-100, 100, (char*)"50.000.txt",(char*)"a");

	FILE* f = fopen("dothoigiancacthuattoan.txt", "a");
	/*
	fprintf(f, "\t\t\t\tSecletion Sort");
	fprintf(f, "\nTap Du Lieu\tLan chay 1\tLan Chay 2\tLan chay 3\tTrung Binh");*/
	fprintf(f,"\n50.000\t");
	double tong = 0;
	double thoigian = 0;
	for (int i = 1; i <= 3; ++i)
	{
		int n = 10000;
		int* a;

		bool KiemTra = DocuLieTuTapTin((char*)"50.000.txt", (char*)"r", a, n);
		if (KiemTra)
		{

			clock_t start = clock();
			SelectionSort<int>(a, n);
			clock_t end = clock();
			 thoigian = (double)(end - start) / CLOCKS_PER_SEC;

			//printf("%Voi n = %d => Selection Sort chay may %.3lf", n, thoigian);
			tong += thoigian;
			fprintf(f, "\t%.3fs\t", thoigian);
			delete[]a;
		}

	}
	fprintf(f, "\t%.3fs", tong / 3);
	printf("\nDu lieu da duoc ghi");

	return 0;
}