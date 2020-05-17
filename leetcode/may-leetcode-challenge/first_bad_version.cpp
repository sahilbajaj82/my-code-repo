// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1;
        int right=n;
        int ans=1;
        while(left<=right) {
            int mid=(right-left)/2+left;
            bool flag=isBadVersion(mid);
            if(flag==true) {
                ans=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
    }
};
