#include "DuLieuNganHang.h"
#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
DuLieuNganHang::DuLieuNganHang(){};
void DuLieuNganHang::setLaiDuLieuNganHang(int duLieu[],int soTaiKhoan)
{
	ofstream input;
	input.open("ThongTinKhachHang.txt");
	int i=0;
	while(i<soTaiKhoan*4)
	{
		input << duLieu[i] << endl;
		i++;
	}
	input.close();
}
