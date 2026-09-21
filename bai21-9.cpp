#include <bits/stdc++.h>

using namespace std;

class Ps1{
	protected:
		int tu;
		int mau;
	public:
		void nhap(){
			cout<<"nhap tu so: ";
			cin>>tu;
			do{
				cout<<"nhap mau so: ";
				cin>>mau;
			}
			while(mau==0);
		}
		void Toigian(){
			int gcd=std::__gcd(tu,mau);
			tu/=gcd;
			mau/=gcd;
			if(mau<0){
				tu=-tu , mau=-mau;
			}			
		}
		void xuat(){
			cout<<tu<<" / "<<mau;
		}
};
class Ps2 : public Ps1{
	public:
		bool operator=(Ps2 ps){
			tu = ps.tu;
			mau=ps.mau;
			return true;
		}
		bool operator>(Ps2 ps){
		   return (tu*ps.mau)>(mau*ps.tu);
		}
};
bool sapxepgiamdan(Ps2 a , Ps2 b){
	return a > b;
}
int main(){
	int n;
	do{
		cout<<"nhap so luong phan so (toi da 10 phan tu): ";
		cin>>n;
	}while(n<1 || n>10);
	 
	 vector <Ps2> ds(n);
	 for(int i=0 ; i<n ;i++){
	 	cout<<"phan so thu: "<<i+1<<endl;	
	 	ds[i].nhap();
		ds[i].Toigian();
}
    
    sort(ds.begin() , ds.end() ,sapxepgiamdan);
     
    cout<<"\n \==DACH SACH GIAM DAN==/ \n";
    for(int i=0 ; i<n;i++){
    	cout<<"phan so: "<<i+1<<": ";
    	ds[i].xuat();
    	cout<<"\n";
	}
  	return 0;
}