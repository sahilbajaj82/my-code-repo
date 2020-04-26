#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
std::vector<int>  coef1(string s) {
    std::vector<int> v1;
    int count=0;
    int a=0;
    int prev=-1,prev1=-1;
    int n=s.length();
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            if(prev==-1)
                prev=i;
            else  {
                // cout<<i-prev-1<<" ";
                if(i-prev-1!=0)
                v1.push_back(i-prev-1);
                a=a+i-prev-1;
            }
            prev=i;
        }
        else {
            if(prev1==-1)
                prev1=i;
            else {
                  if(i-prev1-1!=0)
                v1.push_back(i-prev1-1);
                 // cout<<i-prev1-1<<" ";
                a=a+i-prev1-1;
            }
            prev1=i;
        }

        }
    return v1;
}
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    // #ifndef ONLINE_JUDGE   
    // freopen("input.txt", "r", stdin);   
    // freopen("output.txt", "w", stdout);
    // #endif   
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    vector<int>v=coef1(s);
    int len=v.size();
    int i=0;
    int sub=p*2;
    if(sub>=len) {
        cout<<"0\n";
    }
    else {
        // cout<<sub<<endl;
        // cout<<len<<endl;
        sub=len-sub;
        int ini=0;
        for(int i=0;i<sub;i++) {
            ini+=v[i];
        }
        // cout<<ini<<endl;
        int min=ini;
        for(int i=sub;i<len;i++) {
            ini=ini+v[i];
            ini=ini-v[i-sub];
            if(ini<min) {
                min=ini;
            }
        }
        cout<<min<<endl;
    }
    
    return 0;  
}   