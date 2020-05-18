#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		long a;
		cin>>a;
		int day=0;
		for(int i=1;i<n;) {
			long y=a;
			while(i<n&&(y--)) {
				int temp;
				cin>>temp;
				a+=temp;
				i++;
			}
			day++;
		}
		cout<<day<<endl;
	}
	return 0;
}
