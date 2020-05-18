#include<bits/stdc++.h>
using namespace std;
int cal(string s){
	int tim=2;
	int l=s.length();
	for(int i=1;i<l;i++) {
		if((s[i-1]=='f'||s[i-1]=='d')&&(s[i]=='f'||s[i]=='d'))
			tim=tim+4;
		else if((s[i-1]=='j'||s[i-1]=='k')&&(s[i]=='j'||s[i]=='k'))
			tim=tim+4;
		else
			tim=tim+2;
	}
	return tim;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		string *s=new string[n];
		for(int i=0;i<n;i++)
			cin>>s[i];
		sort(s,s+n);
		long tim=0;
		int caltime=cal(s[0]);
		tim=caltime;
		for(int i=1;i<n;i++) {
			if(s[i-1].compare(s[i])==0)
				tim+=caltime/2;
			else {
				caltime=cal(s[i]);
				tim+=caltime;
			}
		}
		cout<<tim<<endl;
	}
	return 0;
}
			
