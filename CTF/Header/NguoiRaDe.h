#ifndef _NGUOI_RA_DE_H
#define _NGUOI_RA_DE_H
#include "Nguoi.h"
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

#endif