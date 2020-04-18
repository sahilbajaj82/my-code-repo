#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;   
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll pf(ll n) {
    int c=0;
    while(n%2==0) {
        c++;
        n=n/2;
    }
    for(int i=3;i*i<=n;i=i+2) {
        while(n%i==0) {
            c++;
            n=n/i;
        }
    }
    if(n>2){
        c++;
    }
    return c;
}
int solve() {
    ll x,k;
    cin>>x>>k;
    if(k>34){
        return 0;
    }
    if(x<binpow(2,k)) {
        return 0;
    }
    int p=pf(x);
    if(p>=k)
        return 1;
    return 0;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cout<<solve()<<endl;
    }  
    return 0;
}   