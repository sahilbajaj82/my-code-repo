#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd((a),(b))
int main(){
	int h,w,x,y;
	cin>>h>>w>>x>>y;
	int g=gcd(x,y);
	x=x/g;
	y=y/g;
	int temp1=h/x;
	int temp2=w/y;
	if(temp1>temp2){
		cout<<temp2*x<<" "<<temp2*y<<endl;
	}
	else{
		cout<<temp1*x<<" "<<temp1*y<<endl;
	}
	return 0;
}