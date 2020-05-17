#include<bits/stdc++.h>
using namespace std;
int main() {
	int d,n;
	cin>>n>>d;
	int q;
	cin>>q;
	while(q--) {
		int flag=1;
		int a,b;
		cin>>a>>b;
		if(a+b-d<0)
			flag=0;
		if(a+b-2*n+d>0)
			flag=0;
		if(b-a-d>0)
			flag=0;
		if(a-b-d>0)
			flag=0;


		if(flag)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<"\n";
	}
	return 0;
}
