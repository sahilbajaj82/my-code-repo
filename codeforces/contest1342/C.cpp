#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
ll find(ll a,ll lcm,ll mx) {
    ll q=(a)/lcm;
    ll left=a%lcm+1;

    return q*(mx)+min(left,mx);
}
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
       ll a,b,q;
       cin>>a>>b>>q;
       if(b>a)
        swap(a,b);
        ll lcm=(a*b)/__gcd(a,b);
       while(q--) {
        ll l,r;
        cin>>l>>r;
        ll ans1=find(l-1,lcm,a);
        ll ans2=find(r,lcm,a);
        // cout<<ans1<<" "<<ans2<<endl;
        cout<<r-l+1-(ans2-ans1)<<" ";
        // cout<<lcm<<endl;
        // for(int i=l;i<=r;i++) {
        //     if((i%a-i%b+b)%b==0)
        //         cout<<i<<" ";
        // }
        // cout<<endl;
       }
       cout<<endl;
    }   
    return 0;  
}   