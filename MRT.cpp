// MRT.cpp
#include "MRT.h"
#include <conio.h>
#include "PhanCung.h"
#include "DuLieuNganHang.h"
#include "PhanCung.h"
#include <windows.h>
#include <iostream>

MRT::MRT()
{
}

void MRT::chay()
{
    while (true)
    {
		ManHinh manHinh;
		manHinh.tb();
        std::cout << "May Dang Chay.....\n";
        Sleep(1000);
        manHinh.hienThi();
        getch();
    }
}
