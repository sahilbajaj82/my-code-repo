#include<bits/stdc++.h>
using namespace std;
int callbs(int s,int e) {
	if(e-s<700) {
		for(int i=s;i<=e;i++) {
			cout<<"1 "<<i<<endl;
			fflush(stdout);
			int x;
			cin>>x;
			if(x==1) {
				cout<<"2\n3 "<<i<<endl;
				break;
			}
		}
	}
	else {
		int m=(e+9*s)/10+1;
		cout<<"1 "<<m<<endl;
		fflush(stdout);
		int x;
		cin>>x;
		if(x==-1) {
			m=m-1;
			cout<<"1 "<<m<<endl;
			fflush(stdout);
			cin>>x;
		}
		if(x==1) {
			cout<<"2\n";
			callbs(s,m);
		}
		else {
			callbs(m,e);
		}
	}
	return 0;
}
int main() {
	int n,c;
	cin>>n>>c;
	callbs(1,n);
	return 0;
}
