#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  int t;
  cin>>t;
  while(t--) {
    ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll cost=b;
    int count1=1,count2=1;
    int level=1;
    for(int i=0;i<n-1;i++) {
      if(s[i+1]=='1') {
        if(level==1) {
          level=2;
          cost=cost+2*b+2*a;
        }
        else {
          cost+=2*b+a;
        }
      }
      else {
        if(level==1) {
          cost=cost+b+a;
        }
        else {
          int findone=i;
          for(int j=i+1;j<n;j++) {
            if(s[j]=='1') {
              findone=j;
              break;
            }
          }
          if(findone==i) {
            if(s[i]=='1') {
              cost=cost+a+2*b;
            }
            else {
              cost=cost+2*a+b;
              level=1;
            }
          }
          else {
            int interval=findone-i-1;
            if(interval==1) {
              cost=cost+2*b+a;
            }
            else {
              if(interval*(a+2*b)>(interval+2)*a+(interval-1)*b+2*b) {
                cost=cost+(interval+2)*a+(interval-1)*b+2*b+a+2*b;
                i=findone-1;
              }
              else {
                cost=cost+interval*(a+2*b)+a+2*b;
                i=findone-1;
              }

            }
          }
        }
      }
    //  cout<<i<<" "<<level<<" "<<cost<<endl;
    }
    if(level==1) {
      cost=cost+a+b;
    }
    else {
      cost=cost+2*a+b;
    }
    cout<<cost<<endl;
  }
  return 0;
}
