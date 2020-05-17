#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,m;
  cin>>n>>m;
  int a[n][m];
  int b[n][m];
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) {
      cin>>a[i][j];
      b[i][j]=0;
    }
  std::vector<int> v1;
  std::vector<int> v2;
  for(int i=0;i<n-1;i++) {
    for(int j=0;j<m-1;j++) {
      int flag=1;
      for(int k=i;k<i+2;k++) {
        for(int h=j;h<j+2;h++) {
          if(a[k][h]==0) {
            flag=0;
          }
        }
      }
      if(flag==1) {
        v1.push_back(i+1);
        v2.push_back(j+1);
        for(int k=i;k<i+2;k++) {
          for(int h=j;h<j+2;h++) {
              b[k][h]=1;
          }
        }
      }
    }
  }
  int flag=1;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++) {
      if(a[i][j]!=b[i][j])
        flag=0;
    }
  if(flag==0) {
    cout<<"-1\n";
  }
  else {
    cout<<v1.size()<<endl;
    for(int i=0;i<v1.size();i++) {
      cout<<v1[i]<<" "<<v2[i]<<endl;
    }
  }
  return 0;
}
