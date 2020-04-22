#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int t;
    cin>>t;
    while (t--) {   
        long long n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++){
        	cin>>a[i];
        }
        ll sum=0;
        bool sign=false;
        if(a[0]>0)
        	sign=true;
        ll mn=-1*INT_MAX;
        ll mx=0;
        for(int i=0;i<n;i++) {
        	if(a[i]>0) {
        		if(sign==false) {
        			sum=sum+mn;
        			mn=-1*INT_MAX;
        			mx=0;
        			sign=true;
        		}
        		mx=max(mx,a[i]);
        		if(i==n-1) {
        			sum=sum+mx;
        		}
        	}
        	else {
        		if(sign==true) {
        			sum=sum+mx;
        			mn=-1*INT_MAX;
        			mx=0;
        			sign=false;
        		}
        		mn=max(mn,a[i]);
        		if(i==n-1) {
        			sum=sum+mn;
        		}
        	}
        	// cout<<sum<<" ";
	    }

	    cout<<sum<<endl;
    }   
    return 0;  
}   