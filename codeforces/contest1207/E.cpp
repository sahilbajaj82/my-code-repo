#include<bits/stdc++.h>
using namespace std;
int main() {
//  cout<<(5^128);
  cout<<"? ";
  for(int i=1;i<=100;i++) {
    cout<<(i)<<" ";
  }
  fflush(stdout);
  cout<<endl;
  int x;
  cin>>x;
  cout<<"? ";
  for(int i=1;i<=100;i++) {
    cout<<(i<<7)<<" ";
  }
  fflush(stdout);
  cout<<endl;
  int y;
  cin>>y;
  int ans=x^y;
  ans=(ans>>7);
  ans=(ans<<7);
  //cout<<ans<<endl;
  cout<<"! "<<(ans^y)<<endl;
  return 0;
}
