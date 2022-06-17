#ifndef _BAI_THI_H
#define _BAI_THI_H
#include "NguoiRaDe.h"
#include <iostream>
#include <vector>
using std::string;
using std::vector;

class BaiThi
{
    string TenBai;
    Category ChuDe;
    size_t Diem;
    size_t SoNguoiGiai;
    vector<string> TaiNguyen;
    string GoiY;
    string DapAn;
    NguoiRaDe *TacGia;

public:
    BaiThi(/* args */) {}
    void Nhap();
    void Xuat() const;
    // string GetTenBai() const;
    // Category GetChuDe() const;
    // size_t GetSoNguoiGiai() const;
    void solved();
    size_t GetDiem() const;
    friend class CuocThi;
    ~BaiThi() {}
};

#endif