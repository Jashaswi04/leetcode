class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++) dp[0][j]=matrix[0][j];
        for (int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int u=matrix[i][j]+dp[i-1][j];
                int ur=1e9;
                if (j+1<n) ur=matrix[i][j]+dp[i-1][j+1];
                int ul=1e9;
                if (j-1>=0) ul=matrix[i][j]+dp[i-1][j-1];
                dp[i][j]=min(u,min(ur,ul));
            }
        }
        int maxi=dp[n-1][0];
        for(int j=1;j<n;j++) maxi=min(maxi,dp[n-1][j]);
        return maxi;
    }
};