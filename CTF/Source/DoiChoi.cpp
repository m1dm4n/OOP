#ifndef _DOI_CHOI_CPP
#define _DOI_CHOI_CPP
#include "DoiChoi.h"
using std::cin;
using std::cout;
using std::endl;

DoiChoi::DoiChoi(string ten, vector<NguoiChoi *> tv, Rank type, size_t max)
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
bool DoiChoi::KiemTraToiDaTV() const
{
    return this->ThanhVien.size() >= this->TVToiDa;
}
void DoiChoi::Xuat() const
{
    cout << "\n----- Thong tin cua " << Ten << " -----";
    for (size_t i = 0; i < ThanhVien.size(); ++i)
    {
        ThanhVien[i]->Xuat();
        cout << endl;
    }
}
void DoiChoi::ThemThanhViem(NguoiChoi *nguoi)
{
    if (!this->KiemTraToiDaTV())
        this->ThanhVien.push_back(nguoi);
}
void DoiChoi::Giai1Bai(BaiThi &chall, const uint32_t &t)
{
    chall.solved();
    this->CacBaiDaLam.push_back(chall);
    this->Diem += chall.GetDiem();
    this->ThoiGian += t;
}

bool DoiChoi::operator<(const DoiChoi &other) const
{
    if (this->Diem * int(this->HangMuc) == other.Diem * int(other.HangMuc))
        return this->ThoiGian < other.ThoiGian;
    return (this->Diem * int(this->HangMuc) < other.Diem * int(other.HangMuc));
}
bool DoiChoi::operator>(const DoiChoi &other) const
{
    if (this->Diem * int(this->HangMuc) == other.Diem * int(other.HangMuc))
        return this->ThoiGian > other.ThoiGian;
    return (this->Diem * int(this->HangMuc) > other.Diem * int(other.HangMuc));
}

#endif