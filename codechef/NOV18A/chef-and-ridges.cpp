#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long num=1,den=2,n1=1,d2=2,i=1,b=2;
		while(i<n) {
			d2=d2*b;
			if(i%2==1) {
				num=b*num-n1;
				den=d2;
			}
			else {
				num=b*num+n1;
				den=d2;
			}
			i++;
			
		}
		
	cout<<num<<" "<<den<<" ";
	}
	cout<<"\n";
	return 0;
}
