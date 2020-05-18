class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int a[26]={0};
        for(int i=0;i<s1.length();i++) {
            a[s1[i]-'a']++;
        }
        int b[26]={0};
        if(s1.length()>s2.length()) {
            return false;
        }
        for(int i=0;i<s1.length();i++) {
            b[s2[i]-'a']++;
        }
        int flag=1;
        for(int i=0;i<26;i++) {
            if(a[i]!=b[i]) {
                flag=0;
                break;
            }
        }
        if(flag) {
            return true;
        }
        for(int i=s1.length();i<s2.length();i++) {
            b[s2[i]-'a']++;
            b[s2[i-s1.length()]-'a']--;
            int flag=1;
             for(int i=0;i<26;i++) {
                 if(a[i]!=b[i]) {
                  flag=0;
                 break;
             }
             }
            if(flag)
                 return true;
            }
      return false;
    }
};
