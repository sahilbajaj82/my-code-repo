#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    string s;
    cin>>s;
    int len=s.length();
    int count=0;
    string ans=s;
    for(int i=len-1;i>=0;i--) {
        if(s[i]=='1') {
            if(count==0)
                ans[i]='0';
            else {
                ans[i]='1';
                count--;
            }
        }
        else {
            count++;
            ans[i]='0';
        }
    }
    cout<<ans<<endl;
    return 0;
}
