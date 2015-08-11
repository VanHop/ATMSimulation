// Tien.h
#ifndef Tien_H
#define Tien_H
#include "TaiKhoan.h"
#include <iostream>
using namespace std;
 //lop nay dinh nghia doi tuong Tien & cac toan tu nap chong lien quan
 //cac ham o day chi la goi y, can khai bao va dinh nghia chinh xac hon
 //can dinh 8nghia day du cac ham khoi tao phuc vu cho chuyen doi kieu tu dong
class Tien
{
    public:
        Tien();
        void chuyenTien(TaiKhoan nguoiDung[],int i,int tien,int DuLieu[]);
        //friend const Tien& operator+ ();
        //friend const Tien& operator- ();
        //friend const Tien& operator* ();
        //friend const Tien& operator/ ();
        //friend const int operator/ ();
    private:
};
#endif // Tien_H
