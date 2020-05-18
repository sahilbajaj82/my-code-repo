#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fac[1001],mod=1000000007;
ll fastmod(ll  base,ll p)
{
    if(p ==0)
        return 1;
    else if(p&1)
        return (base*fastmod(base,p-1))%mod;
    else
    {
        ll k =  fastmod(base,p/2);
        return (k*k)%mod;
    }
}
ll nCr(ll n, ll r) {
	ll a = fac[n],b = fac[n-r],c = fac[r];
	a = (a*fastmod(b,mod-2))%mod;
	a = (a*fastmod(c,mod-2))%mod;
	return a;
}	
void fac1() {
	fac[0]=1;
	for(int i=1;i<=1000;i++)
		fac[i] = (fac[i-1]*i)%mod;
}
int main() {
	fac1();
	int t;
	cin>>t;
	ll a,b,c;
	while(t--) {
		cin>>a>>b>>c;
		ll aa = a,bb = b,cc= c;
		ll ans = 0;
		ll dp = 0;
		ll dp1[1001];
		
		for(int i=1;i<=b;i++)
			dp1[i] = (dp1[i-1]+nCr(b,i))%mod;
		dp = fastmod(2,cc);
		dp = (dp + mod -1)%mod;//cout<<dp<<endl;
		for(int i=a;i>=2;i--) {
			ll ta = nCr(a,i),ta2 = 0;//cout<<ta<<endl;	
			if(b>=i)
				b = i-1;
			if(b==0) break;
			ll dp2 = (ta*dp1[b])%mod;//cout<<dp2<<endl;
			ans = (ans+dp2)%mod;
				
		}
		ans = (ans*dp)%mod;
		cout<<ans<<endl;

	}
	return 0;
}
