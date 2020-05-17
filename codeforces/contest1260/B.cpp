
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
        ll a,b;
        cin>>a>>b;
        int flag=1;
        if(((a+b)%3)!=0) {
            flag=0;
        }
        if(a==0&&b!=0) {
            flag=0;
        }
        if(b==0&&a!=0) {
            flag=0;
        }
        if(a>b) {
            if(a>2*b)
                flag=0;
        }
        else {
            if(b>2*a)
                flag=0;
        }
        if(flag)
            cout<<"YES\n";
        else {
            cout<<"NO\n";
        }
    }   
    return 0;  
}   