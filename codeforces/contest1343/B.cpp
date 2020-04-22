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
        long long n;
        cin>>n;
        if(n%4==0) {
        	int st=2;
        	cout<<"YES\n";
        	for(int i=0;i<n/2;i++) {
        		cout<<st<<" ";
        		st+=4;
        	}
        	st=2;
        	for(int i=0;i<n/2;i++) {
        		if(i%2) {
        			// st-=1;
        			cout<<st-1<<" ";
        		}
        		else {
        			// st+=1;
        			cout<<st+1<<" ";
        		}
        		st=st+4;
        	}
        	cout<<endl;
        }
        else {
        	cout<<"NO\n";
        }
    }   
    return 0;  
}   