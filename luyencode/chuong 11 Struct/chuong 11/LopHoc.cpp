#include "LopHoc.h"
#define SOTIENMOTCHI 120000
#define KHA 2500000
#define GIOI 3000000
#define XUATSAC 3500000
template <typename sondeptrai>
// vừa để gia tăng, vừa giảm bớt ô nhớ.
void REALLOC(sondeptrai*& a, int OldSize, int NewSize)
{
	// Bước 1: Tạo ra 1 mảng mới là bản sao của mảng cũ rồi đổ dữ liệu từ mảng cũ sang.
	sondeptrai* tam = new sondeptrai[OldSize];

	for (int i = 0; i < OldSize; i++)
	{
		tam[i] = a[i];
	}

	// Bước 2: Xóa mảng cũ đi và cấp mới lại.
	delete[] a;
	a = new sondeptrai[NewSize];

	// Bước 3: Đổ dữ liệu từ mảng tạm sang mảng mới.
	int Min = OldSize < NewSize ? OldSize : NewSize;

	for (int i = 0; i < Min; i++)
	{
		a[i] = tam[i];
	}

	// Bước 4: Xóa mảng tạm đi.
	delete[] tam;
}
void NhapLopHoc(LOPHOC& lh)
{
	do {
		printf("\nNhap vao so luong sinh vien trong lop hoc: ");
		scanf_s("%d", &lh.n);

		if (lh.n < 0)
		{
			printf("\nSo luong khong hop le. Xin kiem tra lai !");
		}
	} while (lh.n < 0);

	lh.arr = (SINHVIEN*)malloc(lh.n * sizeof(SINHVIEN));
	for (int i = 0; i < lh.n; i++)
	{
		printf("\n------- Nhap Sinh Vien Thu %d ------", i + 1);
		int Check; // chưa bị trùng
		do {
			Check = 0; // reset.

			fflush(stdin);
			printf("\nNhap vao ma so: ");
			gets_s(lh.arr[i].MaSo);

			// Kiểm tra xem mã số của sinh viên sau có bị trùng với mã số của các sinh viên trước đó hay không ?
			for (int j = i - 1; j >= 0; j--)
			{
				if (strcmp(lh.arr[i].MaSo, lh.arr[j].MaSo) == 0)
				{
					Check = 1; // Cap nhat bi trung
					break; // thoat ra luon
				}
			}

			if (Check == 1)
			{
				printf("\nMa so sinh vien nay da bi trung. Xin hay nhap lai ma so moi");
			}
		} while (Check == 1);

		// Nhập tiếp các thông tin còn thiếu.
		NhapSinhVien(lh.arr[i]);
	}
}
void XuatLopHoc(LOPHOC lh)
{
	for (int i = 0; i < lh.n; i++)
	{
		printf("\n------- Sinh Vien Thu %d ------", i + 1);
		XuatSinhVien(lh.arr[i]);
	}
}
void HoanVi(SINHVIEN& a, SINHVIEN& b)
{
	SINHVIEN Temp = a;
	a = b;
	b = Temp;
}
void SapXepLopHoc(LOPHOC& lh, char phanloai)
{
	for (int i = 0; i < lh.n - 1; i++)
	{
		for (int j = i + 1; j < lh.n; j++)
		{
			if (phanloai == 't')
			{
				if (TinhDiemTrungBinh(lh.arr[i]) > TinhDiemTrungBinh(lh.arr[j]))
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}
			else
			{
				if (TinhDiemTrungBinh(lh.arr[i]) < TinhDiemTrungBinh(lh.arr[j]))
				{
					HoanVi(lh.arr[i], lh.arr[j]);
				}
			}

		}
	}
}
int DemSoLuongHocBong(LOPHOC lh)
{
	int dem = 0;
	for (int i = 0; i < lh.n; i++)
	{
		if (strcmp(XepLoai(lh.arr[i]), "Gioi") == 0 || strcmp(XepLoai(lh.arr[i]), "Kha") == 0)
		{
			dem++;
		}
	}
	return dem;
}
void XuLyHoclai(LOPHOC lh, int& dem, float& tien)
{
	dem = 0;
	tien = 0;

	for (int i; i < lh.n; i++)
	{
		int check = 0;
		for (int j = 0; j < lh.arr[i].danhsachmon.n; j++)
		{

			if (lh.arr[i].danhsachmon.arr[j].SoDiem < 5)
			{
				check = 1;

				tien += lh.arr[i].danhsachmon.arr[j].SoChi * SOTIENMOTCHI;

			}

		}
		if (check == 1)
		{
			dem++;
		}
	}
}
SINHVIEN *TimKiemThongTin(LOPHOC lh, char* MaTimKiem)// trả về con trỏ sinh vien
{
	for (int i = 0; i < lh.n; i++)
	{
		if (strcmp(lh.arr[i].MaSo, MaTimKiem) == 0)
		{
			return &lh.arr[i];
		}
		
	}
	return NULL;
}
void XoaSinhVien(LOPHOC& lh, int Vitrixoa)
{
	for (int i = Vitrixoa+1; i < lh.n; i++)
	{
		lh.arr[i - 1] = lh.arr[i];
	}
	REALLOC(lh.arr, lh.n, lh.n--);
}
void XoaSinhVienDuaTrenMa(LOPHOC& lh, char* Maso)
{
	for (int i = 0; i < lh.n; i++)
	{
		if (strcmp(lh.arr[i].MaSo,Maso)==0)
		{
			XoaSinhVien(lh,i);
			break;/// thoat ra khoi vong lap ngay khi xoa boi Maso khong trùng
		}
	}
}
void XoaTatCaSinhVienRotMon(LOPHOC &lh)
{
	for (int i = 0; i < lh.n; i++)
	{
		if (KiemTraBiRotMon(lh.arr[i]))
		{
			XoaSinhVien(lh, i);
			i--;
		}
	}
}
void CapNhatDuaTrenMaSo(LOPHOC&lh, char*Maso)
{
	for (int i = 0; i < lh.n; i++)
	{
		if (strcmp(lh.arr[i].MaSo, Maso) == 0)
		{
			SINHVIEN sv;
			strcpy(sv.MaSo, Maso);
			NhapSinhVien(sv);
			lh.arr[i] = sv;
			break;

		}
	}
}
void SapXepTen(LOPHOC& lh, char phanloai)
{
	for (int i = 0; i < lh.n; i++)
	{
		for (int j = i + 1; j < lh.n; j++)
		{
			if (phanloai == 't')
			{
				char Ten1[30], Ten2[30];
					//strcpy(Ten1,LocRaTen(lh.arr[i]));
					//strcpy(Ten2,LocRaTen(lh.arr[i]));
					if (strcmp(Ten1, Ten2) == 1)
					{

					}
			}
			if (phanloai == 'g')
			{
				char Ten1[30], Ten2[30];
					//strcpy(Ten1,LocRaTen(lh.arr[i]));
					//strcpy(Ten2,LocRaTen(lh.arr[i]));
					if (strcmp(Ten1, Ten2) == -1)
					{

					}
			}
		}
	}
}