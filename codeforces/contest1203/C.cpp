#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);
}  

int main() {
	
		long long n;
		cin>>n;
		long long a[n];
		for(long long i=0;i<n;i++) {
			cin>>a[i];
		}
		long long ans=a[0];
		for(long long i=1;i<n;i++) {
			ans=gcd(ans,a[i]);
		}
    	long long cnt = 0; 
    	for (long long i = 1;i<=sqrt(ans); i++) { 

        	if (ans % i == 0) { 
        	    if (ans/i==i) 
            	    cnt++;
 	           else  {
    	            cnt=cnt+2;
    	           } 

        	} 
    } 
    cout<<cnt<<endl;
	
	return 0;
}