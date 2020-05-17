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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll count=0;
    int arr[c-a];
    int len=c-a+1;
    int n=min(b-a,c-b);
    int m=max(b-a,c-b);

    for(int i=0;i<len;i++) {
        arr[i]=n+1;
    }
    for(int i=0;i<n;i++) {
        arr[i]=i+1;
    }
    for(int i=0;i<n;i++) {
        arr[len-1-i]=i+1;
    }

    ll ad[len];
    ad[len-1]=arr[len-1];
    for(int i=len-2;i>=0;i--) {
        ad[i]=ad[i+1]+arr[i];
        
    }
    // for(int i=0;i<len;i++) {
    //     cout<<ad[i]<<" ";
    // }
    // cout<<endl;
    // cout<<endl;
    for(int i=c;i<=d;i++) {
        if(i-a-b+1>=len) {
            break;
        }
        else if(i-a-b+1<0) {
            count=count+ad[0];
        }
        else 
        count=count+ad[i-a-b+1];
        // cout<<i<<" "<<count<<endl;
    }
    cout<<count<<endl;
    return 0;  
}   