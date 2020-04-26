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
    // #ifndef ONLINE_JUDGE   
    // freopen("input.txt", "r", stdin);   
    // freopen("output.txt", "w", stdout);
    // #endif   
    int t;
    cin>>t;
    string s;
    cin>>s;
    int len=s.length();
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout<<s<<endl;
    int a[len+1][26];
    for(int i=0;i<26;i++) {
        a[0][i]=0;
    }
    for(int i=0;i<len;i++) {
        for(int j=0;j<26;j++) {
            a[i+1][j]=a[i][j];
        }
        a[i+1][s[i]-'a']++;
        
    }
    // for(int i=0;i<=len;i++) {
    //     cout<<i<<" : ";
    //     for(int j=0;j<26;j++) {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int q;
    cin>>q;
    while(q--) {
        int x,y;
        cin>>x>>y;
        int max=0;
        for(int i=25;i>=0;i--) {
            if(a[y+1][i]-a[x][i]>0) {
                max=a[y+1][i]-a[x][i];
                break;
            }
        }
        cout<<max<<endl;
    }

    return 0;  
} 