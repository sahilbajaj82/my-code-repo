#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	unsigned long M=1000000007;
	long fib[100001];
	fib[0]=0,fib[1]=1;
	for(int i=2;i<100001;i++)
		fib[i]=(fib[i-1]+fib[i-2])%M;
	while(t--) {
		long m,n;
		cin>>m>>n;
		long a[100001];
		long b[100001];
		long result=0;
		for(int i=0;i<m;i++) {
			cin>>a[i];
			if(n>2)
			result=(result+(a[i]*((fib[n-2]*m)%M))%M)%M;
			else if(n==1) {
				result=(result+(a[i]*m)%M)%M;
			}
		}
		for(int i=0;i<m;i++) {
			cin>>b[i];
			if(n>=2)
			result=(result+((b[i]*((fib[n-1]*m)%M))%M))%M;
		}
		cout<<result<<endl;

	}

	return 0;
}
		
