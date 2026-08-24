#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Để dùng setw căn chỉnh cột

using namespace std;

class NhanVien {
private:
    string maNV;
    string hoTen;
    double luong;

public:
    // 1. Constructor không đối (Default constructor)
    NhanVien() {
        maNV = "";
        hoTen = "";
        luong = 0.0;
    }

    // 2. Constructor có đối (Parameterized constructor)
    NhanVien(string ma, string ten, double l) {
        maNV = ma;
        hoTen = ten;
        luong = l;
    }

    // Tiêu đề bảng
    static void inTieuDe() {
        cout << left 
             << setw(15) << "Ma NV" 
             << setw(25) << "Ho Ten" 
             << setw(15) << "Luong" << endl;
        cout << string(55, '-') << endl;
    }

    // Xuất dữ liệu theo dạng hàng (dùng cho định dạng cột)
    void xuatTheoCot() const {
        cout << left 
             << setw(15) << maNV 
             << setw(25) << hoTen 
             << fixed << setprecision(2) << setw(15) << luong << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    vector<NhanVien> dsNV; // Sử dụng Cấu trúc dữ liệu Vector (Cách 3)

    // Ở MAIN: Nhập n nhân viên sử dụng constructor có đối để đưa vào mảng
    for (int i = 0; i < n; i++) {
        string ma, ten;
        double luong;

        cout << "\n=== NHAP THONG TIN NHAN VIEN THU " << i + 1 << " ===" << endl;
        cout << "Nhap ma NV: ";
        cin >> ma;
        cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập chuỗi có khoảng trắng
        cout << "Nhap ho ten: ";
        getline(cin, ten);
        cout << "Nhap luong: ";
        cin >> luong;

        // Tạo đối tượng bằng Constructor có đối và push_back vào vector
        NhanVien nv(ma, ten, luong);
        dsNV.push_back(nv);
    }

    // Xuất dữ liệu nhân viên theo dạng cột
    cout << "\n================ BANGLUONG NHAN VIEN ================\n";
    NhanVien::inTieuDe();
    for (size_t i = 0; i < dsNV.size(); i++) {
        dsNV[i].xuatTheoCot();
    }

    return 0;
}
