#include <bits/stdc++.h>   
using namespace std;   
using ll =unsigned long long;
using fll =__int128;
#define F first
#define S second
#define pb push_back
const ll N=64;
string printbs(fll x) {
	bitset<N> bset1(x);
	stringstream s;
	s<<bset1;
	string s1;
	s>>s1;
	return s1;
}
fll ff(ll x,ll y,fll z) {
    fll a= (x&z);
    fll b= (y&z);

    return a*b;
}
ll bf(ll x,ll y,ll l,ll r) {
        ll max=0;
        ll in=0;
        for(ll i=l;i<=r;i++)
            if((x&i)*(y&i)>max) {
                max=(x&i)*(y&i);
                in=i;
            }
        return in;
}
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int t;
    cin>>t;
    while (t--) {   
        ll x,y,l,r;

        cin>>x>>y>>l>>r;
        fll L=l;
        string s1=printbs(x);
        string s2=printbs(y);
        string s3=printbs(r);
        string s5=printbs(l);
        fll max=0;
        fll ans=L;
        // std::vector<ll> v;
        fll O=1;
        // cout<<s1<<"\n"<<s2<<"\n"<<s3<<"\n"<<s5<<endl;
        fll temp=0;
        for(ll i=0;i<N;i++) {
            if(s3[i]=='1') {
                fll z=((O<<(N-i-1))-1)+temp;
                // cout<<printbs(z)<<endl;
                if(ff(x,y,z)>max&&z>=L) {
                    ans=z;
                    max=ff(x,y,z);
                }
                temp+=(O<<(N-i-1));
            }
        }
        // cout<<(ll)ans<<" "<<(ll)max<<" "<<(ll)ff(x,y,temp)<<endl;
        if(ff(x,y,temp)>max) {
            ans=temp;
        }
        // cout<<ans<<endl;
        string s4=printbs(ans);
        for(ll i=0;i<N;i++) {
            if(s4[i]=='1') {
                if(s1[i]=='0'&&s2[i]=='0') {
                    ans=ans-(O<<(N-i-1));
                    if(ans<L) {
                        ans=ans+(O<<(N-i-1));
                    }
                    else {
                        s4[i]='0';
                    }
                }
            }
        }
        // ll ans2=bf(x,y,l,r);
        cout<<(ll)ans<<endl;
        // if(ans!=ans2) {
        //     cout<<x<<" "<<y<<" "<<l<<" "<<r<<endl;
        // }

        // cout<<s4<<endl;
    }   
    return 0;  
}   