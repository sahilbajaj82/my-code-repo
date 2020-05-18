#include<bits/stdc++.h>
using namespace std;
long double euclid(long double x1,long double y1,long double x2,long double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
	#ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
	int t;
	cin>>t;

	while(t--) {
		long double x,y;
		cin>>x>>y;
		int n,m,k;
		cin>>n>>m>>k;
		long double a[n][2],b[m][2],c[k][2],mina[n],minb[m];
		for(int i=0;i<n;i++) {
			cin>>a[i][0]>>a[i][1];
		}
		for(int i=0;i<m;i++) {
			cin>>b[i][0]>>b[i][1];
		}
		for(int i=0;i<k;i++) {
			cin>>c[i][0]>>c[i][1];
		}
		for(int i=0;i<n;i++) {
			mina[i]=euclid(a[i][0],a[i][1],c[0][0],c[0][1]);
			for(int j=1;j<k;j++) {
				long double temp=euclid(a[i][0],a[i][1],c[j][0],c[j][1]);
				if(mina[i]>temp)
					mina[i]=temp;
			}
		}
		//cout<<"kk";
		for(int i=0;i<m;i++) {
			minb[i]=euclid(b[i][0],b[i][1],c[0][0],c[0][1]);
			for(int j=1;j<k;j++) {
				long double temp=euclid(b[i][0],b[i][1],c[j][0],c[j][1]);
				if(minb[i]>temp)
					minb[i]=temp;
			}
		}
		long double min=LDBL_MAX;
		for(int i=0;i<n;i++) {
			long double val=euclid(x,y,a[i][0],a[i][1]);
			for(int j=0;j<m;j++) {
				long double temp=val+euclid(a[i][0],a[i][1],b[j][0],b[j][1])+minb[j];
				if(min>temp)
					min=temp;
			}
		}
		for(int i=0;i<m;i++) {
			long double val=euclid(x,y,b[i][0],b[i][1]);
			for(int j=0;j<n;j++) {
				long double temp=val+euclid(a[j][0],a[j][1],b[i][0],b[i][1])+mina[j];
				if(min>temp)
					min=temp;
			}
		}
		printf("%0.9Lf\n",min);
	}
	return 0;
}
