// TaiKhoan.h
#ifndef TaiKhoan_H
#define TaiKhoan_H
// lop quan ly doi tuong tai khoan ca nhan
class TaiKhoan
{
    public:
        TaiKhoan();
        int duLieu[1000];
        int soTaiKhoan;
        void setMaPin(int);
        void setMaThe(int);
        void setSoDu(int);
        void setSoLanNhapSai(int);
        void setDuLieu(int,int);
        int getMaPin();
        int getMaThe();
        int getSoLanNhapSai();
        int getSoDu();
        bool kiemTraMaPIN(int, int, int &);
        bool kiemTraSoDu(int);
        void rutTien();
        int getSoTaiKhoan();
        int laySoTaiKhoan();
        //int getDuLieu(int i)
//        {
//			return DuLieu[i];
//		}
    private:
		int maPin, maThe, soLanNhapSai, soDu;
		int *nguoiDung;
};
#endif // TaiKhoan_H
