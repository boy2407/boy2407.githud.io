#include "LopHoc.h"



int main()
{
	LOPHOC lh;

	NhapLopHoc(lh);
	XuatLopHoc(lh);

	/*printf("\nDanh sach lop sau khi sap xep tang dan la\n");
	SapXepLopHoc(lh, 't');
	XuatLopHoc(lh);

	printf("\nDanh sach lop sau khi sap xep giam dan la\n");
	SapXepLopHoc(lh, 'g');
	XuatLopHoc(lh);*/

	//int SoHocSinhNhanHocBong = DemSoLuongHocBong(lh);
	//printf("\nSo luong nhan hoc bong la: %d", SoHocSinhNhanHocBong);

	//char MaTimKiem[30];
	//fflush(stdin); // xóa bộ nhớ đệm.
	//printf("\nNhap vao ma tim kiem la: ");
	//gets(MaTimKiem);

	//SINHVIEN *sv = TimKiemThongTin(lh, MaTimKiem);

	//if(sv == NULL)
	//{
	//	printf("\nKhong tim thay thong tin sinh vien");
	//}
	//else
	//{
	//	printf("\nTim thay thong tin sinh vien la\n");
	//	XuatSinhVien(*sv);
	//}

	SINHVIEN them; // thêm vào cuối danh sách lớp.

	// Nhập thông tin sinh viên cần thêm

	fflush(stdin);
	printf("\nNhap vao ma so: ");
	gets_s(them.MaSo);


	NhapSinhVien(them);
	//CapPhatLai(lh);
	//realloc(lh.arr, (lh.n + 1) * sizeof(SINHVIEN));
	

	//// Đưa thông tin sinh viên thêm vào cuối cùng.
	lh.arr[lh.n] = them;

	lh.n++; // Tăng số lượng sinh viên lên.

	printf("\nDanh sach lop hoc sau khi them la\n");
	XuatLopHoc(lh);

	// test
	/*XoaSinhVien(lh, 0);
	printf("\nDanh sach lop sau khi xoa la\n");
	XuatLopHoc(lh);*/

	//XoaSinhVienDuaTrenMaSo(lh, "1");

	/*XoaTatCaSinhVienRotMon(lh);
	printf("\nDanh sach lop sau khi xoa la\n");
	XuatLopHoc(lh);*/

	/*CapNhatDuaTrenMaSo(lh, "5");
	printf("\nDanh sach sau khi cap nhat la:\n");
	XuatLopHoc(lh);*/


	// giải phóng bộ nhớ.
	//free(lh.arr);
	delete[]lh.arr;
	return 0;
}