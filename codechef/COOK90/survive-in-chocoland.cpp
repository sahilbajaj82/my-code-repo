#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,k,s;
		cin>>n>>k>>s;
		if(s>6) {
			if(n*6<k*7)
			cout<<"-1"<<endl;
		else {
			int y=s*k;
			if(y%n==0)
				cout<<y/n<<endl;
			else
				cout<<(y/n)+1<<endl;
			}
		}
		else {
			if(k>n)
				cout<<"-1"<<endl;
			else if(k==n)
				cout<<s<<endl;
			else {
				int y=s*k;
				if(y%n==0)
					cout<<y/n<<endl;
				else
					cout<<(y/n)+1<<endl;
			}
		}
	}
return 0;
}

