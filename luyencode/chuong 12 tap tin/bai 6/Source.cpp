#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> arr;

	//cách 1

	//int n = 5;
	//arr.resize(n);
	//arr[0] = 1;
	//arr[1] = 2;
	//arr[2] = 3;
	//arr[3] = 4;
	//arr[4] = 5;
	//arr.insert(arr.begin() +3,69);
	////them 5 lan 69
	//arr.insert(arr.begin() + 3, 5, 69);
	////arr.erase(arr.begin() + 2);
	//int sophantu = arr.size();
	//for (int i = 0; i < sophantu; i++)
	//{
	//	cout << arr[i] << " ";
	//}

	//cach 2;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);

	
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}