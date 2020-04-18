#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int main() {
    
    ll t;
    cin>>t;
    ll j=0;
    while (j<t) {   
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll b[n];
        priority_queue <pair<ll,pair<ll,int>>>pq;
        for(ll i=0;i<n-1;i++){
            b[i]=a[i+1]-a[i];
            pq.push(make_pair(b[i],make_pair(b[i],1)));
        }
        while(k>0){
            pair<ll,pair<ll,int>>temp=pq.top();
            pq.pop();

            ll pp=temp.S.F;
            ll val=temp.S.S;
            //cout<<temp.F<<" "<<pp<<" "<<val<<endl;
            val++;
            int gap=pp/val;
            if(pp%val)
                gap++;
            pq.push(make_pair(gap,make_pair(pp,val)));
            k--;
        }
        cout<<"Case #"<<j+1<<": "<<(pq.top()).F<<endl;
    	j++;
    }
    return 0;  
}   