#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
int main() {   
    // ios::sync_with_stdio(0);   
    // cin.tie(0);   
    // cout.tie(0);
    // #ifndef ONLINE_JUDGE   
    // freopen("input.txt", "r", stdin);   
    // freopen("output.txt", "w", stdout);
    // #endif   
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        std::vector<int> v[n];
        for(int i=0;i<m;i++) {
            int x,y;
            cin>>x>>y;
            if(x!=y) {
            v[x-1].push_back(y-1);
            v[y-1].push_back(x-1);
            }
        }
        // sort(v[0].begin(),v[0].end());
        std::vector<int> no;
        queue<pair<int,int>> q;
        bool visited[n+1];
        for(int i=0;i<=n;i++) {
            visited[i]=false;
        }
        visited[0]=true;
        q.push(make_pair(1,0));
        int c[n+1]={0};
        while(!q.empty()) {
            int x=q.front().first;
            int lev=q.front().second;
            q.pop();
            visited[x]=true;
            c[x]=1;
            no.push_back(x);
            if(lev<2) {
                for(auto i:v[x]) {
                    if(!visited[i]) {
                        q.push(make_pair(i,lev+1));
                    }
                }
            }
        }
        // c[0]=1;
        // c[1]=1;
        std::set<int> ans;
        for(auto i:v[0]) {
            if(i>1)
            if(c[i]==0)
                ans.insert(i);
        }
        // sort(ans.begin(),ans.end());
        if(ans.size()==0) {
            cout<<"-1\n";
        }
        else {
           for(auto &i:ans) {
               cout<<i+1<<" ";
           }
            cout<<"\n"; 
        }
    }
    return 0;  
}   