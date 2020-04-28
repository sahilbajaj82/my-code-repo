#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,a;
    cin>>n;unsigned long long sum=0;
    for(;n>0;n--)
    { int i;
    cin>>a;
    sum=0;
    long p;
     p=(a-1)/3;
     long q=(a-1)/5;
     long r=(a-1)/15;
     cout<<(3*p*(p+1)+5*q*(q+1)-15*r*(r+1))/2<<endl;
    }/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

