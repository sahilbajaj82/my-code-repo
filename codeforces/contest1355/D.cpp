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
    int n,s;
    cin>>n>>s;
    int left=n-1;
    int right=s-left;
    if(n>=right) {
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
        for(int i=0;i<n-1;i++) {
            cout<<"1 ";
        }
        cout<<right<<endl;
        cout<<n<<endl;
    }
    return 0;  
}   