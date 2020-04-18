#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long power(long x, unsigned long y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return power(x, y / 2) * power(x, y / 2); 
    else
        return x * power(x, y / 2) * power(x, y / 2); 
} 

long fun(long x) {
	long sum=0;
	string number;
	stringstream  ss;
	ss<<x;
	ss>>number;

	int len=number.length();
	reverse(number.begin(),number.end());
	sum=(sum+(number[len-1]-'0')*power(10,len-1))%MOD;
	for(int i=len-2;i>=0;i--) {
		if(number[i]==number[i+1])
			continue;
		else {
			sum=(sum+(number[i]-'0')*power(10,i))%MOD;
		}
	}
	return sum;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		long nl,l;
		cin>>nl>>l;
		long nr,r;
		cin>>nr>>r;
		long sum=0;
		for(long i=l;i<=r;i++) {
			sum=(sum+fun(i))%MOD;
			//cout<<i<<" "<<fun(i)<<endl;
		}
		cout<<sum<<endl;
	}
}