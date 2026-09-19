#include <bits/stdc++.h>

using namespace std;

class Monhoc{
	protected:
		string mon;
		int cc;
		float kt , dt;
	public:
		void nhapMonhoc(){
			cout<<"nhap ten mon hoc: ";
			cin.ignore();
			getline(cin,mon);
			cout<<"nhap diem chuyen can: ";
			cin>>cc;
			cout<<"nhap diem kiem tra: ";
			cin>>kt;
			cout<<"nhap diem thi: ";
			cin>>dt;
		}
		void xuatMonhoc(){
			cout<<"Mon: "<<mon<<" | "
             	<<"diem chuyen can: "<<cc<<" | "<<"diem kiem tra: "<<kt<<" | "<<"diem thi: "<<dt;
		}
		float getcc(){
			return cc;
		}
		float getkt(){
			return kt;
		}
};	
class Sinhvien : public Monhoc{
	private:
		string hoten , msv , lop;
	public:
		void  nhap(){
			nhapMonhoc();
			cout<<"nhap ten sinh vien: ";
			cin.ignore();
			getline(cin,hoten);
			cout<<"nhap ten lop: ";
			cin>>lop;
			cout<<"nhap msv: ";
			cin>>msv;
		}
		void xuat(){
			cout<<"ten sinh vien: "<<hoten<<" | "<<"lop: "<<lop<<" | "<<"msv: "<<msv<<endl;
			xuatMonhoc();		
		float diemhocphan;
		diemhocphan=(cc*0.1)+(kt*0.3)+(dt*0.6);
		cout<<" | diem hoc phan la: "<<diemhocphan;				
		}
		
};
	void camthi(Sinhvien ds[] , int n){  // vì muốn nhập vào cả mang ds[] và biến n để chạy vòng lặp từng ptu
			for(int i=0 ; i<n;i++){     // suy ra ham do phai viet ben ngoai
				if(ds[i].getcc()<5 || ds[i].getkt()==0){
				   ds[i].xuat();
			}		
			}
		}	
int main(){
	int n;
	cout<<"nhap n= ";
	cin>>n;
	
	Sinhvien ds[100];
	cout<<"\n \==NHAP THONG TIN SINH VIEN==/ \n";
	for(int i=0;i<n;i++){
		cout<<"sinh vien thu: "<<i+1<<endl;
		ds[i].nhap();
}
	cout<<"\n \==THONG TIN SINH VIEN BI CAM THI==/ \n";
	camthi(ds, n);  // viet ngoài hàm thì ko cần duyệt lại
}
