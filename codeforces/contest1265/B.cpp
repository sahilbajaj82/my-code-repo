#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
int size[200003];
int Arr[200003];
void initialize( int N) {
    for(int i = 0;i<N;i++) {
        Arr[ i ] = i ;
        size[ i ] = 1;
        // cou[i]=-1;
    }
}

int root (int i) {
    while(Arr[ i ] != i) {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
        i = Arr[ i ]; 
    }
    return i;
}
bool find(int A,int B) {
    if( root(A)==root(B) )   
        return true;
    else
        return false;
}
void weighted_union(int A,int B) {
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A]<=size[root_B ]){
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];    
    }
}
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
        // cout << "Hello World\n";
        int n;
        cin>>n;
        int a[200003];
        int p[200003];
        int ar[200003];
        for(int i=0;i<n+2;i++)
        	ar[i]=0;
        initialize(200003);
        for(int i=0;i<n;i++) {
        	cin>>a[i];
        	p[a[i]]=i;
        }
        int flag=true;
        for(int i=1;i<=n;i++) {
        	ar[p[i]]=1;
        	if(ar[p[i]-1]==1) {
        		weighted_union(p[i],p[i]-1);
        	}
        	if(ar[p[i]+1]==1) {
        		weighted_union(p[i],p[i]+1);
        	}
        	if(size[root(p[i])]==i)
        		cout<<"1";
        	else
        		cout<<"0";
        }
        cout<<endl;
    }   
    return 0;  
}   