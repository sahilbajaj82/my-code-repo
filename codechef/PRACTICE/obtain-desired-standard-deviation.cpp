#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		long s;
		cin>>s;
		s=s*s;
		s=s*n;
		long double check=s;
		if(n==1) {
			if(s==0)
				cout<<"0"<<endl;
			else
			cout<<"-1"<<endl;
		}
		else  {
				int copy=n-2;
				while(copy--) {
					cout<<"0 ";
				}
				check/=2;
				check=sqrt(check);
				printf("%0.15Lf %0.15Lf",check,-1*check);
				cout<<endl;
		}
	}
	return 0;
}



