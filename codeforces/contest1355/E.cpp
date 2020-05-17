#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
ll ar[100001];
ll n,a,r,m1;
ll value(ll m,ll n,ll tot) {
    ll br[n];
    for(int i=0;i<n;i++)
        br[i]=ar[i];
    ll bricks=m*n;
    ll zero=0;
    ll opcost=max(zero,bricks-tot)*a+max(zero,tot-bricks)*r;
    // cout<<m<<" "<<opcost<<"\n";
    ll abb=abs(bricks-tot);
    int left=0;
    int right=n;
    // cout<<abb<<endl;
    if(bricks-tot>0) {
        // cout<<"x";
        for(int i=0;i<n;i++) {
            if(br[i]+abb<m) {
                br[i]+=abb;
                abb=0;
                break;
            }
            else {
                  abb=abb-m+br[i];
                br[i]=m;
              
                left=i+1;
            }
        }
    }
    else if(bricks-tot<0) {
        for(int i=n-1;i>=0;i--) {
            if(br[i]-abb>m) {
                br[i]-=abb;
                abb=0;
                break;
            }
            else {
                abb=abb+m-br[i];
                br[i]=m;
                
                right=i;
            }
        }
    }
    // for(int i=0;i<n;i++) {
    //     cout<<br[i]<<" ";
    // }
    // cout<<opcost<<endl;
    if(a+r<m1) {
        for(int i=0;i<n;i++) {
            if(br[i]<m) {
                opcost+=(m-br[i])*a;
            }
            else {
                opcost+=(br[i]-m)*r;
            }
        }
    }
    else {
        int ss=0;
        int ee=n-1;
        while(ee>=ss) {
            ll cc=m-br[ss];

            ll dd=br[ee]-m;
    //         cout<<opcost<<" ";
    //         for(int i=0;i<n;i++) {
    //     cout<<br[i]<<" ";
    // }
    // cout<<endl;
        
            if(cc>dd) {
               
                br[ss]+=dd;
                br[ee]=m;
                 ee--;

            }
            else {
                br[ee]-=cc;
                br[ss]=m;
                 ss++;
            }
            opcost+=min(cc,dd)*m1;
            // cout<<ss<<" "<<cc<<" "<<dd<<" "<<opcost<<" "<<min(cc,dd)<<endl;
         }   
    }
    return opcost;
}

int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
   
    cin>>n>>a>>r>>m1;
    
    ll tot=0;
    for(int i=0;i<n;i++) {
        cin>>ar[i];
        tot+=ar[i];
    }
    sort(ar,ar+n);
    ll op=0;
    int left=ar[0];
    int right=ar[n-1];
    while(right>=left) {
        int mid=(right+left)/2;
        ll cal=value(mid,n,tot);
        // cout<<mid<<" "<<cal<<endl;
        ll le=LLONG_MAX;
        if(mid!=ar[0])  {
         le=value(mid-1,n,tot);
         // cout<<mid-1<<" "<<le<<endl;
        }
        if(le<cal) {
            op=le;
            right=mid-1;
        }
        else {
            op=cal;
            left=mid+1;
        }
    }
    cout<<op<<endl;
    
    return 0;  
}   