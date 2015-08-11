// GiaoDich.h
#ifndef GiaoDich_H
#define GiaoDich_H
#include "TaiKhoan.h"
#include <iostream>
#include <vector>
// lop dinh nghia cac giao dich 
using namespace std;
class GiaoDich
{
    public:
        GiaoDich();
        vector<string>LuuGiaoDich;
        void rutTien(TaiKhoan [],int);
        void luuGiaoDich(int,float);
        void luuGiaoDich(int,int);
        void layHopTien();
        bool kiemTraHopTien(int);
        void backHopTien();
        void luuTamHopTien();
        void setLaiHopTien();
        void chuyenTien(TaiKhoan [],int);
        void thanhToanDienNuoc(TaiKhoan [],int);
        void thanhToanDienThoai(TaiKhoan [],int);
        void muaTheDienThoai(TaiKhoan [], int);
        void thongTin(TaiKhoan [], int);
        void doiMaPin(TaiKhoan [],int);
        void inHoaDon(TaiKhoan [],int);
        void rutTienTrongHop(TaiKhoan [],int,int,int,float);
    private:
		int hopTien[10];
		int hopTamTien[10];
};
#endif // GiaoDich_H
