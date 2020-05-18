#include<bits/stdc++.h>
using namespace std;
int main(){
	long num,sum=0;
	cin>>num;
	sum=1;
	long p=sqrt(num);
	for(int loop=2; loop<=p;loop++)
	{
		if(num%loop==0) {
			sum+=loop;
			sum+=num/loop;
		}
			
	}
	if(sum==num&&num!=1) {
		cout<<"Perfect\n";
	}
	else {
		cout<<"Not Perfect\n";
	}

return 0;
}

