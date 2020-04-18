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
        ll a,n,m;
        cin>>a>>n>>m;
        bool flag=true;
        while(n>0) {
        	if(a/2+10>=a) {
        		break;
        	}
        	// cout<<a<<endl;
        	a=a/2+10;
        	n--;
        	
        }
    
        bool ans=false;
        if(a-m*10<=0) {
        	cout<<"YES\n";
        }
        else
        	cout<<"NO\n";
        // cout<<b<<" "<<c<<" "<<c<<endl;
    }   
    return 0;  
}   