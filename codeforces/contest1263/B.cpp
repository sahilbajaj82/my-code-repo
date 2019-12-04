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
    int t;
    cin>>t;
    while (t--) {   
        int n;
        cin>>n;
        string s[n],s1[n];
        for(int i=0;i<n;i++) {
            cin>>s[i];
            s1[i]=s[i];
        }
        sort(s,s+n);
        int a[10];
        for(int i=0;i<10;i++)
            a[i]=0;
        for(int i=0;i<n;i++) {
            a[s[i][3]-'0']++;
        }
        int c=0;
        for(int i=0;i<n;i++) {
            int count=1;
            for(int j=i+1;j<n;j++) {
                if(s[i]==s[j]) {
                    count++;
                    if(j==n-1) {
                        c+=count-1;
                        i=j;
                    }
                }
                else {
                    i=j-1;
                    c+=count-1;
                    break;
                }
            }
            
        }
        cout<<c<<endl;
        int m[10];
        for(int i=0;i<10;i++)
            m[i]=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(s1[i]==s1[j]) {
                    m[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(m[i]==0)
                cout<<s1[i]<<endl;
            else {
                for(int k=0;k<10;k++) {
                        if(a[k]==0) {
                            s1[i][3]=char(k+'0');
                            a[k]++;
                            break;
                        }
                    }
                    cout<<s1[i]<<endl;            }
        }
       
    }   
    return 0;  
}
