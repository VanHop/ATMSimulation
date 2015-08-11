// DuLieuNganHang.h
#ifndef DuLieuNganHang_H
#define DuLieuNganHang_H

// lop quan ly du lieu ngan hang
// viec tiem kiem tai khoan ca nhan can thuc hien thong qua lop nay
// luu tru & tim kiem cac giao dich doi voi tai khoan cung su dung lop nay

class DuLieuNganHang
{
    public:
        DuLieuNganHang();
        bool kiemTraMaPIN();
        bool kiemTraSoDu();
        void rutTien();
        void setLaiDuLieuNganHang(int duLieu[],int soTaiKhoan);
    private:
};

#endif // DuLieuNganHang_H
