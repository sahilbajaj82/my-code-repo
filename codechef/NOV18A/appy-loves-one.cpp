#include<bits/stdc++.h>
using namespace std;
int longestone(int *a,int n) {
	int maxx=0;
	for(int i=0;i<n;i++) {
		int count=1;
		if(a[i]) {
			for(int j=i+1;j<n;j++) {
				if(a[j])
					count++;
				else
					break;
			}
			if(count>maxx)
				maxx=count;
		}
	}
	return maxx;
}
void print(int *a,int n) {
	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main() {
	int n,k,q;
	cin>>n>>q>>k;
	int *a=new int[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	char *c=new char[q+1];
	cin>>c;
	int i=0;
	while(i<q) {
		if(c[i]=='?') {
			int b=longestone(a,n);
			if(b>k)
				b=k;
			cout<<b<<endl;
		}
		else {
			int temp=a[n-1];
			for(int i=n;i>0;i--)
				a[i]=a[i-1];
			a[0]=temp;
			//print(a,n);
		}
		i++;
	}
	return 0;
}
