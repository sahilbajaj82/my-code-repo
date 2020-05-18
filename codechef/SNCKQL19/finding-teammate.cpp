#include<bits/stdc++.h>
using namespace std;
int main(){ 
	int t;
	cin>>t;
	long p[100001];
	long M=1000000007;
	p[0]=1;
	p[1]=1;
	p[2]=1;
	for(int i=3;i<100001;i++) {
		if(i%2) {
			p[i]=(p[i-1]*i)%M;
		}
		else {
			p[i]=p[i-1];
		}
	}
	while(t--) {
		int n;
		cin>>n;
		int *a=new int[n];
		long *b=new long[1000001];
		for(int i=0;i<1000001;i++) {
			b[i]=0;
		}
		for(int i=0;i<n;i++) {
			cin>>a[i];
			b[a[i]]++;
		}
		int k=0;
		sort(a,a+n);
		for(int i=0;i<n;) {
			a[k++]=a[i];
			i=i+b[a[i]];
		}
		n=k;
		long count=1;
		int temp=a[n-1];
		for(int i=n-2;i>=0;i--) {
			if(b[temp]==1) {
				count=(count*b[a[i]])%M;
				b[a[i]]--;
				temp=a[i];
								// 1 1 1 1 1 2 2 3 3 3 3 3 //4 4 4 4 
			}
			else if(b[temp]%2==0) {
				count=(count*p[b[temp]])%M;
				temp=a[i];
			}
			else {
				count=(count*p[b[temp]])%M;
				i++;
				b[temp]=1;
			}
		}
		count=(count*p[b[a[0]]])%M;
		cout<<count<<endl;
	}
	return 0;
}

