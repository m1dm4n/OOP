#include "Header/CuocThi.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Nhap so luong cuoc thi trong nam qua: ";
    cin >> n;
    vector<CuocThi>UIT(n);
    for (size_t i = 0; i < UIT.size(); ++i)
    {
        UIT[i].Nhap();
    }
    for (size_t i = 0; i < UIT.size(); ++i)
    {
        UIT[i].Xuat();
    }
    for (size_t i = 0; i < UIT.size(); ++i)
    {
        UIT[i].ManhNhieuBaiNhat();
    }
    for (size_t i = 0; i < UIT.size(); ++i)
    {
        cout << "Quan quan cua
        UIT[i].QuanQuan().Xuat();
    }
    for (size_t i = 0; i < UIT.size(); ++i)
    {
        UIT[i].Top3();
    }
    return 0;
}