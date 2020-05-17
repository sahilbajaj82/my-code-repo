#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
ll mindig(ll x) {
    stringstream ss;
    ss<<x;
    string s;
    ss>>s;
    sort(s.begin(),s.end());
    return s[0]-'0';
}
ll maxdig(ll x) {
    stringstream ss;
    ss<<x;
    string s;
    ss>>s;
    sort(s.begin(),s.end());
    return s[s.length()-1]-'0';
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
        ll a,k;
        cin>>a>>k;
        for(int i=0;i<k-1;i++) {
            ll h=mindig(a);
            if(h==0) {
                break;
            }
            a=a+h*maxdig(a);
        }
        cout<<a<<endl;
    }   
    return 0;  
}   