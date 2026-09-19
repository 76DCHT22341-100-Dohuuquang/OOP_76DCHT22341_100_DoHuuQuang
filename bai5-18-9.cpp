#include <bits/stdc++.h>

using namespace std;

class Nguoi{          // Lop cha
    protected:
        string Hoten , namsinh;
    public:
        void nhapNguoi(){
            cout<<"nhap ho ten: ";
            cin.ignore();
            getline(cin,Hoten);
            cout<<"nhap nam sinh: ";
            cin>>namsinh;
        }
        void xuatNguoi(){
            cout<<Hoten<<"\n"<<namsinh;
        }
        string getHoten(){ // Lay Hoten tu protected ra de dung vao ham timkiemthongtin
            return Hoten;
        }
};
class Sinhvien : public Nguoi{ // Lop con
    private:
        string Msv;
        float dtb;
    public:
        void nhap(){
            nhapNguoi(); // goi lop cha
            cout<<"nhap ma sinh vien: ";
            cin>>Msv;
            cout<<"nhap diem trung binh: ";
            cin>>dtb;
        }
        void xuat(){
            xuatNguoi(); // goi lop cha
            cout<<"\n"<<Msv<<"\n"<<dtb;
        }
        string getMsv(){ // Lay Msv tu private ra de dung vao ham timkiemthongtin
            return Msv;
        }
};
// ham de tim kiem thong tin sinh vien
//tu khoa la chuoi van ban go tu ban phim, dung de so sanh voi dssv
void timkiemthongtin(Sinhvien ds[] , int n , string tukhoa){ // khai bao ds , n , tukhoa
    bool timthay=false; // de hieu rang chua tim thay thong tin
    for(int i=0 ; i<n ; i++){ // duyet qua sinh vien
        if(ds[i].getHoten()==tukhoa || ds[i].getMsv()==tukhoa){ // neu ten sinh vien hoac msv giong voi tukhoa
            cout<<" \n ket qua tim kiem: \n";
            ds[i].xuat(); // suy ra xuat thong tin sinh vien
            timthay=true; // bat true nghia la da tim thay, ham nay giup chuong trinh biet da tim thay ket qua
        }
    }
    if(timthay==false){ // neu tim thay bang false , may se bt rang chua tim thay ket qua
        cout<<"khong co du lieu";
    }
}
int main (){
    int n;
    Sinhvien ds[100]; // khai bao ds
    string tukhoa;    // khai bao tu khoa
    cout<<"nhap n = ";
    cin>>n;

    cout<<"\n \==NHAP THONG TIN SINH VIEN==/ \n";
    for(int i=0;i<n;i++){
        cout<<"\nsinh vien thu: "<<i+1<<endl;
        ds[i].nhap();
    }
    cout<<"\n \==THONG TIN TIM KIEM==/ \n";
    cin.ignore(); // de xoa bo enter o nhap n
    getline(cin,tukhoa); // de nhap tukhoa , vd nhap la quang hay 1-> se luu vao bien tukhoa
                        //-> ham timkiemthongtin se lay tukhoa dem di so sanh voi hoten or msv (o dong 48).
    timkiemthongtin(ds , n , tukhoa);

    return 0;
}