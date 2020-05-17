#include<bits/stdc++.h>
using namespace std;
int main() {
	int flag=0;
	int n;
	cin>>n;
	while(n--)  {
		int h;
		cin>>h;
		if(h)
			flag=1;
	}
	if(flag)
		cout<<"HARD";
	else
		cout<<"EASY";
	cout<<"\n";
	return 0;
}
