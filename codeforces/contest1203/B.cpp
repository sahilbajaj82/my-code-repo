#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[4*n+1];
		for(int i=0;i<4*n;i++) {
			cin>>a[i];
		}
		int N=4*n;
		sort(a,a+N);

		int flag=1;
		int area=-1;
		for(int i=0;i<N;i=i+2) {
			if(a[i]==a[i+1]&&a[N-i-1]==a[N-i-2]) {
				if(area==-1) {
					area=a[i]*a[N-i-1];
				}
				else {
					if(area!=a[i]*a[N-i-1]) {
				//		cout<<"CF"<<i<<endl;
						flag=0;
						break;
					}

				}
			}
			else {
				//cout<<"CC"<<i<<endl;
				flag=0;
				break;
			}
		}
		if(flag==1) {
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
	}
	return 0;
}