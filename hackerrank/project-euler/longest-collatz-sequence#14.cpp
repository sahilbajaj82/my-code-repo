#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int b[5000001]={0};
int collatz(long n){
    if(n<5000001)
    if(b[n])
        return b[n];
    if(n==1)
        return 0;
    if((n&1)==0)
        return 1+collatz(n/2);
    else
        return 1+collatz(3*n+1);
}

int main() {
    int a[5000001];
    int max=0;
    int j=1;
    for(int i=1;i<=5000001;i++) {
        int n=collatz(i);
        b[i]=n;
        if(n>=max) {
            max=n;
            j=i;
        }
        a[i]=j;
       
    }
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<a[n]<<endl;
       
    } 
    return 0;
}
