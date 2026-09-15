#include <bits/stdc++.h>

using namespace std;

// Câu 1: Khai báo lớp Nguoi
class Nguoi {
protected:
    string hoten;
    int namsinh;

public:
	//hsm tao ko doi
    	Nguoi(){
			hoten="";
			namsinh=0;
		}
		//ham tao co doi
		Nguoi(string ten , int ns){
			hoten=ten;
			namsinh=ns;
    // Câu 2: Phương thức nhập, xuất cho Nguoi
        void nhap() {
        cout << "  Nhap ho ten: ";
        getline(cin, hoten);
        cout << "  Nhap nam sinh: ";
        cin >> namsinh;
        cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập số
    }

        void xuat() {
        cout << "Ho ten: " << hoten << " | Nam sinh: " << namsinh;
    }
};

// Câu 1: Khai báo lớp SinhVien kế thừa lớp Nguoi
class SinhVien : public Nguoi {
private:
    string maSV;
    float diemTB;

public:
	//lop con sinh vien ko dc ke thua ham tao ma phai goi lai
	//goi lai ham tao ko doi cua nguoi
    SinhVien() : Nguoi(){
	}
	//goi lai ham tao co doi cua nguoi
	SinhVien(string ten, int ns ,string msv , float dtb): Nguoi(string ten , int ns){
		maSV=msv;
		diemTB=dtb;
	}
    // Câu 2: Phương thức nhập, xuất cho SinhVien
    void nhap(){
        Nguoi::nhap();// goi nhap cua lop nguoi, sinh vien duoc ke thua nguoi
		cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
        cout << "  Nhap diem trung binh: ";
        cin >> diemTB;
    }

    void xuat(){
        Nguoi::xuat();
		cout << "MSV: " << maSV << " | "; 
        cout << " | Diem TB: " << diemTB << endl;
    }

    // Getter lấy điểm trung bình để sắp xếp
    float getDiemTB()  {
        return diemTB;
    }
};

// Hàm so sánh điểm trung bình giảm dần
bool soSanhDiem( SinhVien a, SinhVien b) {
    return a.getDiemTB() > b.getDiemTB();
}

int main() {
    int n;
    cout << "Nhap so luong sinh vien n = ";
    cin >> n;
    cin.ignore();

    vector<SinhVien> dsSV(n);

    // Câu 3: Nhập danh sách n sinh viên
    cout << "\n=== NHAP DANH SACH SINH VIEN ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nSinh vien thứ " << i + 1 << ":\n";
        dsSV[i].nhap();
    }

    // Sắp xếp danh sách giảm dần theo điểm trung bình
    sort(dsSV.begin(), dsSV.end(), soSanhDiem);

    // In danh sách sau khi sắp xếp
    cout << "\n=== DANH SACH SINH VIEN GIAM DAN THEO DIEM TB ===\n";
    for (int i = 0; i < n; i++) {
        dsSV[i].xuat();
    }

    return 0;
}