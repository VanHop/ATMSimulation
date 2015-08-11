#include "PhanCung.h"
#include "TaiKhoan.h"
#include "GiaoDich.h"
#include "HoaDon.h"
#include "DuLieuNganHang.h"
#include "Tien.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;
ManHinh::ManHinh(){};
void ManHinh::hienThi()
{
	int luaChon;
	BanPhim a;
	system("cls");
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"                          Chao Mung Ban Den Voi ATM's VTH !!!"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
	
	cout<<"                +-------------------------------------------+"<<endl;
	cout<<"                +                Huong Dan                  +"<<endl;
	cout<<"                +-------------------------------------------+"<<endl;
	cout<<"                +                                           +"<<endl;
	cout<<"                +     Buoc 1. Lap The ATM Vao (Bam 1)       +"<<endl;
	cout<<"                +     Buoc 2. Nhap Ma The                   +"<<endl;
	cout<<"                +     Buoc 3. Nhap Ma Pin                   +"<<endl;
	cout<<"                +     Buoc 4. Nhan ENTER                    +"<<endl;
	cout<<"                +                                           +"<<endl;
	cout<<"                +-------------------------------------------+"<<endl<<endl;
	luaChon = a.setgetLuaChon();
	switch(luaChon)
	{
		quaylai: system("cls");
		case 1: 
			KheDocThe p;
			dich: int m = p.laySoTaiKhoanThe();
			if (m==1)
				goto kt;
			if (m==2)
			{
				thongBao(2);
				goto dich;
			}
			if (m==3)
			{
				thongBao(3);
				goto quaylai;
			}
			if (m==4)
			{
				thongBao(4);
				goto dich;
			}
			break;
			kt: ;
	}
}
void ManHinh::menu(TaiKhoan nguoiDung[],int k)
{
	BanPhim a;
	GiaoDich p;
	TaiKhoan tk;
	HoaDon hd;
	int luaChon;
	batdau: system("cls");
	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<"                             XIN CHAO!!!"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl<<endl;
	
	cout<<"                +---------------------------------------------+"<<endl;
	cout<<"                +                   Danh Sanh                 +"<<endl;
	cout<<"                +---------------------------------------------+"<<endl;
	cout<<"                +                                             +"<<endl;
	cout<<"                +     Lua Chon 1. Rut Tien                    +"<<endl;
	cout<<"                +     Lua Chon 2. Chuyen Tien                 +"<<endl;
	cout<<"                +     Lua Chon 3. Thanh Toan Hoa Don          +"<<endl;
	cout<<"                +     Lua Chon 4. Mua The Dien Thoai          +"<<endl;
	cout<<"                +     Lua Chon 5. Xem Thong Tin               +"<<endl;
	cout<<"                +     Lua Chon 6. Doi Ma Pin                  +"<<endl;
	cout<<"                +     Lua Chon 7. In Sao Ke                   +"<<endl;
	cout<<"                +     Lua Chon 8. Thoat                       +"<<endl;
	cout<<"                +---------------------------------------------+"<<endl<<endl;
	for (int m=0;m<p.LuuGiaoDich.size();m++)
		cout << p.LuuGiaoDich[m] << endl;
	luaChon = a.setgetLuaChon();
	switch(luaChon)
	{
		case 1:
			p.rutTien(nguoiDung,k);
			goto batdau;
		case 2:
			p.chuyenTien(nguoiDung,k);
			goto batdau;
		case 3:
			int Chon;
			cout << "1: Thanh Toan Tien Dien Nuoc " << endl
				 << "2: Thanh Toan Tien Dien Thoai " << endl;
			cout << "Lua Chon : ";
			cin >> Chon;
			switch(Chon)
			{
				case 1:
					p.thanhToanDienNuoc(nguoiDung,k);
					goto batdau;
				case 2:
					p.thanhToanDienThoai(nguoiDung,k);
					goto batdau;
			}
			goto batdau;
		case 4:
			p.muaTheDienThoai(nguoiDung,k);
			goto batdau;
		case 5:
			p.thongTin(nguoiDung,k);
			goto batdau;
		case 6:
			p.doiMaPin(nguoiDung,k);
			goto batdau;
		case 7:
			p.inHoaDon(nguoiDung,k);
			goto batdau;
		case 8:
			hienThi();
	}
	
}
void ManHinh::thongBao(int i,TaiKhoan nguoiDung[],int k)
{
	TaiKhoan tk;
	DuLieuNganHang dl;
	tk.duLieu[k*4] = 0;
	dl.setLaiDuLieuNganHang(tk.duLieu,tk.soTaiKhoan);
	cout << "\n\n\n\t\t\tDang Nhap Thanh Cong !^^\n\t\t\tDang Tai Du Lieu";
	for (int i=0;i<5;i++)
	{
		cout << ".\a";
		Sleep(500);
	}
	menu(nguoiDung,k);
}
void ManHinh::thongBao(int i)
{
	if (i==2)
	{
		cout << "Ban nhap sai ma pin\n";
		Sleep(3000);
	}
	if (i==3)
	{
		cout << "Tai Khoan Da Bi Khoa Vinh Vien !^^\n";
		Sleep(3000);
	}
	if (i==4)
	{
		cout << "Khong co du lieu\n";
		Sleep(3000);
	}
	if (i==5)
		cout << "Rut Tien Thanh Cong!^^\n";
	if (i==6)
		cout << "So Tien Trong Tai Khoan Khong Du De Rut!^^\nHoac Trong Hop Tien Da Het\nHoac Khong Co Menh Gia Phu Hop\n";
}
KheDocThe::KheDocThe(){};
int KheDocThe::laySoTaiKhoanThe()
{
	system("cls");
	BanPhim b;
	TaiKhoan *nguoiDung, layTk;
	nguoiDung = new TaiKhoan[layTk.laySoTaiKhoan()];
	int maTk, maPin, th=0;
	bool test;
	ManHinh a;
	maTk = b.setgetMaThe();
	maPin = b.setgetMaPin();
	getDuLieu(layTk,nguoiDung);
	for (int i=0;i<layTk.getSoTaiKhoan();i++)
	{
		test = nguoiDung[i].kiemTraMaPIN(maTk,maPin,th);
		if(test==true)
		{
			if (nguoiDung[i].getSoLanNhapSai()<3)
			{
				a.thongBao(1,nguoiDung,i);
				return 1;
			}
			else
				return 3;
		}
		if (test==false)
		{
			if (th==1&&nguoiDung[i].getSoLanNhapSai()<3)
				return 2;
			else
				if (nguoiDung[i].getSoLanNhapSai()>=3)
					return 3;
		}
		else
			return 4;
	}
	return 4;
}
void getDuLieu(TaiKhoan &layTk, TaiKhoan nguoiDung[])
{
	int j=0;
	for (int i=0;i<layTk.soTaiKhoan;i++)
	{
		nguoiDung[i].setSoLanNhapSai(j);
		nguoiDung[i].setMaThe(j+1);
		nguoiDung[i].setMaPin(j+2);
		nguoiDung[i].setSoDu(j+3);
		j=j+4;
	}
}
BanPhim::BanPhim(){};
int BanPhim::setgetMaPin()
{
	int maPin;
	cout << "\t\tNhap Ma Pin: ";
	cin >> maPin;
	return maPin;
}
int BanPhim::setgetMaThe()
{
	int maThe;
	cout << "\n\n\n\n\t\tNhap Ma Tai Khoan: ";
	cin >> maThe;
	return maThe;
}
int BanPhim::setgetLuaChon()
{
	int luaChon;
	cout << "Nhap Lua Chon: ";
	cin >> luaChon;
	return luaChon;
}
void ManHinh::tb()
{
	cout << "\n\n\n";
	cout<<"                ----------------------------------------------------"<<endl;
	cout<<"                |                    CHU Y!!!                       |"<<endl;
	cout<<"                ----------------------------------------------------"<<endl<<endl;
	
	cout<<"                +---------------------------------------------------+"<<endl;
	cout<<"                +    ATM Rut Tien Tren Thuat Toan Lay Ngau Nhien    +"<<endl;
	cout<<"                +         Cac Menh Gia Tu Lon Den Be!!!!            +"<<endl;
	cout<<"                +                                                   +"<<endl;
	cout<<"                +           ENTER De Bat Dau Giao Dich!^^           +"<<endl;
	cout<<"                +---------------------------------------------------+"<<endl;
	char c = getch();
}
