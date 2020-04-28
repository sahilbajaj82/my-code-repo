#include<bits/stdc++.h>
using namespace std;
bool prime[1000001];
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

int main() {
    SieveOfEratosthenes();
    int t;
    cin>>t;
    long b[1000001]={0};
    prime[1]=false;
    int j=0;
    while(t--) {
        int n;
        cin>>n;
        long sum=0;
        if(n<j)
            sum=b[n];
        else { sum=b[j];
        for(int i=j+1;i<=n;i++)
        {    
            if(prime[i]) {
                
                sum=sum+i;
            }
            b[i]=sum;
            
        }
             j=n;
        }
        cout<<sum<<endl;
    }
    return 0;
}
