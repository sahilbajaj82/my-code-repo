#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
const ll M=998244353;
ll dp[2001][2001];
int n,m,q;
ll a[2001];
ll findpath(int x,int y) {
	if(x==0&&y==0)
		return a[y];
	if(x<0||y<0) {
		return 0;
	}
	if(dp[x][y]!=-1) {
		return dp[x][y];
	}
	dp[x][y]=(a[y]*(findpath(x,y-1)+findpath(x-1,y)))%M;
	return dp[x][y];
}
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    
    cin>>m>>n>>q;
    
    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=0;i<2001;i++) {
    	for(int j=0;j<2001;j++) {
    		dp[i][j]=-1;
    	}
    }
    dp[m-1][n-1]=findpath(m-1,n-1);
    while(q--) {
    	int k;
    	cin>>k;
    	cout<<dp[k-1][n-1]<<endl;
    }
    return 0;  
}   