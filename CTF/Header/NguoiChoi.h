#ifndef _NGUOI_CHOI_H
#define _NGUOI_CHOI_H
#include "Nguoi.h"


class NguoiChoi : public Nguoi
{
    string Lop;

public:
    NguoiChoi(/* args */) {}
    NguoiChoi(const string &_hoten, const string &_email, const string &_lop) : Nguoi(_hoten, _email), Lop(_lop) {}
    void Nhap();
    void Xuat() const;
    ~NguoiChoi() {}
};

#endif