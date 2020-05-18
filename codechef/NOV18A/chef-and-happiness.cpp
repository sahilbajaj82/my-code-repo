#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int *a=new int[n];
		int *c=new int[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
			c[i]=a[i];
		}
		sort(a,a+n);
		
		int j=0;
    	for(int i=0;i<n-1;i++) 
        	if(a[i]!=a[i+1]) 
            	a[j++]=a[i]; 
  		a[j++]=a[n-1];
  		int *b=new int[n];
  		for(int i=0;i<j;i++) {
  			b[i]=c[a[i]-1];
  			//cout<<b[i-1] <<" ";
  		}
  		sort(b,b+j);
  		int flag=0; 
  		for(int i=0;i<j-1;i++) {
  			if(b[i]==b[i+1]) {
  				flag=1;
  				break;
  			}
  		}
  		if(flag)
  			cout<<"Truly Happy\n";
  		else
  			cout<<"Poor Chef\n";
	}
	return 0;
}
