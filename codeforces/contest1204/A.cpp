#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    string s;
    int count=0;
    cin>>s;
    int len=s.length();
    count=len/2;
    if(len%2==1) {
    for(int i=1;i<len;i++) {
        if(s[i]=='1') {
            count++;
            break;
        }
    }
    }
    cout<<count<<endl;
    return 0;
}
