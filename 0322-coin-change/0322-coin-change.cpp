class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,1e9));
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int a=0;a<=amount;a++){
            if(a%coins[0]==0) dp[0][a]=a/coins[0];
        }
        for(int i=1;i<n;i++){
            for(int a=1;a<=amount;a++){
                int not_take=dp[i-1][a];
                int take=1e9;
                if(coins[i]<=a) take=1+dp[i][a-coins[i]];
                dp[i][a]=min(take,not_take);
            }
        }
        return ((dp[n-1][amount]==1e9)?-1:dp[n-1][amount]); 
    }
};