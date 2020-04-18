#include <bits/stdc++.h>   
using namespace std;   
using ll =long long;
int cou[26];
int size[26];
int Arr[26];
void initialize( int N) {
    for(int i = 0;i<N;i++) {
        Arr[ i ] = i ;
        size[ i ] = 1;
        cou[i]=-1;
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
    int n;
    cin>>n;
    initialize(26);
    while(n--) {
    	string s;
    	cin>>s;
    	sort(s.begin(),s.end());
    	auto res=unique(s.begin(),s.end());
    	s=string(s.begin(),res);
        cou[s[0]-'a']=1;
        for(int i=1;i<s.length();i++) {
            cou[s[i]-'a']=1;
            weighted_union(s[i]-'a',s[0]-'a');
        }
    }
    set<int>s;
    for(int i=0;i<26;i++) {
        if(cou[i]==1) {
            s.insert(root(Arr[i]));
        }
    }
    cout<<s.size()<<endl;
    return 0;  
}   