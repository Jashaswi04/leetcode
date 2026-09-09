class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int cost_day=costs[0]+dp[i+1];
            int j;
            for(j=i;j<days.size() && days[j]<days[i]+7;j++);
            int cost_week=costs[1]+dp[j];
            for(j=i;j<days.size() && days[j]<days[i]+30;j++);
            int cost_mon=costs[2]+dp[j];
            dp[i]=min(cost_day,min(cost_week,cost_mon));
        }
        return dp[0];
    }
};