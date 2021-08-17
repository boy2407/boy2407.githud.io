#include <stdio.h>
#include <conio.h>
/* Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết */
struct Node
{
	int data;
	struct Node* pNext;
};
typedef struct Node NODE;

struct List
{
	NODE* pHead, * pTail;
};
typedef struct List LIST;
/* ---------------------------------------------------- */

// Bước 2: Khởi tạo danh sách liên kết
void Init(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

// Bước 3: Tạo Node trong danh sách liên kết
NODE* GetNode(int DATA){
	NODE* p = new NODE; // Khởi tạo con trỏ p
	if (p == NULL)
	{
		printf("\nKhong du bo nho de cap phat con tro");

		return NULL; 
	}
	p->data = DATA; 
	p->pNext = NULL; 
	return p; 
}
// Bước 4: Thêm Node p vào đầu/Thêm Node p vào cuối trong danh sách liên kết
void AddHead(LIST& l, NODE* p){
	
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p; 
	}
}
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p; // pTail trỏ Next tới p
		l.pTail = p; // Cập nhật pTail chính là p
	}
}
/* ------------------------------------------------ */
/* Bước 5: Viết hàm InPut/OutPut */
void InPut(LIST& l)
{
	Init(l); // Khởi tạo danh sách.

	int n;
	printf("\nNhap vao so luong phan tu trong danh sach: ");
	scanf_s("%d", &n);

	// Vòng lặp chạy n lần, mỗi lần nhập dữ liệu cho 1 Node
	for (int i = 1; i <= n; i++)
	{
		int data;
		printf("\nNhap vao data: ");
		scanf_s("%d", &data);

		// Đóng gói data vào Node
		NODE* p; // Khai báo
		p = GetNode(data); // Cho con trỏ p trỏ tới Node được tạo ra.
		//AddHead(l, p); // Thêm  Node p vào đầu danh sách
		AddTail(l, p);
	}
}
void OutPut(LIST l)
{
	// for(int i = 0; i < n; i++)
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		printf("%4d", p->data);
	}
	

}
/* ------------------------------------------------------ */
/* Bước 6: Những xử lý yêu cầu cần có trên danh sách liên kết */
// Tính tổng danh sách
int TinhTong(LIST l)
{
	// for(int i = 0; i < n; i++)
	int tong = 0;
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		tong += p->data;
	}
	return tong;
}
// Liệt kê các số chẵn trong danh sách
void LietKeSoChan(LIST l)
{
	printf("\nCac so chan co trong danh sach la: ");
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->data % 2 == 0)
		{
			printf("%4d", p->data);
		}
	}
}
// sắp xếp danh sách liên kết đơn tăng dần/giảm dần
void HoanVi(int& x, int& y)
{
	/*int temp = x;
	x = y;
	y = temp;*/
	x = x + y;
	y = x - y; // y = x
	x = x - y; // x = y
}
void SapXep(LIST& l, char phanloai)
{
	/*
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				HoanVi(a[i], a[j]);
			}
		}
	}
	*/
	for (NODE* p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (phanloai == 't')
			{
				if (p->data > q->data)
				{
					HoanVi(p->data, q->data);
				}
			}
			else if (phanloai == 'g')
			{
				if (p->data < q->data)
				{
					HoanVi(p->data, q->data);
				}
			}
		}
	}

}
//THem Node x vao sau q
void ThemVaoSau(LIST& l, NODE* x, NODE* q)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->data == q->data)
		{
			NODE* g = p->pNext;//tim thang dang sau
			x->pNext = g;
			p->pNext = x;
			return;
		}
	}
	AddHead(l, x);
}
void ThemSauTacCaSoChan(LIST& l, int phantuthemvao)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->data % 2 == 0)
		{
			NODE* x = GetNode(phantuthemvao);//getnode o ngay bên trong để tạo ra node mới 

			NODE* g = p->pNext;//tim thang dang sau
			x->pNext = g;
			p->pNext = x;
			p = p->pNext;//bỏ qua khong xét giống mảng thêm nhiều
		}
	}
}
//1 2 3 4 5
//
// p=4
void ThemVaoTruoc(LIST& l, NODE* x, NODE* p)
{
	// Tìm Node nằm trước Node p => gọi là Node q
	NODE* q = x;
	if (p->data == l.pHead->data)
	{
		AddHead(l, x);
		return;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data == p->data)
		{
			x->pNext = k;
			q->pNext = x;
			return;
		}
		q = k;
	}
}void ThemVaoTruocCacSoChan(LIST& l, int phancanthem)
{
	// Tìm Node nằm trước Node p => gọi là Node q
	NODE* q = l.pHead;
	for (NODE* p = l.pHead->pNext; p != NULL; p = p->pNext)
	{
		if (p->data % 2 == 0)
		{
			NODE* x = GetNode(phancanthem);
			x->pNext = p;
			q->pNext = x;
		}
		q = p;
	}
	if (l.pHead->data % 2 == 0)
	{
		NODE* g = GetNode(phancanthem);
		AddHead(l, g);
	}
}
void XoaDauDanhSach(LIST& l)
{
	if (l.pHead != NULL)
	{
		NODE* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void XoauSauMotNode(LIST& l, NODE* p)
{
	for (NODE* i = l.pHead; i != l.pTail; i = i->pNext)
	{
		if (i->data = p->data)
		{
			//xoa node j=p
			NODE* j = p->pNext;//trỏ tới p
			p->pNext = j->pNext;//trỏ bỏ qua p tới p+1
			delete j;
			return;
		}
	}
}
void XoaCuoi(LIST& l)
{
	NODE* g = l.pHead;
	//1 2 3
	// g=2,i=3=ptail

	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i == l.pHead && i == l.pTail)
		{
			XoaDauDanhSach(l);
			return;
		}
		if (i == l.pTail)
		{
			g->pNext = NULL;
			l.pTail = g;
			delete i;
			return;
		}
		g = i;
	}


}
void XoaHetSoChan(LIST& l)
{
	NODE* truoc = l.pHead;

	for (NODE* i = l.pHead->pNext; i != l.pTail; i = i->pNext)
	{		
		if (i->data % 2 == 0)
		{
			NODE* sau;
			sau = i->pNext;
			truoc->pNext = sau;
			delete i;
			i = truoc;
		}
		truoc = i;
	}
	if (l.pHead->data % 2 == 0)
	{
		XoaDauDanhSach(l);
	}
	if (l.pTail->data % 2 == 0)
	{
		XoaCuoi(l);
	}
}
void ThayTheGiaTri(LIST& l,int bithay,int sothaythe)
{
	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->data == bithay)
		{
			i->data = sothaythe;
		}
	}
}
// Bước 7: Giải phóng danh sách liên kết
void GiaiPhong(LIST& l)
{
	NODE* p;
	while (l.pHead != NULL)
	{
		p = l.pHead; // Cho con trỏ p trỏ vào pHead
		l.pHead = l.pHead->pNext; // pHead được trỏ sang Node bên cạnh
		delete p; // giải phóng con trỏ
	}
}

int main()
{
	LIST l; // Khai báo danh sách.
	InPut(l);
	OutPut(l);
	printf("\n");
	
	XoaHetSoChan(l);
	OutPut(l);
	/*NODE q, *x;
	
	x = GetNode(69);
	printf("\n%4d %4d\n", sizeof(q),sizeof(int));*/
	//printf("\nThem 69 dau sau 2 ");
	//ThemVaoSau(l, x, q);
	////OutPut(l);

	/*ThemSauTacCaSoChan(l, 70);
	OutPut(l);*/

	/*printf("\nThem 69 vao dang truoc 2: ");
	ThemVaoTruoc(l, x, q);
	OutPut(l);*/

	/*printf("\nxoa dau danh sach");
	
	ThayTheGiaTri(l, 1, 69);
	OutPut(l);*/


	//GiaiPhong(l); // Giải phóng danh sách
	// printf("\npTail = %d", l.pTail ->data);


	return 0;
}