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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int gp=0;
        int gs=0;
        for(int i=0;i<n;i++) {
            if(a[i]<=gs+1) {
                gp++;
                gs=0;
            }
            else{
                gs++;
            }
        }
        cout<<gp<<endl;
    }   
    return 0;  
}   