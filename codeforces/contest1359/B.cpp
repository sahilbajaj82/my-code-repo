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
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        string s[n];
        ll cost=0;
        for(int i=0;i<n;i++)
            cin>>s[i];
        if(2*x>y) {
            for(int i=0;i<n;i++) {
                for(int j=1;j<m;j++) {
                    if(s[i][j]=='.'&&s[i][j-1]=='.') {
                        cost+=y;
                        s[i][j]='*';
                        s[i][j-1]='*';
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(s[i][j]=='.') {
                    cost+=x;
                }
            }
        }
        cout<<cost<<endl;
    }   
    return 0;  
}   
