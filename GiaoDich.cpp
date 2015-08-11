#include "TaiKhoan.h"
#include "PhanCung.h"
#include "DuLieuNganHang.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include "GiaoDich.h"
#include "Tien.h"
#include "HoaDon.h"
using namespace std;
GiaoDich::GiaoDich(){};
void GiaoDich::rutTien(TaiKhoan nguoiDung[],int i)
{
	float d = 1.0;
	int tien1, tien, k;
	layHopTien();
	cout << "So tien can rut: ";
	cin >> tien1;
	rutTienTrongHop(nguoiDung,i,tien,tien1,d);
}
void GiaoDich::chuyenTien(TaiKhoan nguoiDung[],int i)
{
	int tien, maThe, m = 0, k;
	TaiKhoan a;
	DuLieuNganHang p;
	Tien set;
	cout << "Nhap Ma The Muon Chuyen: ";
	cin >> maThe;
	for (k=0;k<a.soTaiKhoan;k++)
	{
		m=4*k+1;
		if (a.duLieu[m] == maThe)
		{
			cout << "Nhap So Tien Muon Chuyen: ";
			cin >> tien;
			if(nguoiDung[i].kiemTraSoDu(tien)==true)
			{
				set.chuyenTien(nguoiDung,i,tien,a.duLieu);
				set.chuyenTien(nguoiDung,k,-tien,a.duLieu);
				p.setLaiDuLieuNganHang(a.duLieu,a.soTaiKhoan);
				luuGiaoDich(tien,maThe);
				cout << "Dang Giao Dich";
				for (int j=0;j<3;j++)
					cout << ".\a";
				cout << "\nThanh Cong !^^";
				break;
			}
			else
			{
				cout << "So Tien Trong Tai Khoan Khong Du De Chuyen!^^\nHoac Trong Hop Tien Da Het\nHoac Khong Co Menh Gia Phu Hop\n";
				Sleep(3000);
				break;
			}
		}
	}
	if (k==a.soTaiKhoan)
	{
		cout << "Khong Co Du Lieu!^^";
		Sleep(3000);
	}
}
void GiaoDich::layHopTien()
{
	ifstream input;
	input.open("HopTien.txt");
	int i=0;
	while(!input.eof())
	{
		input >> hopTien[i];
		i++;
	}
	input.close();
}
bool GiaoDich::kiemTraHopTien(int tien)
{
	int tong = 0;
	for (int i=0;i<8;i=i+2)
		tong += hopTien[i]*hopTien[i+1];
	if (tong >= tien)
		return true;
	else
		return false;
}
void GiaoDich::backHopTien()
{
	for (int i=0;i<10;i++)
		hopTien[i] = hopTamTien[i];
}
void GiaoDich::luuTamHopTien()
{
	for (int i=0;i<10;i++)
		hopTamTien[i] = hopTien[i];
}
void GiaoDich::setLaiHopTien()
{
	ofstream input;
	input.open("HopTien.txt");
	int i=0;
	while(i<10)
	{
		input << hopTien[i] << endl;
		i++;
	}
	input.close();
}
void GiaoDich::luuGiaoDich(int tien,float d)
{
	char tam[20];
	itoa(tien,tam,10);
	string b, a;
	a=tam;
	if (d==1.0)
		LuuGiaoDich.push_back("Ban Da Rut " + a + " USD !^^");
	if (d==2.0)
		LuuGiaoDich.push_back("Ban Da Thanh Toan " + a + " USD Tien Dien Nuoc !^^");
	if (d==3.0)
		LuuGiaoDich.push_back("Ban Da Thanh Toan " + a + " USD Tien Dien Thoai !^^");
	if (d==4.0)
		LuuGiaoDich.push_back("Ban Da Mua " + a + " USD Tien The Dien Thoai Tra Truoc !^^");
	if (d==5.0)
		LuuGiaoDich.push_back("Ban Da Doi Ma Pin Thanh " +a+ " !^^");
}
void GiaoDich::luuGiaoDich(int tien,int maThe)
{
	char Tien[20], MaThe[20];
	itoa(tien,Tien,10);
	itoa(maThe,MaThe,10);
	string a, b;
	a = Tien;
	b = MaThe;
	LuuGiaoDich.push_back("Ban Da Chuyen " + a + " USD Vao Tai Khoan " + b + " !^^");
}
void GiaoDich::thanhToanDienNuoc(TaiKhoan nguoiDung[],int i)
{
	float d = 2.0;
	int tien,tien1;
	layHopTien();
	cout << "Nhap So Tien Can Thanh Toan: ";
	cin >> tien1;
	rutTienTrongHop(nguoiDung,i,tien,tien1,d);
}
void GiaoDich::thanhToanDienThoai(TaiKhoan nguoiDung[],int i)
{
	int tien,tien1;
	float d = 3.0;
	layHopTien();
	cout << "Nhap So Tien Can Thanh Toan: ";
	cin >> tien1;
	rutTienTrongHop(nguoiDung,i,tien,tien1,d);
}
void GiaoDich::muaTheDienThoai(TaiKhoan nguoiDung[],int i)
{
	int tien,tien1;
	float d = 4.0;
	layHopTien();
	cout << "Nhap So Tien The Can Mua: ";
	cin >> tien1;
	rutTienTrongHop(nguoiDung,i,tien,tien1,d);
}
void GiaoDich::thongTin(TaiKhoan nguoiDung[],int i)
{
	cout << "Ma Tai Khoan: " << nguoiDung[i].getMaThe() << endl
		 << "Ma Pin:       " << nguoiDung[i].getMaPin() << endl
		 << "So Du:        " << nguoiDung[i].getSoDu() << endl;
	char c=getch();
}
void GiaoDich::doiMaPin(TaiKhoan nguoiDung[],int i)
{
	float d=5.0;
	TaiKhoan a;
	DuLieuNganHang p;
	int pin1,pin2;
	lai:
	cout << "Nhap Ma Pin Can Chuyen: ";
	cin >> pin1;
	cout << "Nhap Lai Ma Pin: ";
	cin >> pin2;
	if (pin1!=pin2)
		goto lai;
	else
	{
		a.duLieu[2*i+2*(i+1)] = pin1;
		nguoiDung[i].setMaPin(i+(i+1)*2);
		p.setLaiDuLieuNganHang(a.duLieu,a.soTaiKhoan);
		cout << "Thay Doi Thanh Cong!^^";
		luuGiaoDich(pin1,d);
		Sleep(3000);
	}
}
void GiaoDich::inHoaDon(TaiKhoan nguoiDung[],int i)
{
	char tenNguoiDung[30];
	int name = nguoiDung[i].getMaThe();
	itoa(name,tenNguoiDung,10);
	int u = strlen(tenNguoiDung);
	tenNguoiDung[u]='.';
	tenNguoiDung[u+1]='t';
	tenNguoiDung[u+2]='x';
	tenNguoiDung[u+3]='t';
	ofstream out;
	out.open(tenNguoiDung);
	int k = LuuGiaoDich.size()-1, m;
	if (k>=5)
		m = k - 5;
	else
		m = -1;
	for (;k>m;k--)
		out << LuuGiaoDich[k] << endl;
	cout << "\nDang in";
	for (int j=0;j<3;j++)
	{
		cout <<".\a";
		Sleep(500);
	}
	cout << "\nIn Thanh Cong !^^";
	Sleep(3000);
	out.close();
}
void GiaoDich::rutTienTrongHop(TaiKhoan nguoiDung[],int i,int tien,int tien1,float d)
{
	int h=0;
	srand(time(NULL));
	TaiKhoan a;
	DuLieuNganHang p;
	if (nguoiDung[i].getSoDu()>=tien1&&kiemTraHopTien(tien1)==true)
	{
		for (int k=0;k<1000000;k++)
		{
			luuTamHopTien();
			backHopTien();
			tien = tien1;
			int mG1 = 0, mG2 = 0, mG3 = 0, mG4 = 0, mG5 = 0, i=0;
			if (tien/hopTamTien[i+1]<=hopTamTien[i]&&tien!=0)
			{
				mG1 = rand() % (tien/hopTamTien[i+1] +1 );
				hopTamTien[i] = hopTamTien[i] - mG1;
				tien -= mG1 * hopTamTien[i+1];
			}
			if (tien/hopTamTien[i+3]<=hopTamTien[i+2]&&tien!=0)
			{
				mG2 = rand() % (tien/hopTamTien[i+3]+1);
				hopTamTien[i+2] = hopTamTien[i+2] - mG2;
				tien -= mG2 * hopTamTien[i+3];
			}
			if (tien/hopTien[i+5]<=hopTamTien[i+4]&&tien!=0)
			{
				mG3 = rand() % (tien/hopTamTien[i+5]+1);
				hopTamTien[i+4] = hopTamTien[i+4] - mG3;
				tien -= mG3 * hopTamTien[i+5];
			}
			if (tien/hopTamTien[i+7]<=hopTamTien[i+6]&&tien!=0)
			{
				mG4 = rand() % (tien/hopTamTien[i+7]+1);
				hopTamTien[i+6] = hopTamTien[i+6] - mG4;
				tien -= mG4 * hopTamTien[i+7];
			}
			if (tien/hopTamTien[i+9]<=hopTamTien[i+8]&&tien!=0)
			{
				mG5 = rand() % (tien/hopTamTien[i+9]+1);
				hopTamTien[i+8] = hopTamTien[i+8] - mG5;
				tien -= mG5 * hopTamTien[i+9];
			}
			if (tien==0)
			{
				hopTien[i] = hopTien[i] - mG1;
				hopTien[i+2] = hopTien[i+2] - mG2;
				hopTien[i+4] = hopTien[i+4] - mG3;
				hopTien[i+6] = hopTien[i+6] - mG4;
				hopTien[i+8] = hopTien[i+8] - mG5;
				setLaiHopTien();
				h=1;
				break;
			}
		}
		if (h==1)
		{
			cout << "Thanh Cong !^^\n";
			nguoiDung[i].setDuLieu(i+((i+1)*3),tien1);
			nguoiDung[i].setSoDu(i+(i+1)*3);
			a.duLieu[i+(i+1)*3] = nguoiDung[i].getSoDu();
			p.setLaiDuLieuNganHang(a.duLieu,a.soTaiKhoan);
			luuGiaoDich(tien1,d);
		}
		else
			cout << "So Tien Trong Tai Khoan Khong Du De Thanh Toan!^^\nHoac Trong Hop Tien Da Het\nHoac Khong Co Menh Gia Phu Hop";
	}
	else
		cout << "So Tien Trong Tai Khoan Khong Du De Thanh Toan!^^\nHoac Trong Hop Tien Da Het\nHoac Khong Co Menh Gia Phu Hop";
	Sleep(3000);
}
