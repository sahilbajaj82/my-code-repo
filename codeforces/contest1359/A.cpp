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
        int n,m,k;
        cin>>n>>m>>k;
        int mx=n/k;
        int rem=max(0,m-mx);
        int rec=min(mx,m);
        int p=k-1;
        int mm=ceil((double)rem/p);
        cout<<rec-mm<<endl;
    }   
    return 0;  
}   
