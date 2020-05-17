#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    int n;
    cin>>n;
    while (n--) {   
        // cout << "Hello World\n";
        int t;
        cin>>t;
        int a[t];
        int k=t/2,g=1,s=0,b=0;
        for(int i=0;i<t;i++) {
        	cin>>a[i];
        }   
        int i;
        for(i=1;i<k;i++) {
        	if(a[i]==a[i-1])
        		g++;
        	else
        		break;
        }
        int flag=1;
        // cout<<i<<endl;
        int prev=k;
        for(int j=k-1;j>=i;j--) {
        	if(a[j]==a[k]) {
        		prev=j;
        		continue;
        	}
        	if(flag) {
        		if(j==k-1) {
        			b++;
        		}
        		else {
        			if(a[j]==a[prev-1])
        				b++;
        			else {
        				if(g>=b) {
        					prev=j+1;
        					j++;
        					continue;
        				}

        				// cout<<j<<endl;
        				j++;
        				flag=0;
        			}
        		}
        	}
        	else {
        		s++;
        	}
        }
        // cout<<g<<" "<<s<<" "<<b<<endl;
        if((g+s+b)>k||(g==0)||(s==0)||(b==0)||(g>=s)||(g>=b)) {
        	cout<<"0 0 0\n";
        }
        else {
        	cout<<g<<" "<<s<<" "<<b<<endl;
        }
    }   
    return 0;  
}   