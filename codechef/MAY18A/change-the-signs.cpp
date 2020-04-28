#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long a[100002];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int dp[100002];
		memset(dp,0,sizeof(int));
		a[n+1]=INT_MAX;a[0]=INT_MAX;
	 	long ps=INT_MAX;
		int p=0;
		for(int i=1;i<=n;i++) {
			ps=ps<a[i-1]?ps:a[i-1];
			if(a[i]<ps&&a[i]<a[i+1]) {
				a[i]=a[i]*-1;
				dp[i]=0;
				p=i;
			}
			else if(a[i]<a[i-1]&&a[i]<a[i+1]) {
				long sum1=a[i];
				long sum2=0;
				int j=p;
				int count=1;
				while(j!=0) {
					if(count%2)
						sum2-=a[j];
					else
						sum1+=a[j];
					j=dp[j];
				}
				if(sum1>sum2) {
					a[i]*=-1;
					int j=p;
					while(j!=0) {
						a[j]*=-1;
						j=dp[j];
					}
					dp[i]=p;
				}
				p=i;
			}
			ps=ps+a[i];
		}
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
// 4 7 5 6 3 
			
				

