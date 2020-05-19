#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--) {
		long k;
		int d0,d1;
		cin>>k>>d0>>d1;
		long sum=0;
		long i=3;
		sum=(d0+d1)%10;
		if(sum%5==0) {
			cout<<"NO"<<endl;
		}
		else {
			long total=d0+d1;
			total=total+sum;
			while(sum!=2&&i<k) {
				i++;
				sum=(sum*2)%10;
				total=total+sum;
		}
	
		long temp=k-i;
		temp=temp/4;
		total=total+temp*20;
		temp=k-i-temp*4;
		if(temp==3)
			total+=18;
		if(temp==2)
			total+=12;
		if(temp==1)
			total+=4;
	
		if(total%3==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
	

