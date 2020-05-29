#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
long double ab(long double y) {
    if(y<0) {
        return -y;
    }
    return y;
}
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
        ll c,h,t;
        cin>>h>>c>>t;
        ll tot=0;
        if(2*t-h-c<=0) {
            cout<<"2\n";
        }
        else {
            // for(int i=0;i<20;i++) {
            //     if(i%2)
            //         tot+=c;
            //     else
            //         tot+=h;
            //     cout<<ab(double(tot)/(i+1)-t)<<"\n";
            // }
            ll val=2*t-h-c;
            ll dd=(h-t)/val;
            long double x=((long double)((dd+1)*h+dd*c))/(2*dd+1);
            long double y=((long double)((dd+2)*h+(dd+1)*c))/(2*dd+3);
            // cout<<x-t<<" "<<ab(y-t)<<endl;
            if(ab(x-t)<=ab(y-t)) {
                cout<<2*dd+1<<endl;
            }
            else {
                cout<<2*dd+3<<endl;
            }
        }
    }   
    return 0;  
}   
