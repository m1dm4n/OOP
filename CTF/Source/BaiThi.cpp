#ifndef _BAI_THI_CPP
#define _BAI_THI_CPP
#include "BaiThi.h"
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;


size_t BaiThi::GetDiem() const { return Diem; }
void BaiThi::Nhap()
{
    cout << "\n**************** Challenge information ****************\n";
    string tmp;
    fflush(stdin);
    cout << "Nhap ten Challenge: ";
    getline(cin, TenBai);
    int choice;
    cout << "(1. Web, 2. Cryptography, 3. Reverse Engineering, 4. Pwnable, 5. Programming, 6. Forensic, 7. Miscellaneous)"
            "Chu de: ";
    cin >> choice;
    ChuDe = Category(choice);
    cout << "So diem: ";
    cin >> Diem;
    fflush(stdin);
    cout << "Tai Nguyen kem theo: \n";
    while (getline(cin, tmp))
        TaiNguyen.push_back(tmp); // This is to input the sentence
    cout << "Goi y: ";
    getline(cin, GoiY);
    cout << "Dap An: ";
    getline(cin, DapAn);
    TacGia = new NguoiRaDe();
    TacGia->Nhap();
}
void BaiThi::Xuat() const
{
    cout << "\n----- Thong tin cua " << TenBai << " -----";
    cout << "\n   [+] Chu de: ";
    PrintCategory(ChuDe);
    cout << "\n   [+] So diem: " << Diem;
    cout << "\n   [+] So nguoi giai: " << SoNguoiGiai;
    cout << "\n   [+] Tai Nguyen kem theo: \n";
    for (size_t i = 0; i < TaiNguyen.size(); ++i)
        cout << "            " << i << ". " << TaiNguyen[i] << '\n'; // This is to input the sentence
    cout << "   [+] Goi y: " << GoiY;
    cout << "\n   [+] Dap An: " << DapAn;
    TacGia->Xuat();
    cout << endl;
}
void BaiThi::solved()
{
    this->SoNguoiGiai += 1;
}
#endif
