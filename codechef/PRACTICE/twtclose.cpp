#include<iostream>
using namespace std;
int main()
{ int n,k;
  int a[1001]={0};
  cin>>n>>k;
  int count=0;
  while(k--) {
	char c[10];
	int m;
	cin>>c;
	if(c[2]=='O')
	{ for(int i=1;i<=n;i++)
	  a[i]=0;
	  count=0;
	}
	else { cin>>m;
	if(a[m]==0) { a[m]=1; count++; }
	else
	{ a[m]=0; count--; }
       }
 cout<<count<<endl;
 }
return 0;
}

