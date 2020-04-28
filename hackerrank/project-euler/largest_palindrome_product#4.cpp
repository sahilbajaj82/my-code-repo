#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int palindrome(int n) {
    int a[6];
    for(int i=0;i<6;i++) {   
        a[i]=n%10;
        n=n/10;
    }
    if(a[0]==a[5]&&a[1]==a[4]&&a[2]==a[3])
        return 1;
    else
        return 0;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int max=0;
        for(int i=999;i>100;i--)
            for(int j=999;j>100;j--) {
                if(i*j<n)
                if(palindrome(i*j))
                    if(i*j>max)
                        max=i*j;
            }
        cout<<max<<endl;
       
        
    }
    return 0;
}
