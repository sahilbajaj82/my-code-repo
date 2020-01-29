#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int t;
    cin>>t;
    while (t--) {   
        int n;
        cin>>n;
        pair<int,int>p[n];
        for(int i=0;i<n;i++){
        	cin>>p[i].F>>p[i].S;
        }
        sort(p,p+n);
        string s="";
        int x=0,y=0;
        int flag=1;
        for(int i=0;i<n;i++) {
        	if(p[i].F-x<0||p[i].S-y<0) {
        		flag=0;
        		break;
        	}
        	while(x!=p[i].F) {
        		s=s+"R";
        		x++;
        	}
        	while(y!=p[i].S) {
        		s=s+"U";
        		y++;
        	}
        }
        if(flag) {
        	cout<<"YES\n";
        	cout<<s<<endl;
        }
        else
        	cout<<"NO\n";
    }   
    return 0;  
}   