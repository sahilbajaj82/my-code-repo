#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<t;i++)
		sum=sum+s[i]-'0';
	int a[101];
	int j=0;
	for(int i=2;i<101;i++)
		if(sum%i==0)
			a[j++]=i;
	int flag=0;
	for(int i=0;i<j;i++) {
		int x=sum/a[i];
		int count=0;
		int ss=0;
		int check=1;
		for(int k=0;k<t;k++) {
			ss=ss+s[k]-'0';
			if(ss==x) {
				ss=0;
			}
			if(ss>x) {
				check=0;
				break;
			}
		}
			if(check) {
				flag=1;
				break;
			}
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
