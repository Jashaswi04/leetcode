class Solution {
public:
    int f(vector<int>& cuts,int s,int e,vector<vector<int>> dp){
        if(e-s<=1) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int tot=1e9;
        for(int i=s;i<=e;i++){
            int left_cost=f(cuts,s,i-1,dp);
            int right_cost=f(cuts,i+1,e,dp);
            int cost=(cuts[e]-cuts[s])+left_cost+right_cost;
            tot=min(cost,tot);
        }
        return dp[s][e]=tot;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int k=cuts.size();
        vector<vector<int>> dp(k,vector<int>(k,0));
        for(int i=k-1;i>=0;i--){
            for(int j=i+1;j<k;j++){
                for(int x=i+1;x<j;x++){
                    int cost=(cuts[j]-cuts[i])+dp[i][x]+dp[x][j];
                    dp[i][j]=min((dp[i][j]==0?INT_MAX:dp[i][j]),cost);
                }
            }
        }
        return dp[0][k-1];
    }
};