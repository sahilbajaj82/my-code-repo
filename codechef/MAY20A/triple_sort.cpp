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
    	int n,k;
    	cin>>n>>k;
    	int a[n];
    	// vector<int> v;
    	int pos[n+1];
        for(int i=0;i<n;i++) {
            cin>>a[i];
            pos[a[i]]=i+1;
        }
       
        	int ans[n+1][3];
        	int in=0;
        	int i=0;
        	while(i<n) {
            	if(a[i]==i+1) {
                	i++;
               		continue;
            	}
            	else  {
            		if(a[i]==pos[i+1]) {
            			i++;
            			continue;
            		}
            		int val=a[i];
                	ans[in][0]=i+1;
               	 	ans[in][1]=val;
               		ans[in][2]=pos[i+1];
                	pos[a[i]]=val;
                	pos[a[val-1]]=pos[i+1];
                	pos[a[pos[i+1]-1]]=i+1;
                	int temp=a[ans[in][2]-1];
                	a[ans[in][2]-1]=a[val-1];
                	a[val-1]=a[i];
                	a[i]=temp;
                	in++;
            	}
           //  	// cout<<in<<" ";
           //  		for(int i=1;i<=n;i++)
        			// 	cout<<a[i-1]<<" ";
        			// cout<<endl;
        	}
        	  // 		for(int i=1;i<=n;i++)
        			// 	cout<<a[i-1]<<" ";
        			// cout<<endl;
        		 vector<pair<int,int>> v1;
       		 map<int,int>s;
        		for(int i=0;i<n;i++) {
        			if((a[i]!=i+1)&&a[i]==pos[i+1]&&a[pos[i+1]-1]==i+1) {
						if(s[a[i]]!=1) {
							v1.push_back(make_pair(a[i],i+1));
							v1.push_back(make_pair(i+1,pos[i+1]));
							s[a[i]]=1;
							s[i+1]=1;
					}
			}
        }
        	
        	for(int i=3;i<v1.size();i=i+4) {
        		int aa=v1[i-3].second,b=v1[i-2].second,c=v1[i-1].second,d=v1[i].second;
        		ans[in][0]=aa;
        		ans[in][1]=b;
        		ans[in++][2]=c;
        		ans[in][0]=c;
        		ans[in][1]=aa;
        		ans[in++][2]=d;
        		a[aa-1]=aa;
        		a[b-1]=b;
        		a[c-1]=c;
        		a[d-1]=d;
        	}
        	// for(int i=1;i<=n;i++)
        	// 			cout<<a[i-1]<<" ";
        	// 		cout<<endl;
        	// cout<<"x";
        	int flag=true;
        	if(in>k)
        		flag=false;
        	for(int i=0;i<n;i++)
        		if(a[i]!=i+1)
        			flag=false;
        	if(flag) {
        		// if(in>k)
        		// 	cout<<"111";
        	 int jj=0;
        	
            cout<<in<<endl;
            while(jj<in) {
                cout<<ans[jj][0]<<" "<<ans[jj][1]<<" "<<ans[jj][2]<<endl;
                jj++;
            }
        	}
        	else {
        		cout<<"-1\n";
        	}
        // }

    }   
    return 0;  
}   