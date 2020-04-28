#include<bits/stdc++.h>
using namespace std;
bool prime[1000000+1];
void SieveOfEratosthenes(int n=1000000)
{
    
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
       
        if (prime[p] == true)
        {
           
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
}
int primecheck(long a)
{
    int flag=1;
    if(a==2)
        return flag;
    if(a%2==0)
        return 0;
    for(long i=3;i<=sqrt(a);i=i+2)
        if(a%i==0)
        {flag=0;break;}
    
    return flag;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        long n,p;
        cin>>n;
        if(primecheck(n))
            p=n;
        else {
            long a=sqrt(n);
            for(int i=2;i<=a;i++) {
                if(n%i==0) {
                    if(primecheck(n/i)) {
                        p=n/i;
                        break;
                    }
                    if(primecheck(i))
                        p=i;
                }
            }
        }
        cout<<p<<endl;
        
    }
  
}