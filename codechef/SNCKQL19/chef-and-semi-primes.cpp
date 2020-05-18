#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	int a[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int *b=new int[25*25];
	int n=25;
	int k=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++)
			b[k++]=a[i]*a[j];
	}
	sort(b,b+k);
	for(int i=0;i<k;i++) {
		//cout<<b[i]<<" ";
		if(b[i]>200) {
			k=i;
			break;
		}
	}
	int *c=new int [k*k];
	int r=0;
	for(int i=0;i<k;i++) {
		for(int j=0;j<k;j++) {
			c[r++]=b[i]+b[j];
		//	cout<<c[r-1]<<" "<<b[i]<<" "<<b[j]<<endl;
		}
	}
	sort(c,c+r);
	for(int i=0;i<r;i++) {
		if(c[i]>200) {
			r=i;
			break;
		}
	}
	int d[201];
	for(int i=0;i<=201;i++)
		d[i]=0;
	for(int i=0;i<r;i++) {
		d[c[i]]=1;
	}
	while(t--) {
		int f;
		cin>>f;
		if(d[f])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
