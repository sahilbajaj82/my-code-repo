#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long a[100001];		
		long k,b;
		cin>>k>>b;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int count=1;
		int l=0;
		long temp;
		while(l<n) {
			temp=a[l]*k+b;
			if(a[n-1]<temp)
			break;
			l++;	
			for(;l<n;l++)
			if(temp<=a[l])
			{ count++;
			break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
	}
			



