class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long> (amount+1,0));
        for(int t=0;t<=amount;t++) dp[0][t]=(t%coins[0]==0);
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                long long unsigned not_take=dp[i-1][t];
                long long unsigned take=0;
                if(coins[i]<=t) take=dp[i][t-coins[i]];
                dp[i][t]=not_take+take;
            }
        }
        return dp[n-1][amount];
    }
};