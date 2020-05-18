class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo=0;
        for(auto i:nums) {
            xo^=i;
        }
    return xo;
    }
};
