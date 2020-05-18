#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	char c[] ="314159265358979323846264338327950";
	long long n=1;
	for(int i=0;i<t;i++) {
		n=n*long(c[i]-'0');
	}
	cout<<n<<endl;
	return 0;
}

