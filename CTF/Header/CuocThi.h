#ifndef _CUOC_THI_H
#define _CUOC_THI_H
#include "BaiThi.h"
#include "DoiChoi.h"
#include "NguoiRaDe.h"
#include <iostream>
#include <vector>
using std::string;
using std::vector;
enum class Type
{
    Jeopardy, Attack_Defense, Mix
};
void PrintType(Type c)
{
    switch (c)
    {
    case Type::Jeopardy:
        cout << "Jeopardy";
        break;
    case Type::Attack_Defense:
        cout << "Attack_Defense";
        break;
    case Type::Mix:
        cout << "Mix";
        break;
    default:
        cout << "Unknown rank!";
    }
}
class CuocThi
{
private:
    /* data */
    string ten;
    string ThoiGianToChuc;
    Type HinhThuc;
    string DonViToChuc;
    size_t ThanhVienToiDa;
    vector<DoiChoi> CacDoiThamGia;
    vector<BaiThi> DanhSachBaiThi;
    size_t SoLuongDangKi;


public:
    CuocThi(/* args */){}
    void Nhap();
    void Xuat() const;
    NguoiChoi* DangKyThanhVien();
    void DangKyDoiChoi();
    DoiChoi QuanQuan() const;
    void Top3() const;
    void ManhNhieuBaiNhat() const;
    NguoiRaDe ItGiaiDuocNhat() const;
    BaiThi *TimBaiThi(const string &);
    NguoiRaDe* TimBaiThiItNhat() const;
    ~CuocThi(){}
};




#endif