#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
void solve2(int n,int m,int k) {
    int a[n][k];
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            cin>>a[i][j];
        }
    }
    int ans[k]={0};
    for(int i=0;i<n;i++) {
        int an=1;
        int min=0;
        ll sum1=0;
        for(int j=0;j<81;j++) {
            ll temp[k]={0};
            for(int jj=0;jj<k;jj++)
                temp[jj]=ans[jj];
            ll sum=0;
            for(int jj=0;jj<k;jj++) {
                if(a[i][jj]==(j)%9+1) {
                    temp[jj]++;;
                    sum++;
                }
                if(i+1<n&&a[i+1][jj]==(j/9)%9+1) {
                    temp[jj]++;;
                    sum++;
                }
            }
            int minqq=1000000;
            for(int jj=0;jj<k;jj++) {
                if(minqq>temp[jj]) {
                    minqq=temp[jj];
                }
            }
            temp[0]=minqq;
            if(min<temp[0]) {
                min=temp[0];
                an=j;
                sum1=sum;
            }
            else if(min==temp[0]) {
                if(sum>sum1) {
                    sum1=sum;
                    an=j;
                }
            }
        }
        for(int jj=0;jj<k;jj++) {
             if(a[i][jj]==(an)%9+1) {
                ans[jj]++;
             }
        }
        cout<<an%9+1<<" ";
    }
    cout<<endl;
}
void solve3(int n,int m,int k) {
    vector<int> a[n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    vector<int> left[n];
    int anss[n];
    map<ll,ll> u1;
    int dd=0;
    int ans[k]={0};
    for(int i=0;i<n;i++) {
        ll max=0;
        ll mc=0,mm=0,mn=0;
        for(int j=0;j<k;j++) {
            if(a[i][j]==1) {
                mc++;
            }
            else if(a[i][j]==2){
                max++;
            }
            else if(a[i][j]==3){
                mm++;
            }
            else
                mn++;
        }
        if(2*max>=k) {
            for(int j=0;j<k;j++) {
                if(a[i][j]==2) {
                    ans[j]++;
                }
            }
            anss[i]=2;
        }
        else if(2*mc>=k) {
            for(int j=0;j<k;j++) {
                if(a[i][j]==1) {
                    ans[j]++;
                }
            }
            anss[i]=1;
        }
        else if(2*mm>=k) {
             for(int j=0;j<k;j++) {
                if(a[i][j]==3) {
                    ans[j]++;
                }
            }
            anss[i]=3;
        }
        else if(2*mn>=k) {
             for(int j=0;j<k;j++) {
                if(a[i][j]==4) {
                    ans[j]++;
                }
            }
            anss[i]=4;
        }
        else {
            // cout<<i<<endl;
            left[dd++]=a[i];
            u1[dd-1]=i;
        }
    }
    // int ans[k]={0};
    for(int i=0;i<dd;i++) {
        int an=1;
        int min=0;
        ll sum1=0;
        for(int j=0;j<64;j++) {
            ll temp[k]={0};
            for(int jj=0;jj<k;jj++)
                temp[jj]=ans[jj];
            ll sum=0;
            for(int jj=0;jj<k;jj++) {
                if(left[i][jj]==(j)%4+1) {
                    temp[jj]++;;
                    sum++;
                }
                if(i+1<dd&&left[i+1][jj]==(j/4)%4+1) {
                    temp[jj]++;;
                    sum++;
                }
                if(i+2<dd&&left[i+2][jj]==(j/16)%4+1) {
                    temp[jj]++;
                    sum++;
                }
            }
            int minqq=1000000;
            for(int jj=0;jj<k;jj++) {
                if(minqq>temp[jj]) {
                    minqq=temp[jj];
                }
            }
            temp[0]=minqq;
            if(min<temp[0]) {
                min=temp[0];
                an=j;
                sum1=sum;
            }
            else if(min==temp[0]) {
                if(sum>sum1) {
                    sum1=sum;
                    an=j;
                }
            }
        }
        for(int jj=0;jj<k;jj++) {
             if(left[i][jj]==(an)%4+1) {
                ans[jj]++;
             }
        }
        
        anss[u1[i]]=an%4+1;
    }
     for(int i=0;i<n;i++) {
        cout<<anss[i]<<" ";
    }
    cout<<endl;
}
void solve1(int n,int m,int k) {
    vector<int> a[n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    vector<int> left[n];
    int anss[n];
    map<ll,ll> u1;
    int dd=0;
    int ans[k]={0};
    for(int i=0;i<n;i++) {
        ll max=0;
        ll mc=0;
        for(int j=0;j<k;j++) {
            if(a[i][j]==1) {
                mc++;
            }
            else {
                max++;
            }
        }
        if(4*max>=3*k) {
            for(int j=0;j<k;j++) {
                if(a[i][j]==2) {
                    ans[j]++;
                }
            }
            anss[i]=2;
        }
        else if(4*mc>=3*k) {
            for(int j=0;j<k;j++) {
                if(a[i][j]==1) {
                    ans[j]++;
                }
            }
            anss[i]=1;
        }
        else {
            // cout<<i<<endl;
            left[dd++]=a[i];
            u1[dd-1]=i;
        }
    }

    // int ans[k]={0};
    for(int i=0;i<dd;i++) {
        int an=1;
        int min=0;
        ll sum1=0;
        for(int j=0;j<8;j++) {
            ll temp[k]={0};
            for(int jj=0;jj<k;jj++)
                temp[jj]=ans[jj];
            ll sum=0;
            // cout<<j<<" ";
            for(int jj=0;jj<k;jj++) {
                // cout<<j<<" ";
                if(left[i][jj]==(j)%2+1) {
                    // cout<<"x1";
                    temp[jj]++;;
                    sum++;
                }
                if(i+1<dd&&left[i+1][jj]==(j/2)%2+1) {
                    temp[jj]++;;
                    sum++;
                    // cout<<"x2";
                }
                if(i+2<dd&&left[i+2][jj]==(j/4)%2+1) {
                    temp[jj]++;
                    sum++;
                }
            }
            int minqq=1000000;
            for(int jj=0;jj<k;jj++) {
                if(minqq>temp[jj]) {
                    minqq=temp[jj];
                }
            }
            temp[0]=minqq;
            if(min<temp[0]) {
                min=temp[0];
                an=j;
                sum1=sum;
            }
            else if(min==temp[0]) {
                if(sum>sum1) {
                    sum1=sum;
                    an=j;
                }
            }
        }
        for(int jj=0;jj<k;jj++) {
             if(left[i][jj]==(an)%2+1) {
                ans[jj]++;
             }
        }
        anss[u1[i]]=an%2+1;
    }
    for(int i=0;i<n;i++) {
        cout<<anss[i]<<" ";
    }
    cout<<endl;
}
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    if(m==2)
        solve1(n,m,k);
    else if(m==4)
        solve3(n,m,k);
    else 
        solve2(n,m,k);
}
int main() {
    #ifndef ONLINE_JUDGE   
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    #endif   
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }  
    return 0;
}   