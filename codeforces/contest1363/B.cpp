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
        int n,x;
        cin>>n>>x;
        int even=0;
        int odd=0;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            if(x%2)
                odd++;
            else
                even++;
        }
        bool flag=true;
        if(odd%2==0)
            odd--;
        if(odd<0)
            flag=false;
        if(x%2==0) {
            x--;
            even--;
            if(even<0){
                flag=false;
            }
        }
        x=x-odd;
        if(x>0) {
            if(even<x) {
                flag=false;
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
        // x=x-odd;
    }   
    return 0;  
}   
