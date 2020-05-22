class Solution {
public:
    string frequencySort(string s) {
        int a[130]={0};
        for(int i=0;i<s.length();i++) {
            a[s[i]]++;
        }
        vector<pair<int,int>> p;
        int k=0;
        for(int i=0;i<130;i++) {
            if(a[i]!=0) {
                p.push_back(make_pair(a[i],i));
            }
        }
        sort(p.begin(),p.end());
        // string s1="";
        int len=p.size();
        char cha[1000000];
        int in=0;
        for(int i=len-1;i>=0;i--) {
            int x=p[i].first;
            int y=p[i].second;
            char ch=char(y);
            // string pl="";
            while(x--) {
                cha[in++]=ch;
            }
            // s1=s1+pl;
        }
        cha[in]='\0';
        return string(cha);
    }
};
