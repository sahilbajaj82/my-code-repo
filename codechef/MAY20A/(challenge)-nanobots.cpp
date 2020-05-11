#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int const n=512,f=512,b=8;
int a[512][512];
vector<pair<char,int>> v;
void solve(int x,int y) {
	int B[b][b];
	int tot=0;
	for(int i=0;i<b;i++) {
		for(int j=0;j<b;j++) {
			B[i][j]=a[x+i][y+j];
			tot+=B[i][j];
		}
	}
	while(true) {
		int check=-1;
		int ind=0;
		int nu=0;
		for(int i=0;i<b;i++) {
			int sum=0;
			int count=0;
			for(int j=0;j<b;j++) {
				if(sum+B[i][j]>f) {
					break;
				}
				count++;
				sum=sum+B[i][j];
			}
			if(check<sum+count) {
				check=sum+count;
				ind=i;
				nu=1;
			}
		}
		for(int i=0;i<b;i++) {
            int sum=0;
            int count=0;
            for(int j=0;j<b;j++) {
                if(sum+B[j][i]>f) {
                    break;
                }
                count++;
                sum=sum+B[j][i];
            }
            if(check<sum+count) {
                check=sum+count;
                ind=i;
                nu=0;
            }
        }
        if(nu==0) {
        	v.push_back(make_pair('U',ind+y+1));
        	int sum=0;
        	int j=0;
        	for(;j<b;j++) {
        		if(sum+B[j][ind]>f) {
        			break;
        		}
        		tot-=B[j][ind];
        		
        		sum+=B[j][ind];
        		B[j][ind]=0;
        		a[j+x][ind+y]=0;
        	}
        	if(j==b) {
        		for(;j<n;j++) {
        			if(j+x>=n) {
        				break;
        			}
        			if(sum+a[j+x][ind+y]>f) {
        				break;
        			}
        			sum=sum+a[j+x][ind+y];
        			// cout<<sum<<" ";
        			a[j+x][ind+y]=0;
        		}
        	}
        }
        else {
        	v.push_back(make_pair('L',ind+x+1));
        	int sum=0;
        	int j=0;
        	for(j=0;j<b;j++) {
        		if(sum+B[ind][j]>f) {
        			break;
        		}
        		tot-=B[ind][j];
        		sum+=B[ind][j];
        		B[ind][j]=0;
        		a[ind+x][j+y]=0;
        	}

        	if(j==b) {
        		for(;j<n;j++) {
        			if(j+y>=n) {
        				break;
        			}
        			if(sum+a[ind+x][j+y]>f) {
        				break;
        			}
        			sum+=a[ind+x][j+y];
        			a[ind+x][j+y]=0;
        		}
        	}
        	// cout<<sum<<endl;
        }
		if(tot==0) {
			break;
		}
		// cout<<tot<<endl;
	}

}
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output1.txt", "w", stdout);
    #endif  
    int N,F; 
	cin>>N>>F;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}    
	int max;
	cin>>max;

	for(int i=0;i<n;i+=b) {
		for(int j=0;j<n;j+=b) {
			solve(i,j);
		}
	}
	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<n;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<v.size()<<endl;
	for(auto i:v) {
		cout<<i.first<<" "<<i.second<<endl;
	}
    return 0;  
}   