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
        int n,a,b;
        cin>>n>>a>>b;
        string s="";
        for(int i=0;i<b;i++) {
        	s=s+char(i+'a');
        }
        for(int i=b;i<a;i++) {
        	s=s+'a';
        }
        for(int i=a;i<n;i++) {
        	s=s+s[i-a];
        }
        cout<<s<<endl;
    }   
    return 0;  
}   