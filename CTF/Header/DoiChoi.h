#ifndef _DOI_CHOI_H
#define _DOI_CHOI_H

#include "NguoiChoi.h"
#include "BaiThi.h"
#include <vector>
#include <iostream>

using std::vector;
using std::string;

enum class Rank
{
    Junior,
    Intermediate,
    Senior
};
void PrintRank(Rank c)
{
    switch (c)
    {
    case Rank::Junior:
        cout << "Junior";
        break;
    case Rank::Intermediate:
        cout << "Intermediate";
        break;
    case Rank::Senior:
        cout << "Senior";
        break;
    default:
        cout << "Unknown rank!";
    }
}
class DoiChoi
{
private:
    /* data */
    size_t SoTV;
    string Ten;
    vector<NguoiChoi *> ThanhVien;
    Rank HangMuc;
    size_t TVToiDa;
    uint32_t Diem;
    vector<BaiThi> CacBaiDaLam;
    uint32_t ThoiGian;

public:
    DoiChoi(/* args */) : SoTV(0), TVToiDa(1) {} // Mac dinh la thi ca nhan
    DoiChoi(string ten, vector<NguoiChoi *> tv, Rank type, size_t max) 
    {
        this->Ten = ten;
        this->HangMuc = type;
        this->TVToiDa = max;
        this->SoTV = (tv.size() > max ? max : tv.size());
        for (size_t i = 0; i < SoTV; ++i)
            ThanhVien.push_back(tv[i]);
        this->Diem = 0;
        this->ThoiGian = 0;
    }
    void Xuat() const;
    bool KiemTraToiDaTV() const;
    void ThemThanhViem(NguoiChoi *);
    void Giai1Bai(BaiThi &, const uint32_t &);
    bool operator<(const DoiChoi &) const;
    bool operator>(const DoiChoi &) const;
    friend class CuocThi;
    ~DoiChoi() {}
};

#endif