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
    int n;
    cin>>n;
    while (n--) {   
       int p;
       cin>>p;
       vector<int> a;
       for(int i=0;i<p;i++) {
       		int x;
       		cin>>x;
       		a.push_back(x);
       }
       int count=0;
       sort(a.begin(),a.end());
       std::vector<int> v;
       for(int i=0;i<p;i++) {
       		if(binary_search(a.begin(),a.end(),a[i]-1)||binary_search(a.begin(),a.end(),a[i]+1)||binary_search(v.begin(),v.end(),a[i]-1)||binary_search(v.begin(),v.end(),a[i]+1)) {
       			continue;
       		}
       		else {
       			v.push_back(a[i]+1);
       			count++;
       		}
       }
     
       cout<<count<<endl;
    }   
    return 0;  
}   