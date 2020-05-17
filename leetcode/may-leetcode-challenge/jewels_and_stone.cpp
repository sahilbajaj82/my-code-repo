class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int a[300]={0};
        for(int i=0;i<J.length();i++) {
            a[J[i]]=1;
        }
        int count=0;
        for(int i=0;i<S.length();i++) {
            if(a[S[i]]==1)
                count++;
        }
        return count;
    }
};
