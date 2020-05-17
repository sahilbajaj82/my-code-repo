#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='L') {
			for(int j=0;j<10;j++) {
				if(a[j]==0) {
					a[j]=1;
					break;
				}
			}
		}
		else if(s[i]=='R') {
			for(int j=9;j>=0;j--) {
				if(a[j]==0) {
					a[j]=1;
					break;
				}
			}
		}
		else {
			a[s[i]-'0']=0;
		}
	}
	for(int i=0;i<10;i++)
		cout<<a[i];
	cout<<endl;
	
	return 0;
}