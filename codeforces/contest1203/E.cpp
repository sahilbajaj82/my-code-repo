#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	int b[150002];
	int len=150002;
	for(int i=0;i<len;i++)
		b[i]=0;
	for(int i=0;i<n;i++) {
		if(a[i]!=1) {
			if(b[a[i]-1]==0) {
					b[a[i]-1]=1;
			}
			else if(b[a[i]]==0) {
				b[a[i]]=1;
			}
			else if(b[a[i]+1]==0) {
					b[a[i]+1]=1;
			}
		}
		else {
			if(b[a[i]]==0) {
				b[a[i]]=1;
			}
			else if(b[a[i]+1]==0) {
				b[a[i]+1]=1;
			}
		}			
	}
	int count=0;
	for(int i=1;i<len;i++) {
		if(b[i]==1)
			count++;
	}
	cout<<count<<endl;
	return 0;
}