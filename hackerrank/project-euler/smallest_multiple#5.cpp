#include <bits/stdc++.h>
using namespace std;
bool prime[101];
void SieveOfEratosthenes(int n=100)
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

int main() {
    int t;
    cin>>t;
    SieveOfEratosthenes(50);
    while(t--) {
        long a[41];
        int n;
        cin>>n;
        long p=1;
        for(int i=1;i<=n;i++)
            a[i]=i;
        for(int i=2;i<=n;i++) {
            if(prime[i])
                a[i]=a[i-1]*i;
            else {
                int j;
                for(j=1;j<=n;j++)
                    if(((a[i-1]*j)%i)==0)
                        break;
                a[i]=a[i-1]*j;
            }
        }
        cout<<a[n]<<endl;
        
        
    }
    return 0;
}
