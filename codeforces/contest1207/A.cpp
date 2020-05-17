#include<bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin>>t;
  while(t--) {
    int n,e,f;
    cin>>n>>e>>f;
    n=n/2;
    int h,c;
    cin>>h>>c;
    long long profit=0;
    if(h>c) {
      if(e>n) {
        profit=profit+h*n;
      }
      else {
        profit=profit+h*e;
        n=n-e;
        profit+=min(n,f)*c;
      }
    }
    else {
      if(f>n) {
        profit=profit+c*n;
      }
      else {
        profit=profit+c*f;
        n=n-f;
        profit+=min(n,e)*h;
      }

    }
    cout<<profit<<endl;
  }
  return 0;
}
