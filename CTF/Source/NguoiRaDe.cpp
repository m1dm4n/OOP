#ifndef _NGUOI_RA_DE_CPP
#define _NGUOI_RA_DE_CPP
#include "NguoiRaDe.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;

void NguoiRaDe::Nhap()
{
    int choice;
    cout << "(1. Web, 2. Cryptography, 3. Reverse Engineering, 4. Pwnable, 5. Programming, 6. Forensic, 7. Miscellaneous)"
            "Chu de: ";
    cin >> choice;
    ChuyenMon = Category(choice);
}
void NguoiRaDe::Xuat() const
{
    cout << "\n   [+] Chuyen mon: ";
    PrintCategory(ChuyenMon);
}
#endif