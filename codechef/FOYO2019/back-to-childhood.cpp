#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--) {
		string s;
		cin>>s;
		int flag=1;
		int l=s.length();
		int x=0;
		for(int i=0;i<l;i++) {
			if(s[i]=='/')
				x++;
			else
				x--;
			if(x<0)
				flag=0;
		}

	if(flag) {
		cout<<"Regular since Childhood.\n";
	}
	else {
		cout<<"Irregular since Childhood.\n";
	}
}
return 0;
}

