#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    double luongCoBan;
    double heSo;
};

void nhapNhanVien(NhanVien &nv) {
    cout << "Nhap ma nhan vien: ";
    getline(cin, nv.maNV);
    cout << "Nhap ten nhan vien: ";
    getline(cin, nv.tenNV);
    cout << "Nhap luong co ban: ";
    cin >> nv.luongCoBan;
    cout << "Nhap he so luong: ";
    cin >> nv.heSo;
    cin.ignore(); 
}

void xuatNhanVien(const NhanVien &nv) {
    cout << left << setw(12) << nv.maNV 
         << setw(25) << nv.tenNV 
         << setw(18) << fixed << setprecision(0) << nv.luongCoBan 
         << setw(10) << setprecision(2) << nv.heSo << endl;
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); 
    
    vector<NhanVien> dsNV(n);
    cout << "\n=== NHAP THONG TIN NHAN VIEN ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien thu " << i + 1 << ":\n";
        nhapNhanVien(dsNV[i]);
    }

    cout << "\n=== DANH SACH NHAN VIEN ===\n";
    cout << left << setw(12) << "Ma NV" 
         << setw(25) << "Ho Ten" 
         << setw(18) << "Luong Co Ban" 
         << setw(10) << "He So" << endl;
    cout << string(65, '-') << endl;

    for (int i = 0; i < n; i++) {
        xuatNhanVien(dsNV[i]);
    } 
 
    return 0;
}
