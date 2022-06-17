#ifndef _NGUOI_CPP
#define _NGUOI_CPP
#include "Nguoi.h"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

void Nguoi::Nhap()
{
    fflush(stdin);
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap email: ";
    getline(cin, Email);
}
void Nguoi::Xuat() const
{
    cout << "\n   [+] " << HoTen << ", email: " << Email << "\n";
}
#endif