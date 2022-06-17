#pragma once
#include "Nguoi.h"
using std::cout;
enum class Category
{
    Web,
    Cryptography,
    Reverse_Engineering,
    PWN,
    Programming,
    Forensic,
    Miscellaneous
};
void PrintCategory(Category c)
{
    switch (c)
    {
        case Category::Web:
            cout << "Web";
            break;
        case Category::Cryptography:
            cout << "Cryptography";
            break;
        case Category::Reverse_Engineering:
            cout << "Reverse_Engineering";
            break;
        case Category::PWN:
            cout << "Pwnable";
            break;
        case Category::Programming:
            cout << "Programming";
            break;
        case Category::Forensic:
            cout << "Forensic";
            break;
        case Category::Miscellaneous:
            cout << "Miscellaneous";
            break;
        default:
            cout << "Unknown category!";
    }
}
class NguoiRaDe : public Nguoi
{
    Category ChuyenMon;

public:
    NguoiRaDe(/* args */) {}
    NguoiRaDe(const string &_hoten, const string &_email, const Category &_chuyenmon) : Nguoi(_hoten, _email), ChuyenMon(_chuyenmon) {}
    void Nhap();
    void Xuat() const;
    ~NguoiRaDe() {}
};

