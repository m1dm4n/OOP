#ifndef _NGUOI_CHOI_CPP
#define _NGUOI_CHOI_CPP
#include "NguoiChoi.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;

void NguoiChoi::Nhap()
{
    fflush(stdin);
    cout << "Nhap lop: ";
    getline(cin, Lop);
}
void NguoiChoi::Xuat() const
{
    cout << "\n   [+] Lop hoc: " << Lop;
}
#endif