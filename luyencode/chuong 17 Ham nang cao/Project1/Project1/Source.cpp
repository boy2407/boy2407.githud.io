#include <iostream>
#include <vector>
using namespace std;
void Nhap(vector<int>& arr, int &n)
{
	// Nhập số lượng phần tử.
	do {
		cout << "\nNhap vao so luong phan tu: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "\nSo luong phan tu phai > 0. Xin kiem tra lai!";
		}
	} while (n <= 0);

	// Cấp phát bộ nhớ cho vector.
	arr.resize(n); // <=> arr.resize(n, 0);
}
void Xuat(vector<int> arr)
{
	for (int i = 0; i < arr.size(); ++i) // Dùng hàm size để lấy kích thước mảng hiện hành.
	{
		cout << arr.at(i) << "   "; // <=> cout << arr[i] << "   ";
	}
}
int main()
{
	vector<int> arr;

	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(1);
	//arr.erase(arr.begin(),arr.begin()+5);
	/*arr.insert(arr.begin() + 2, 6);
	arr.insert(arr.begin() + 2, 2,6);*/
	vector<int>arr1;
	vector<int> arr_1;
	for (int i =0; i <=10; i++)
	{
		arr_1.push_back(i);
	}
	arr.insert(arr.begin() + 1, arr_1.begin()+1, arr_1.begin() + 5); // Dạng 3: Chèn dãy các phần tử từ vị trí 1 đến vị trí 3 của vector arr_1 vào vị trí 1 trong vector arr.
	cout << "\n\nMang sau khi chen day cac phan tu tu vi tri 1 --> 3 trong vector arr_1 vao vi tri 1 trong vector arr\n";
	cout<<arr.capacity()<<endl;
	cout << arr.size()<<endl;
	//Nhap(arr,n);
	Xuat(arr_1);
	cout<<endl;
	Xuat(arr);
	
}