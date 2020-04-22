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
        long long n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)
        	cin>>a[i];
        unordered_map<ll,ll>m1;
        
        int table1[2*k+2]={0};
        int table2[2*k+2]={0};
        for(int i=0;i<n/2;i++) {
        	m1[a[i]+a[n-i-1]]++;
        	table2[max(a[i],a[n-1-i])+k]++;
        	table1[min(a[i],a[n-1-i])+1]++;
        }
        ll mn=n/2;

        for(int i=1;i<=2*k+1;i++) {
        	table2[i]=table2[i-1]+table2[i];
        }
        for(int i=2*k;i>=0;i--) {
        	table1[i]=table1[i]+table1[i+1];
        }
        //   for(int i=2*k;i>=0;i--) {
        // 	table2[i]=table2[i]+table2[i+1];
        // }
      	// for(int i=0;i<=2*k+1;i++) {
      	// 	cout<<i<<" "<<table1[i]<<" "<<table2[i]<<endl;
      	// }
      	// // sort(m1.begin(),m1.end());
        for(auto i:m1) {
        	// int c1=upper_bound(v2.begin(),v2.end(),i.first-1)-v2.begin();
        	// cout<<i.first<<" "<<i.second<<endl;
        	int count=table1[i.first+1]+table2[i.first-1];
        	// cout<<i.first<<" "<<count<<" "<<table1[i.first-1]<<" "<<table2[i.first-1]<<endl;
        	mn=min(mn,count*2+(n/2-count-i.second)),n/2;
        }
        
        cout<<mn<<endl;
    }   
    return 0;  
}   