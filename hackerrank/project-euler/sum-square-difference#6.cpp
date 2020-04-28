#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        long p=(n*(n+1))/2;
        p=p*p;
        long t=(n*(n+1)*(2*n+1))/6;
        cout<<p-t<<endl;
    }
    return 0;
}
