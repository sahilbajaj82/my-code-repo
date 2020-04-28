#include<bits/stdc++.h>
using namespace std;
bool prime[10000000+1];
void SieveOfEratosthenes(int n=10000000)
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
    SieveOfEratosthenes();
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int count=0,i=2;
        while(count!=n) {
            if(prime[i])
                count++;
            i++;
        }
        cout<<i-1<<endl;
    }
       
    return 0;
}
