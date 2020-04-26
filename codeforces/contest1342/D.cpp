#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
ll find(ll a,ll lcm,ll mx) {
    ll q=(a)/lcm;
    ll left=a%lcm+1;

    return q*(mx)+min(left,mx);
}
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    
      int n,k;
      cin>>n>>k;
      int a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      int c[k];
      for(int i=0;i<k;i++) {
        cin>>c[i];
      }
      // cout<<c[9]<<endl;
      sort(a,a+n);
      int count[n]={0};
      int in=0;
      int max=0;
      vector<int> v[n];
      priority_queue<pair<int,int>>p;
      p.push(make_pair(0,0));
      for(int i=n-1;i>=0;i--) {
        pair<int,int> top=p.top();
        int x=-1*top.first;
        in=top.second;
        // cout<<x<<" "<<in<<" "<<c[a[i]-1]<<" "<<a[i]<<endl;
        if(x>=c[a[i]-1]) {
            max++;
            in=max;
            x=0;
        }
        else {
            p.pop();
        }
        // cout<<a[i]<<" "<<in<<" "<<c[a[i]-1]<<" "<<a[i]-1<<" "<<c[9]<<endl;
        
        v[in].push_back(a[i]);
        x++;
        p.push(make_pair(-1*x,in));
        // in=0;
      }
      cout<<max+1<<endl;
      for(int i=0;i<=max;i++) {
        cout<<v[i].size()<<" ";
        for(auto j:v[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
      }
    
    return 0;  
}   