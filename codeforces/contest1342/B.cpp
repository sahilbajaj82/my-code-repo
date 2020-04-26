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
        string s;
        cin>>s;
        bool b1=true;
        int len=s.length();
        int count=0;
        for(int i=0;i<len;i++) {
            if(s[i]=='0'){
                count++;
            }
        }
        if(count==0||count==len) {
            cout<<s<<endl;
        }
        else {
            string t="";
            for(int i=0;i<len;i++) {
                t=t+"01";
            }
            cout<<t<<endl;
        }
    }   
    return 0;  
}   