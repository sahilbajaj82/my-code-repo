#include<bits/stdc++.h>
using namespace std;

int main() {


	int n;
	cin>>n;
	string s;
	while(n--) {
		int l;
		cin>>l;
		cin>>s;
		string f = "codered";
		int p = 0;
		for(int i=0;i<s.length();i++) {
			if(s[i]==f[p])
				p++;
			if(p==7)
				break;
		}
		if(p==7)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}
