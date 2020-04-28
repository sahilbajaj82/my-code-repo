#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	int a[5001]={0};
	for(int i=0;i<t;i++)
	{ for(int j=0;j<5;j++) {
		int x;
		cin>>x;
		a[i]+=x;
	}
	switch(a[i]) {
	case 0 : cout<<"Beginner";
			break;
	case 1 : cout<<"Junior Developer";
			break;
	case 2 : cout<<"Middle Developer";
			break;
	case 3 : cout<<"Senior Developer";
			break;
	case 4 : cout<<"Hacker";
			break;
	case 5 : cout<< "Jeff Dean";
			break;
	}
	cout<<endl;
	}
	return 0;
	}
