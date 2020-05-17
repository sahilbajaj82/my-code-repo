// Created by Sahil Bajaj Codeforces handle: sahil.bajaj
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
       	ll n,m;
       	cin>>n>>m;
       	ll mm=m%10;
       	ll co=n/m;
       	ll sum=0;
       	for(int i=0;i<10;i++) {
       		sum+=(mm*i)%10;
       	}
       	// cout<<sum<<endl;
       	ll ju=co/10;
       	ll jr=co%10;
       	ll ans=sum*ju;
       	for(int i=0;i<=jr;i++) {
       		ans+=(mm*i)%10;
       	}
       	cout<<ans;
        cout<<'\n';
    }
    return 0;
}