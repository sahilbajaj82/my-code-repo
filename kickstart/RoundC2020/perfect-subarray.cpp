#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
bool isperfect(int n) {
    if(n<0)
        return false;
    int p=sqrt(n);
    if(p*p==n)
        return true;
    return false;
}
vector<int>ps;
void solve() {
	int n;
    cin>>n;
    int ar[n];
    int pre[n+1];
    for(int i=0;i<n;i++)
        cin>>ar[i];
    // pre[0]=0;
    // for(int i=1;i<=n;i++) {
    //     pre[i]=pre[i-1]+ar[i-1];
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    int count=0;
    for(int i=0;i<n;i++) {
        ll temp=ar[i];
        if(isperfect(temp))
            count++;
        for(int j=i+1;j<n;j++) {
            temp+=ar[j];
            // cout<<temp<<endl;
            if(isperfect(temp))
            count++;
        }
    }
    cout<<count<<endl;

}
int main() {   
    for(int i=0;i<10000;i++) {
        ps.push_back(i*i);
        if(ps[i]>1e7) {
            break;
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
    	 cout<<"Case #"<<i+1<<": ";
    	 solve();
    }
    return 0;  
}   
