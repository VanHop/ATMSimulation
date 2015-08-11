#include "TaiKhoan.h"
#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
TaiKhoan::TaiKhoan()
{
	soTaiKhoan = laySoTaiKhoan();
	maPin=0, maThe=0, soLanNhapSai = 0, soDu = 0;
}
bool TaiKhoan::kiemTraMaPIN(int maTk, int maPin,int &th)
{
	if (getMaPin()==maPin&&getMaThe()==maTk)
		return true;
	if (getMaPin()!=maPin&&getMaThe()==maTk)
	{
		fstream input;
		input.open("ThongTinKhachHang.txt");
		int k=0;
		for (k=0;k<soTaiKhoan;k=k+4)
		{
			if (duLieu[k+1]==maThe)
				break;
		}
		setDuLieu(k,-1);
		setSoLanNhapSai(k);
		for (int i=0;i<soTaiKhoan*4;i++)
			input << duLieu[i] << endl;
		input.close();
		th=1;
		return false;
	}
	return false;
}
bool TaiKhoan::kiemTraSoDu(int tien)
{
	if (soDu>=tien)
		return true;
	return false;
}
//void TaiKhoan::rutTien();
int TaiKhoan::laySoTaiKhoan()
{
	ifstream input;
	input.open("ThongTinKhachHang.txt");
	int i=0, k;
	while(!input.eof())
	{
		input >> duLieu[i];
		i++;
	}
	input.close();
	return i/4;
}
void TaiKhoan::setMaPin(int i)
{
	maPin = duLieu[i];
}
void TaiKhoan::setMaThe(int i)
{
	maThe = duLieu[i];
}
void TaiKhoan::setSoDu(int i)
{
	soDu = duLieu[i];
}
void TaiKhoan::setSoLanNhapSai(int i)
{
	soLanNhapSai = duLieu[i];
}
int TaiKhoan::getSoTaiKhoan()
{
	return soTaiKhoan;
}
int TaiKhoan::getMaPin()
{
	return maPin;
}
int TaiKhoan::getMaThe()
{
	return maThe;
}
int TaiKhoan::getSoDu()
{
	return soDu;
}
int TaiKhoan::getSoLanNhapSai()
{
	return soLanNhapSai;
}
void TaiKhoan::setDuLieu(int i,int k)
{
	duLieu[i] = duLieu[i] - k;
}
