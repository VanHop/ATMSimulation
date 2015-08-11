#include "Tien.h"
#include "TaiKhoan.h"
#include <iostream>
#include <conio.h>
using namespace std;
Tien::Tien(){}
void Tien::chuyenTien(TaiKhoan nguoiDung[],int i,int tien,int duLieu[])
{
	duLieu[4*i+3] = nguoiDung[i].getSoDu() - tien;
	nguoiDung[i].setSoDu(4*i+3);
}
