#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
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
        string A[9];
        for(int i=0;i<9;i++)
        	cin>>A[i];
        for(int i=0;i<3;i++) {
        	for(int j=0;j<3;j++)
        		A[3*i+j][3*j+i]=char((A[3*i+j][3*j+i]+1-'0')%9+1+'0');
        }
        for(int i=0;i<9;i++) {
        	cout<<A[i]<<endl;
        }

    }   
    return 0;  
}   