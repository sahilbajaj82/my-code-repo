/*  https://codeforces.com/contest/1267/problem/L */
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
    int n,l,k;
    cin>>n>>l>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    string ans[n];
    int a[26]={};
    for(int i=0;i<s.length();i++) {
    	a[s[i]-'a']++;
    }
    for(int i=0;i<k;i++) {
    	ans[i]="";
    	ans[i]=ans[i]+s[i];
    }
    int pos=k;
    int end=s.length()-1;
    string c=ans[k-1];
    int it=0;
    int x=0;
    for(int j=1;j<l;j++) {
    	for(int i=x;i<k;i++) {
    		if(ans[k-1]>ans[i]) {
    			for(int m=end;m>end-(l-j);m--)
    				ans[i]=ans[i]+s[m];
    			end=end-(l-j);
    			x=i+1;	
    		}
    		else {
    			ans[i]=ans[i]+s[pos++];
    		}
    	}
	}
	for(int i=k;i<n;i++) {
		ans[i]="";
		for(int j=0;j<l;j++){
			ans[i]=ans[i]+s[pos++];
		}
	}
    sort(ans,ans+n);
    for(int i=0;i<n;i++){
    	cout<<ans[i]<<endl;
    }
    return 0;  
}   