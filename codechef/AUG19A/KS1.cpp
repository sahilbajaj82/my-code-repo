#include<bits/stdc++.h>
using namespace std;
int main() {
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		long *a=new long[n+1];
		for(long i=1;i<=n;i++)
			cin>>a[i];
		a[0]=0;
		for(long i=1;i<=n;i++)
			a[i]=a[i]^a[i-1];
		long count=0;
		long ar[1050000];
		vector <long> v[1050000];
		for(long i=0;i<=n;i++) {
			v[a[i]].push_back(i);
			ar[a[i]]=1;
		}
		
		for(long i=0;i<=n;i++){
			if(ar[a[i]]) {
				//cout<<a[i]<<" ";
				long len=v[a[i]].size();
				//cout<<len<<endl;
				if(len>1) {
				for(long j=len-1;j>=0;j--) {
					count+=j*v[a[i]][j]-(len-1-j)*v[a[i]][j];
				}
				count=count-(len*(len-1))/2;	
				}
			ar[a[i]]=0;
			}
		}
		cout<<count<<endl;
	}
	return 0;

}