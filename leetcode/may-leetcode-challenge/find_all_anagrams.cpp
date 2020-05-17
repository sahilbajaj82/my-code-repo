class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        int a[26]={0};
        for(int i=0;i<p.length();i++) {
            a[p[i]-'a']++;
        }
        vector<int>ans;
        if(p.length()>s.length())
            return ans;
        int b[26]={0};
        for(int i=0;i<p.length();i++) {
            b[s[i]-'a']++;
        }
        int flag=1;
        for(int i=0;i<26;i++) {
            if(a[i]!=b[i]) {
                flag=0;
                break;
            }
        }
        if(flag)
            ans.push_back(0);
        for(int i=p.length();i<s.length();i++) {
            b[s[i]-'a']++;
            b[s[i-p.length()]-'a']--;
            int flag=1;
             for(int i=0;i<26;i++) {
                 if(a[i]!=b[i]) {
                  flag=0;
                 break;
             }
             }
            if(flag)
                 ans.push_back(i-p.length()+1);
            }
      
    return ans;
    }
};
