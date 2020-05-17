
#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int n;
    cin>>n;
    while (n--) {   
        ll c,sum;
        cin>>c>>sum;
        long long cost=0;
        ll mod=sum%c;
        ll x=sum/c;
        cost=x*x*(c-mod)+mod*(x+1)*(x+1);
        cout<<cost<<endl;
    }   
    return 0;  
}   