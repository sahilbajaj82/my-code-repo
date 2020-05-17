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
    int t;
    cin>>t;
    while (t--) {   
        // cout << "Hello World\n";
        string s;
        cin>>s;
        char c[3];
        c[0]='a';
        c[1]='b';
        c[2]='c';
        int flag=1;
        for(int i=0;i<s.length();i++) {
        	if(s[i]=='?') {
        		if(i==0) {
        			if(s[i+1]=='a'||s[i+1]=='b')
        				s[i]='c';
        			else {
        				s[i]='a';
        			}
        		}
        		else if(i==s.length()-1) {
        			if(s[i-1]=='a'||s[i-1]=='b')
        				s[i]='c';
        			else
        				s[i]='a';
        		}
        		else {
        			if(s[i-1]!='c'&&(s[i+1]!='c'||s[i+1]=='?'))
        				s[i]='c';
        			else if(s[i-1]!='b'&&(s[i+1]!='b'||s[i+1]=='?'))
        				s[i]='b';
        			else if(s[i-1]!='a'&&(s[i+1]!='a'||s[i+1]=='?'))
        				s[i]='a';
        		}
        	}
        	// cout<<s<<endl;
        	if(i!=0&&s[i]==s[i-1]) {
        		flag=0;
        		break;
        	}
        }   
    	if(flag){
    		cout<<s<<endl;
    	}
    	else {
    		cout<<"-1"<<endl;
    	}
    }   
    return 0;  
}   