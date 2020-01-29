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
    	  ll n;
    	  cin>>n;
    	  std::vector<int> v;
    	  set<int>s;
    	  ll temp=n;
    	  while(temp%2==0){
    	  	v.push_back(2);
    	  	temp/=2;
    	  }  
    	  for(int i=3;i<=sqrt(n);i=i+2) {
    	  	while(temp%i==0){
    	  		v.push_back(i);
    	  		temp/=i;
    	  	}
    	  }
    	  if(temp>2){
    	  	v.push_back(temp);
    	  }
    	  sort(v.begin(),v.end());
    	  // for(auto i:v){
    	  // 	cout<<i<<" ";
    	  // }
    	  // cout<<endl;
    	  int flag=1;
    	  if(v.size()<3) {
    	  		flag=0;
    	  }
    	  else if(v.size()==3) {
    	  	if(v[0]==v[1]||v[0]==v[2]||v[1]==v[2]){
    	  		flag=0;
    	  	}
    	  }
    	  else if(v.size()<6) {
    	  	int h=1;
    	  	for(int i=0;i<v.size()-1;i++) {
    	  		if(v[i]!=v[i+1])
    	  			h=0;
    	  	}
    	  	if(h==1)
    	  		flag=0;
    	  }
    	  if(flag==0) {
    	  	cout<<"NO\n";
    	  }
    	  else {
    	  	cout<<"YES\n";
    	  	cout<<v[0]<<" ";
    	  	int g;
    	  	if(v[0]==v[1]){
    	  		g=v[1]*v[2];
    	  	}
    	  	else
    	  		g=v[1];
    	  	cout<<g<<" "<<(n/v[0])/g<<endl;
    	  }
    }   
    return 0;  
}   