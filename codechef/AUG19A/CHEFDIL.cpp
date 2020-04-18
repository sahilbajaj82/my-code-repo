#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int count1=0;
		for(int i=0;i<s.length();i++) {
			if(s[i]=='1')
				count1++;
		}	
		if(count1%2==1)
			cout<<"WIN\n";
		else
			cout<<"LOSE\n";
	}
	return 0;

}