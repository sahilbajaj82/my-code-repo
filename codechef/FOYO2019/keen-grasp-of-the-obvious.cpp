#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	string s;
	cin>>s;
	int l=s.length();
	int x=0;
	for(int i=0;i<l;i++) {
		if(s[i]=='0'||s[i]=='4'||s[i]=='6'||s[i]=='9')
			x++;
		else if(s[i]=='8')
			x=x+2;
	}
	cout<<x<<endl;
	}
	return 0;
}

