#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a[3001];
    for(int i=0;i<3001;i++)
        a[i]=-1;
    for(int n=1;n<3001;n++)
        if(n%2==0)
        for(int i=3;i<n;i++) {
            for(int j=i+1;j<n-i-j;j++) {
                int s=i*i+j*j-(n-i-j)*(n-i-j);
                if(s==0) {
                    if(i*j*(n-i-j)>a[n])
                        a[n]=i*j*(n-i-j);     
                }
                else if(s>0){
                    break;    
                }
            }
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