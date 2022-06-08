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
class CuocThi
{
private:
    /* data */
    string ten;
    string ThoiGianToChuc;
    Type HinhThuc;
    string DonViToChuc;
    vector<DoiChoi> CacDoiThamGia;
    vector<BaiThi> DanhSachBaiThi;
    size_t ThanhVienToiDa;
    size_t SoLuongDangKi;


public:
    CuocThi(/* args */);
    void Nhap();
    void Xuat() const;
    void DangKiThanhVien();
    void DangKiDoiChoi();
    DoiChoi QuanQuan() const;
    void Top3() const;
    NguoiRaDe ItGiaiDuocNhat() const;
    
    ~CuocThi();
};




#endif