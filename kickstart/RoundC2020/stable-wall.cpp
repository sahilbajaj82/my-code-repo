#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
void solve() {
	int n,m;
    cin>>n>>m;
    string s[n];
    int ch[26]={0};
    for(int i=0;i<n;i++) {
        cin>>s[i];
        for(int j=0;j<m;j++) {
            ch[s[i][j]-'A']=1;
        }
    }

    int stable=0;
    int a[31][31];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++)
            a[i][j]=0;
    }
    int count=n*m;
    int fla=0;
    string ans="";
    while(count!=0) {
        int flag=0;
        int let=0;
        for(int i=0;i<26;i++) {
            if(ch[i]==0){
                continue;
            }
            char c=char(i+'A');
            // cout<<c<<endl;
            int ff=1;
            for(int j=n-2;j>=0;j--) {
                for(int k=0;k<m;k++) {
                    if(s[j][k]==c) {
                        if((a[j+1][k]==1)||s[j+1][k]==c) {
                             continue;
                         }
                         else {
                        // cout<<c<<endl;
                             ff=0;
                         break;
                         }
                     }
                }
            }
            if(ff==1) {
                // cout<<"x";
                ch[i]=0;
                flag=1;
                ans=ans+c;
                for(int k=0;k<n;k++) {
                    for(int j=0;j<m;j++) {
                        if(s[k][j]==c) {
                            count--;
                            a[k][j]=1;
                        }
                    }
                }
            }

        }
        if(flag==0) {
            fla=1;
            break;
        }
    }
    if(fla==1) {
        cout<<"-1"<<endl;
        // cout<<ans<<endl;
    }
    else {
        cout<<ans<<endl;
    }
}
int main() {   
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
    	 cout<<"Case #"<<i+1<<": ";
    	 solve();
    }
    return 0;  
}   
