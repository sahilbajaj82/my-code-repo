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
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        rep(i,n) cin>>v[i];
        sort(v.begin(),v.end());
        int count[210000];
        int cost[210000];
        for(int i=0;i<210000;i++)
        	count[i]=0,cost[i]=0;
        for(auto i:v) {
        	count[i]++;
        	int step=1;
        	int temp=i;
        	while(temp) {
        		temp=temp/2;
        		if(count[temp]<k) {
        			count[temp]++;
        			cost[temp]+=step;
        		}
        		else {
        			break;
        		}
        		step++;
        	}
        }
        ll min=LONG_MAX;
    	for(int i=0;i<210000;i++)
    		if(count[i]>=k) {
    			if(min>cost[i]) {
    				min=cost[i];
    			}
    		}
        cout<<min<<'\n';
    return 0;
}