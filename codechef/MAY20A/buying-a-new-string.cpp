#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
ll cs(string const& a,string const&b,ll p) {
    int count=0;
    int len=a.length(),len1=b.length();
    for(int i=0;i<len-len1+1;i++) {
        int flag=true;
        for(int j=0;j<len1;j++) {
            if(a[i+j]!=b[j]) {
                flag=false;
                break;
            }
        }
        if(flag)
            count++;
    }
    return count*p;
}

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
    	string a,b;
    	cin>>a>>b;
    	int n;
    	cin>>n;
    	pair<ll,string> p[n];
    	for(int i=0;i<n;i++) {
    		cin>>p[i].second;
    		cin>>p[i].first;
    	}   
        ll points=0;
        for(int i=0;i<=a.length();i++) {
            for(int j=0;j<=b.length();j++) {
                string temp=a.substr(0,i)+b.substr(j,b.length());
                ll po=0;
                for(int h=0;h<n;h++) {
                    po+=cs(temp,p[h].second,p[h].first);
                }
                if(po>points)
                    points=po;
            }
        }
    	cout<<points<<endl;
    }   
    return 0;  
}   