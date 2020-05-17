#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
void solve() {
	int n,k;
    cin>>n>>k;
    int a[n];
    int count=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-k+1;i++) {
        if(a[i]==k) {
            int flag=1;
            for(int j=0;j<k-1;j++) {
                if(a[i+j+1]!=k-j-1) {
                    flag=0;
                    i=i+j;
                    break;
                }
            }
            if(flag) {
                count++;
                i=i+k-1;
            }
        }
    }
    cout<<count<<endl;
}
int main() {   
   
    int t;
    cin>>t;
    for(int i=0;i<t;i++) {
    	 cout<<"Case #"<<i+1<<": ";
    	 solve();
    }
    return 0;  
}   
