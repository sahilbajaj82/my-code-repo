#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define N 4 
#define M 998244353
void display(std::vector<ll> res) {
    // ll nn=binpow((res[0]+res[1]+res[2]+res[3])%M,M-2);
    cout<<(res[0])%M<<" "<<(res[1])%M<<" "<<(res[2])%M<<" "<<(res[3])%M<<endl;
}

void solve() {
    std::vector<ll> NA = {748683265, 748683265,748683265, 748683265}; 
    ll AND[N][N] = {{0, 0, 0, 0}, 
                    {0, 1, 2, 3}, 
                    {0, 2, 2, 0}, 
                    {0, 3, 0, 3}}; 
    ll OR[N][N] = {{0, 1, 2, 3}, 
                    {1, 1, 1, 1}, 
                    {2, 1, 2, 1}, 
                    {3, 1, 1, 3}}; 
    ll XOR[N][N] = {{0, 1, 2, 3}, 
                    {1, 0, 3, 2}, 
                    {2, 3, 0, 1}, 
                    {3, 2, 1, 0}}; 
    string s;
    cin>>s;
    
    stack<std::vector<ll> >stk;
    stack<int> stk2;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='#') {
            stk.push(NA);
        }
        else if(s[i]=='&') {
            stk2.push(0);
        }
        else if(s[i]=='|') {
            stk2.push(1);
        }
        else if(s[i]=='^') {
            stk2.push(2);
        }
        else if(s[i]==')') {
            std::vector<ll> out1=stk.top();
            stk.pop();
            std::vector<ll> out2=stk.top();
            stk.pop();
            int c=stk2.top();
            stk2.pop();
            std::vector<ll> out3;
            for(int i=0;i<N;i++)
                out3.push_back(0);
            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                    if(c==0) {
                        out3[AND[i][j]]=(out3[AND[i][j]]+(out1[i]*out2[j])%M)%M;
                    }
                    else if(c==1) {
                        out3[OR[i][j]]=(out3[OR[i][j]]+(out1[i]*out2[j])%M)%M;
                    }
                    else {
                        out3[XOR[i][j]]=(out3[XOR[i][j]]+(out1[i]*out2[j])%M)%M;
                    }
                    
                }

               
            }
            stk.push(out3);
           
        }
    }
  
    display(stk.top());
    
}
int main() {
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }  
    return 0;
}   