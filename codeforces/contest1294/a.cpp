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
        ll a[3],n;
        cin>>a[0]>>a[1]>>a[2]>>n;
        sort(a,a+3);
        n=n-(a[2]-a[1]);
        n=n-(a[2]-a[0]);
        if(n%3==0&&n>=0){
        	cout<<"YES\n";
        }
        else
        	cout<<"NO\n";
        
    }   
    return 0;  
}   