#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define M 1000000007
std::vector<ll> v;
set<ll>s;
void solve() {
    ll n;
    cin>>n;
    ll sum=0;
    ll prev=0;
    for(auto i:v) {
        if(i==prev) {
            continue;
        }
        // cout<<i<<endl;
        prev=i;
        ll tp=i;
        if(tp>n) {
            break;
        }
        ll p=n-n%tp;
        p=p/tp;
        sum=(sum+((p%M)*(tp%M))%M)%M;
    }
    cout<<sum<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    ll t;
    cin>>t;
    
    v.push_back(1);
   
    ll limit=1000000000000;
    for(ll i=2;i*i<=limit;i++) {
       
        ll j=i*i;
        while(j<=limit) {
          
            v.push_back(j);
         
            j=j*i;
        }
    }
  
    sort(v.begin(),v.end());
    
    while(t--) {
        solve();
    }  
    return 0;
}   