class Solution {
public:
    int func(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& obs){
        if (i>=0 && j>=0 && obs[i][j]==1) return 0;
        if (i==0 && j==0) return 1;
        if (i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=func(i,j-1,dp,obs);
        int top=func(i-1,j,dp,obs);
        return dp[i][j]=left+top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp,obstacleGrid);
    }
};