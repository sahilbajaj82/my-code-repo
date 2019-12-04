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
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]<a[2]) {
            cout<<a[1]+a[0]<<endl;
        }
        else {
            int s=a[2]-a[1];
            s=min(s,a[0]);
            a[2]=a[2]-s;
            a[0]=a[0]-s;
            a[2]-=ceil(a[0]/2);
            a[1]-=floor(a[0]/2);
            cout<<min(a[1],a[2])+(a[0]/2)*2+s<<endl;
        }
 
    }   
    return 0;  
}   
