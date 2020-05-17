#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[2*n];
    if(n%2==1) {
        int j=n;
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                a[i]=2*(n-i);
                a[j+i]=2*(n-i)-1;
            }
            else {
                a[i]=2*(n-i)-1;
                a[j+i]=2*(n-i);
            }
        }
        cout<<"YES\n";
        for(int i=0;i<2*n;i++){
            cout<<a[i]<<" ";
        }
    }
    else {
        cout<<"NO"<<endl;
    }
    return 0;
}