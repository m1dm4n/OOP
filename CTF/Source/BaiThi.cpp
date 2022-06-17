#include "BaiThi.h"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

void BaiThi::Nhap()
{
    int choice;
    fflush(stdin);
    cout << "Nhap ten Challenge: ";
    getline(cin, TenBai);
    cout << "Chu de "
    "(Web, Cryptography, Reverse_Engineering, PWN, Programming, Forensic,Miscellaneous): ";
    cin >> choice;
    ChuDe = Category(choice);
    Category c = Category::PWN;

}
