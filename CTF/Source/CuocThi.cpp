#ifndef _CUOC_THI_CPP
#define _CUOC_THI_CPP
#include "CuocThi.h"
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

void CuocThi::Nhap()
{
    fflush(stdin);
    cout << "\n**************** Tao 1 cuoc thi ****************\n";
    cout << "Nhap ten: ";
    getline(cin, ten);
    cout << "Thoi gian to chuc: ";
    getline(cin, ThoiGianToChuc);
    int choice;
    cout << "(1. Jeopardy, 2. Attack Defense, 3. Mix)"
            "Hang muc: ";
    cin >> choice;
    HinhThuc = Type(choice);
    size_t n;
    cout << "Nhap so luong bai thi: ";
    cin >> n;
    for (size_t i = 0; i < n; ++i)
        DanhSachBaiThi[i].Nhap();
    cout << "Nhap so doi tham gia: ";
    cin >> n;
    for (size_t i = 0; i < n; ++i)
        DangKyDoiChoi();
    cout << "\n**************** Ket thuc ****************\n";
}

void CuocThi::Xuat() const
{
    cout << "\n**************** Thong tin cua cuoc thi << " << this->ten << " ****************";
    cout << "\nThoi gian to chuc: " << ThoiGianToChuc;
    cout << "\nHang muc: ";
    PrintType(HinhThuc);
    cout << "Danh sac cac bai thi: ";
    for (size_t i = 0; i < DanhSachBaiThi.size(); ++i)
        DanhSachBaiThi[i].Xuat();
    cout << "Danh sac cac doi tham gia: ";
    for (size_t i = 0; i < CacDoiThamGia.size(); ++i)
        CacDoiThamGia[i].Xuat();
    cout << "\n**************** Ket thuc ****************\n";
}

NguoiChoi *CuocThi::DangKyThanhVien()
{
    NguoiChoi *tmp = new NguoiChoi();
    tmp->Nhap();
    return tmp;
}
void CuocThi::DangKyDoiChoi()
{
    fflush(stdin);
    Rank r;
    int choice;
    size_t n;
    string ten;
    vector<NguoiChoi *> tv;
    vector<BaiThi> solve;
    cout << "Nhap ten: ";
    getline(cin, ten);
    cout << "(1. Junior, 2. Intermediate, 3. Senior)"
            "Hang muc: ";
    cin >> choice;
    r = Rank(choice);
    cout << "Nhap hinh thuc tham gia (1. Ca nhan, 2. Dong doi): ";
    cin >> choice;
    ThanhVienToiDa = choice ? 4 : 1;
    if (choice > 1)
        do
        {
            cout << "Nhap so luong thanh vien:";
            cin >> n;
        } while (n <= 0 || n > ThanhVienToiDa);
    tv.resize(n);
    for (size_t i = 0; i < n; ++i)
        tv[i]->Nhap();
    DoiChoi cur = DoiChoi(ten, tv, r, ThanhVienToiDa);
    cout << "Nhap so bai da giai duoc: ";
    cin >> n;
    string name;
    fflush(stdin);
    for (size_t i = 0; i < n; ++i)
    {
        cout << "Nhap ten bai: ";
        getline(cin, name);
        cout << "Nhap thoi gian giai: ";
        cin >> choice;
        BaiThi *chall = TimBaiThi(name);
        if (chall == nullptr)
        {
            cout << "Khong tim thay chall!";
            i -= 1;
            continue;
        }
        cur.Giai1Bai(*chall, choice);
    }
    CacDoiThamGia.push_back(cur);
}
BaiThi *CuocThi::TimBaiThi(const string &name)
{
    for (size_t i = 0; i < DanhSachBaiThi.size(); ++i)
        if (DanhSachBaiThi[i].TenBai == name)
            return &DanhSachBaiThi[i];
    return nullptr;
}

DoiChoi CuocThi::QuanQuan() const
{
    DoiChoi winner = CacDoiThamGia[0];
    for (size_t i = 1; i < CacDoiThamGia.size(); ++i)
        if (CacDoiThamGia[i] > winner)
            winner = CacDoiThamGia[i];
    return winner;
}
void CuocThi::ManhNhieuBaiNhat() const
{
    std::pair<Category, int> arr[7];
    arr[0].first = Category::Web;
    arr[1].first = Category::Cryptography;
    arr[2].first = Category::Reverse_Engineering;
    arr[3].first = Category::PWN;
    arr[4].first = Category::Programming;
    arr[5].first = Category::Forensic;
    arr[6].first = Category::Miscellaneous;
    for (size_t i = 0; i < DanhSachBaiThi.size(); ++i)
    {
        for (size_t j = 0; j < 7; ++j)
            if (DanhSachBaiThi[i].ChuDe == arr[j].first)
                arr[j].second++;
    }
    sort(arr, arr + 7, [](const std::pair<Category, int> &a, const std::pair<Category, int> &b)
         { return a.second > b.second; });
    cout << "Mang co nhieu bai thi nhat: ";
    PrintCategory(arr[0].first);
    cout << endl;
}
void CuocThi::Top3() const
{
    vector<DoiChoi> tmp = this->CacDoiThamGia;
    sort(tmp.begin(), tmp.end(), [](const DoiChoi &a, const DoiChoi &b)
         { return a.CacBaiDaLam.size() > b.CacBaiDaLam.size(); });
    size_t n = (tmp.size() > 3 ? 3 : tmp.size());
    cout << "[*] Top 3 doi giai nhieu nhat cua cuoc thi " << ten << '\n';
    for (size_t i = 0; i < n; ++i)
        tmp[i].Xuat();
    cout << endl;
}
NguoiRaDe* CuocThi::TimBaiThiItNhat() const
{
    size_t lonnhat = 0;
    NguoiRaDe *ans = nullptr;
    for (size_t i = 0; i < DanhSachBaiThi.size(); ++i)
        if (DanhSachBaiThi[i].SoNguoiGiai > lonnhat)
        {
            ans = DanhSachBaiThi[i].TacGia;
            lonnhat = DanhSachBaiThi[i].SoNguoiGiai;
        }
    return ans;
}
#endif