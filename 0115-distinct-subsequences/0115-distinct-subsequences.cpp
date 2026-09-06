class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0)); 
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){ 
                unsigned int not_take=dp[i-1][j];
                unsigned int take=0;
                if(s[i-1]==t[j-1]) take=dp[i-1][j-1];
                dp[i][j]=take+not_take;
            }
        }
        return (int)dp[n][m];
    }
};