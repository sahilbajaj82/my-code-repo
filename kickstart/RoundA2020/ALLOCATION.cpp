#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int main() {   
    int t;
    cin>>t;
    int j=0;
    while (j<t) {   
        int n,b;
        cin>>n>>b;
        int a[n];
        for(int i=0;i<n;i++)
        	cin>>a[i];
        sort(a,a+n);
        int i=0;
        for(i=0;i<n;i++){
        	if(b-a[i]<0){
        		break;
        	}
        	b=b-a[i];
        }
        cout<<"Case #"<<j+1<<": "<<i<<endl;
    	j++;
    }

    return 0;  
}   