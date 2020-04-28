#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    long f[10];
    f[0]=1;
    for(int i=1;i<10;i++)
        f[i]=f[i-1]*i;
    long ans=0;
    for(int i=10;i<n;i++) {
        long sum=0;
        long t=i;
        while(t!=0) {
            sum=sum+f[t%10];
            t/=10;
        }
       // cout<<i<<" "<<sum<<endl;
        if(sum%i==0) {
            //cout<<i<<endl;
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}