#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		char c[101];
		cin>>c;
		int l=strlen(c);
		int flag=1;
		for(int i=0;i<l;i=i+2) {
			if(c[i]==c[i+1])
				flag=0;
		}
		if(flag)
			cout<<"yes";
		else
			cout<<"no";
		cout<<"\n";
	}
	return 0;
}
