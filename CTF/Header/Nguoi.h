#ifndef _NGUOI_H
#define _NGUOI_H

#include <iostream>
using std::string;

class Nguoi
{
protected:
    /* data */
    string HoTen;
    string Email;

public:
    Nguoi(/* args */) {}
    Nguoi(const string &_hoten, const string &_email) : HoTen(_hoten), Email(_email) {}
    string GetHoTen() const;
    virtual void Nhap();
    virtual void Xuat() const;
    virtual ~Nguoi() {}
};




#endif