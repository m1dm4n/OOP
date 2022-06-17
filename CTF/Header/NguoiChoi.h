#ifndef _NGUOI_CHOI_H
#define _NGUOI_CHOI_H
#include "Nguoi.h"


class NguoiChoi : public Nguoi
{
    string Lop;

public:
    NguoiChoi(/* args */) {}
    void Nhap();
    void Xuat() const;
    ~NguoiChoi() {}
};

#endif