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
       int n,xs;
       cin>>n>>xs;
       std::vector<int> v[n+1];
       for(int i=0;i<n-1;i++) {
       	int x,y;
       	cin>>x>>y;
       	v[x].push_back(y);
       	v[y].push_back(x);
       }
       int flag=false;
       if(n%2==1) {
       	flag=true;
       }
       if(v[xs].size()<=1) {
       		flag=false;
       }
       if(flag) {
       	cout<<"Ashish\n";
       }
       else {
       	cout<<"Ayush\n";
       }

    }   
    return 0;  
}   
