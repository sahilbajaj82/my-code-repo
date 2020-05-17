class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int size=grid.size();
        int row=grid[0].size();
        int dp[size][1000];
        for(int i=0;i<size;i++) {
            for(int j=0;j<row;j++) {
                int x=grid[i][j];
                if(i!=0&&j!=0) {
                    x=x+min(dp[i-1][j],dp[i][j-1]);
                }
                else if(i!=0) {
                    x=x+dp[i-1][j];
                }
                else if(j!=0){
                    x=x+dp[i][j-1];
                }
                dp[i][j]=x;
            }
        }
        return dp[size-1][row-1];
    }
};
