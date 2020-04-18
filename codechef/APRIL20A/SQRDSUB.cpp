#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;   
ll cal(ll n) {
    return (n*(n+1))/2;
}
ll solve() {
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) {
        ll x;
        cin>>x;
        if(x%4==0) {
            a[i]=2;
        }
        else if(x%2==0) {
            a[i]=1;
        }
        else {
            a[i]=0;
        }
    }
    ll b[n],c[n];
    ll last=n;
    for(ll i=n-1;i>=0;i--) {
        b[i]=last;
        if(a[i]>0){
            last=i;
        }
    }
    ll first=-1;
    for(ll i=0;i<n;i++) {
        c[i]=first;
        if(a[i]>0) {
            first=i;
        }
    }
    ll count=(n*(n+1))/2;
    for(int i=0;i<n;i++) {
        if(a[i]==1) {
            ll left=i-c[i]-1;
            ll right=b[i]-i-1;
            ll tt=left+right+1;
            count=count-cal(tt)+cal(left)+cal(right); 
        }
    }
    return count;
}
int main() {
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int t;
    cin>>t;
    while(t--) {
        cout<<solve()<<endl;
    }  
    return 0;
}   