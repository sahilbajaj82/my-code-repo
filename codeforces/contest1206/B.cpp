#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    //sort(a,a+n);
    int count=0,count1=0,count2=0;
    // int nsmall=INT_MAX,psmall=INT_MAX;
    for(int i=0;i<n;i++) {
        if(a[i]<0)
            count++;
        else if(a[i]==0)
            count1++;
    }
    long long cost=0;
    for(int i=0;i<n;i++) {
        if(a[i]>0) {
            cost=cost+abs(a[i]-1);
        }
        else if(a[i]<0){
            cost=cost+abs(1+a[i]);
        }
        else {
            cost++;
        }
    }
    if((count%2)==1&&count1==0) {
        cost=cost+2;
    }
    cout<<cost<<endl;
    return 0;
}