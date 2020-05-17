#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll n,l,r;
    cin>>n>>l>>r;
    long max=0,min=0;
    min=pow(2,l)-1+(n-l);
    max=pow(2,r)-1+(n-r)*pow(2,r-1);
    cout<<min<<" "<<max<<endl;
    return 0;
}
