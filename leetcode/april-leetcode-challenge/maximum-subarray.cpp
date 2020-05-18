class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=0;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum<0) {
                sum=0;
            }
            if(sum>max) {
                max=sum;
            }
        }
        if(max==0) {
            max=-1*INT_MAX;
            for(int i=0;i<nums.size();i++) {
                if(max<nums[i]) {
                    max=nums[i];
                }
            }
        }
        return max;
    }
};
