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
    int t;
    cin>>t;
    while (t--) {   
        int n;
        cin>>n;
        set<int> s;
        // s.insert(n);
        int j=n;
        int flag=1;
        int p=n;
        int l=sqrt(p)+1;
        for(int i=1;i<=l;i++) {
        	s.insert(p/i);
        }
        j=*s.upper_bound(0);
        // s.insert(n);
        int q=1;
        while(j!=0) {
        	q=(n/j)-n/(j+1);
        	if(q==0) {
        		j--;
        	}
        	else {
        		s.insert(j);
        		j--;
        		// n=n-q;
        	}
    	}
        s.insert(0);
        // sort(s,s+s.size());
        cout<<s.size()<<endl;
        for(auto i:s) {
        	cout<<i<<" ";
        }
        cout<<endl;
    }   
    return 0;  
}   
