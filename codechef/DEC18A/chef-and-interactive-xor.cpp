#include<bits/stdc++.h>
using namespace std;
void xor4(int s,int *a) {
	int c123,c234,c134,c124,c1234;
	cout<<"1 "<<s+1<<" "<<s+2<<" "<<s+3<<endl;
	fflush(stdout);
	cin>>c123;
	cout<<"1 "<<s+2<<" "<<s+3<<" "<<s+4<<endl;
	fflush(stdout);
	cin>>c234;
	cout<<"1 "<<s+1<<" "<<s+2<<" "<<s+4<<endl;
	fflush(stdout);
	cin>>c124;
	cout<<"1 "<<s+1<<" "<<s+3<<" "<<s+4<<endl;
	fflush(stdout);
	cin>>c134;
	c1234=c123^c234^c134^c124;
	a[s+1]=c1234^c234;
	a[s+2]=c1234^c134;
	a[s+3]=c1234^c124;
	a[s+4]=c1234^c123;
}
void xor5(int s,int *a) {
	int c123,c234,c145,c125,c345;
	cout<<"1 "<<s+1<<" "<<s+2<<" "<<s+3<<endl;
	fflush(stdout);
	cin>>c123;
	cout<<"1 "<<s+2<<" "<<s+3<<" "<<s+4<<endl;
	fflush(stdout);
	cin>>c234;
	cout<<"1 "<<s+1<<" "<<s+4<<" "<<s+5<<endl;
	fflush(stdout);
	cin>>c145;
	cout<<"1 "<<s+1<<" "<<s+2<<" "<<s+5<<endl;
	fflush(stdout);
	cin>>c125;
	cout<<"1 "<<s+3<<" "<<s+4<<" "<<s+5<<endl;
	fflush(stdout);
	cin>>c345;
	int c14=c123^c234;
	int c5=c145^c14;
	int c12=c125^c5;
	int c3=c123^c12;
	int c4=c345^c3^c5;
	int c2=c234^c3^c4;
	int c1=c123^c2^c3;
	a[s+1]=c1;
	a[s+2]=c2;
	a[s+3]=c3;
	a[s+4]=c4;
	a[s+5]=c5;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int s=0;
		int y=n/4;
		int h=n-y*4;
		int *a=new int[n+1];
		if(n!=11) {
		if(h==0) {
			while(y--) {
			xor4(s,a);
			s=s+4;
			}
		}
		else if(h==1) {
			y--;
			while(y--) {
			xor4(s,a);
			s=s+4;
			}
			xor5(s,a);
		}
		else if(h==2) {
			y=y-2;
			while(y--) {
			xor4(s,a);
			s=s+4;
			}
			xor5(s,a);
			s=s+5;
			xor5(s,a);
		}
		else {
			y=y-3;
			while(y>0) {
			xor4(s,a);
			s=s+4;
			y--;
			}
			xor5(s,a);
			s=s+5;
			xor5(s,a);
			s=s+5;
			xor5(s,a);
		}
		}
		cout<<"2";
		for(int i=1;i<=n;i++) {
			cout<<" "<<a[i];
		}
		cout<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		if(x==-1) {
			return 0;
		}
	}
	return 0;
}
