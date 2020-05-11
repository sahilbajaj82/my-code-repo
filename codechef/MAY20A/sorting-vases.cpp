#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
#define F first
#define S second
#define pb push_back
std::vector<int> groups[30];
std::vector<int> part[30];
int visited[30];
int a[30];
int n;
int ccc;
struct dd {
    int l;
    std::vector<pair<int,int>> v;
};
void disp(int in) {
    for(int i=0;i<in;i++) {
        cout<<i<<": ";
        for(auto j:part[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
dd dd1(int j,int i,dd l) {
    if(l.l>n) {
        l.l=100;
        return l;
    }
    for(int b=0;b<part[j].size();b++) {
        if(part[j][b]==i) {
            l.l++;
            l.v.push_back(make_pair(j,b));
            // part[j][b]=j;
            return l;
        }
    }
    dd min;
    min.l=100;
    int in=0;
    for(int k=0;k<part[j].size();k++)  {
        if(part[j][k]!=j) {
            l.l++;
            dd cal=dd1(part[j][k],i,l);
            if(cal.l<min.l) {
                min=cal;
                in=k;
            }
        }
    }
    // if(min.l!=)
    min.v.push_back(make_pair(j,in));
    return min;
}
void solve() {
    ccc=0;
    int m;
    n=0;
    cin>>n>>m;   
    int visit[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i]--;
        visit[i]=false;        
    }
    for(int i=0;i<19;i++) {
        part[i].clear();
        groups[i].clear();
    }
    vector<int> v[n];
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);  
    }
    int in=0;
    for(int i=0;i<n;i++) {
        if(!visit[i]) {
            stack<int>s;
            s.push(i);
            while(!s.empty()) {
                int x=s.top();
                s.pop();
                groups[in].push_back(x);
                visit[x]=true;
                for(auto i:v[x]) {
                    if(!visit[i]) {
                        s.push(i);
                        visit[i]=true;
                    }
                }
            }
            in++;
        }
    }
   
    for(int i=0;i<in;i++) {
        for(auto j:groups[i]) {
            int find=0;
            for(int k=0;k<in;k++) {
                for(auto bb:groups[k]) {
                    if(a[bb]==j) {
                        find=k;
                    }
                }
            }
            part[i].push_back(find);
        }
    }
    int weight=0;
    while(true) {
        int flag=true;
        dd fff;
        fff.l=100;
        for(int i=0;i<in;i++) {
            for(int j=0;j<part[i].size();j++) {
                if(part[i][j]!=i) {
                 flag=false;
                 dd temp;
                 temp.l=0;
                 temp.v.push_back(make_pair(i,j));
                 temp=dd1(part[i][j],i,temp);
                 if(fff.l>temp.l) {
                    fff=temp;
                 }
             }
            }
        }
        if(flag) {
            break;
        }
        else {
                weight+=fff.l;
                for(auto k:fff.v) {
                    part[k.first][k.second]=k.first;
                }
            }
        }
    cout<<weight<<endl;
}

int main() {   
    ios::sync_with_stdio(0);   
    cin.tie(0);   
    cout.tie(0);
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output1.txt", "w", stdout);
    #endif   
    int t;
    cin>>t;
    while (t--) {   
        solve();
    }   
    return 0;  
}   