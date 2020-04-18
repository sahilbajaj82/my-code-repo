#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		int max=0;
		for(int i=0;i<n;i++) {
			int temp;
			cin>>temp;
			if(arr[i]*20-temp*10>max)
				max=arr[i]*20-temp*10;
		}
		cout<<max<<endl;
	}
	return 0;
}