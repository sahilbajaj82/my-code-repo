#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int max(int a, int b) { return (a > b)? a : b; } 
int a[51][31];
int knap[51][1501];
int knapSack(int n,int p,int N,int k) {
	if(p<0||n==N){
		return 0;
	}
	if(knap[n][p]!=0)
		return knap[n][p];
	int sum=knapSack(n+1,p,N,k);
	for(int i=0;i<k;i++) {
		if(p-i-1>=0){
			int ans=a[n][i]+knapSack(n+1,p-i-1,N,k);
			sum=max(sum,ans);
		}
	}
	knap[n][p]=sum;
	//cout<<n<<"x "<<p<<" "<<sum<<endl;
	return sum;
} 
int main() {   
    int t;
    cin>>t;
    int j=0;
    while (j<t) {   
        int n,k,p;
        cin>>n>>k>>p;
        for(int i=0;i<51;i++){
        	for(int jj=0;jj<1501;jj++)
        		knap[i][jj]=0;
        }
        for(int i=0;i<n;i++) {
        	for(int jj=0;jj<k;jj++) {
        		cin>>a[i][jj];
        		if(jj!=0)
        			a[i][jj]+=a[i][jj-1];
        		
        	}
        }
        int sum=0;
        sum=knapSack(0,p,n,k);
        cout<<"Case #"<<j+1<<": "<<sum<<endl;
    	j++;
    }

    return 0;  
}   