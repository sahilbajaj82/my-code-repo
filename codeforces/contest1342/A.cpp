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
        ll x,y;
        cin>>x>>y;
        ll a,b;
        cin>>a>>b;
        if(x==0&&y==0) {
            cout<<"0\n";
        }
        else {
            if(y>x) {
                swap(x,y);
            }
            
            ll c=(x-y)*a+y*b;
            ll d=(x+y)*a;
             cout<<min(c,d)<<endl;
        }
    }   
    return 0;  
}   