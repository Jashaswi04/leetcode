class Solution {
public:
    int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& a){
        if (i==0 && j==0) return a[0][0];
        if (i<0 || j<0) return 1e9;
        if (dp[i][j]!=-1) return dp[i][j];
        int right=a[i][j]+func(i,j-1,dp,a);
        int top=a[i][j]+func(i-1,j,dp,a);
        return dp[i][j]=min(right,top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp,grid);
    }
};