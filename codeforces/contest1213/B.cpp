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
        int n;
        cin>>n;
        vector<int> v(n);
        rep(i,n) cin>>v[i];
        int ar[n+1];
        int count=0;
        ar[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--) {
        	if(v[i]<ar[i+1]) {
        		ar[i]=v[i];
        	}
        	else
        		ar[i]=ar[i+1];
        }
        for(int i=0;i<n;i++) {
        	if(v[i]>ar[i])
        		count++;
        }
		cout<<count;    
        cout<<'\n';
    }
    return 0;
}