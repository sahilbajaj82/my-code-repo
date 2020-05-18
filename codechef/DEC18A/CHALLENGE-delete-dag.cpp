#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int *a=new int[n+1];
	for(int i=0;i<=n;i++) {
		a[i]=0;
	}
	pair<int,int> p[n+1];
	vector<int> g1[n+1];
	int i=0;
	while(i<m) {
		int x,y;
		cin>>x>>y;
		a[x]++;
		g1[y].push_back(x);
		i++;
	}
	stack <int> s;
	for(int i=1;i<=n;i++) {
		if(a[i]==0)
			s.push(i);
	}
	int o[n],pp[n],q[n];
	int k=0;
	while(!s.empty()) {
		if(s.size()>1) {
			int v1=s.top();
			s.pop();
			int v2=s.top();
			s.pop();
			for (auto i = g1[v1].begin(); i != g1[v1].end(); ++i) { 
        		a[*i]--;
        		if(a[*i]==0)
        			s.push(*i); 
        	}
        	for (auto i = g1[v2].begin(); i != g1[v2].end(); ++i) { 
        		a[*i]--;
        		if(a[*i]==0)
        			s.push(*i); 
        	}
        	o[k]=2;
        	pp[k]=v1;
        	q[k]=v2;
        	k++;
		}
		else {
			int v2=s.top();
			s.pop();
			for (auto i = g1[v2].begin(); i != g1[v2].end(); ++i) { 
        		a[*i]--;
        		if(a[*i]==0)
        			s.push(*i); 
        	}
        	o[k]=1;
        	pp[k]=v2;
        	k++;
		}
	}
	cout<<k<<endl;
	for(int i=0;i<k;i++) {
		if(o[i]==1) {
			cout<<"1 "<<pp[i]<<endl;
		}
		else {
			cout<<"2 "<<pp[i]<<" "<<q[i]<<endl;
		}
	}
	return 0;
}
