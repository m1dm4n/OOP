#include "Header/CuocThi.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Nhap so luong cuoc thi trong nam qua: ";
    cin >> n;
    vector<CuocThi *>UIT(n, nullptr);
    for (size_t i = 0; i < UIT.size(); ++i)
    {
        UIT[i] = new CuocThi;
        UIT[i]->Nhap();
    }
    for (size_t i = 0; i < UIT.size(); ++i)
    {
        UIT[i]->Xuat();
    }
    return 0;
}