/*  https://codeforces.com/contest/1267/problem/E */
#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int n,m;
    cin>>n>>m;
    int a[101][101];
    int s[101]={};
    for(int i=0;i<m;i++) {
    	for(int j=0;j<n;j++) {
    		cin>>a[i][j];
    		s[j]+=a[i][j];
    	}
    }
    int mincount=INT_MAX;
    string ans="";
    for(int i=0;i<n-1;i++) {
    	// cout<<i<<endl<<endl;
    	int count=0;
    	pair<int,int> b[m];
    	for(int j=0;j<m;j++) {
    		b[j].first=a[j][i]-a[j][n-1];
    		b[j].second=j;
    	}
    	sort(b,b+m);
    	int x=s[i],y=s[n-1];
    	string ss="";
    	// cout<<y-x<<endl;
    	while(y-x>0) {
    		y=y-a[b[count].second][n-1];
    		x=x-a[b[count].second][i];
    		// cout<<y-x<<endl;
    		ss=ss+to_string(b[count].second+1)+" ";
   			count++;
    	}
    	if(count<=mincount) {
    		ans=ss;
    		mincount=count;
    	}
    	// cout<<endl;
    }
    cout<<mincount<<endl;
    cout<<ans<<endl;
    return 0;  
}   