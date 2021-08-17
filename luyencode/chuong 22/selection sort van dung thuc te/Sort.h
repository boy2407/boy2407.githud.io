﻿#pragma once
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