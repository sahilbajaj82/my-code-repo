class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=1;
        int high=46341;
        bool flag=false;
        while(low<high) {
            int mid=(high-low)/2+low;
            if(mid*mid==num) {
                flag=true;
                break;
            }
            else if(mid*mid>num) {
                high=mid;
            }
            else {
                low=mid+1;
            }
        }
        return flag;
    }
};
