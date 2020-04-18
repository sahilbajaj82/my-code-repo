#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long double k[100001],c[100000],sum=0,sumk=0,isumk=0;
		
		for(int i=0;i<n;i++) {
			cin>>k[i];
			sumk+=k[i];
			isumk+=1/k[i];
		}
		for(int i=0;i<n;i++) {
			cin>>c[i];
			sum=sum+c[i]*k[i];
		}
		if(sum<0) {
			cout<<"-1\n";
		}
		else {
			long double ss=0;
			long double te=sum;
			long double d[100001];
			for(int i=0;i<n;i++) {
				d[i]=te/(k[i]*k[i]);
				// cout<<d[i]<<" ";
				d[i]=d[i]/isumk;
				ss=ss+sqrt(d[i]);
			}
			printf("%.*Lf ",7,ss);
			for(int i=0;i<n;i++) {
				long double x =d[i]-c[i];
				printf("%.*Lf ",7,x);
			}
			cout<<endl;
		}

	}
	return 0;
}