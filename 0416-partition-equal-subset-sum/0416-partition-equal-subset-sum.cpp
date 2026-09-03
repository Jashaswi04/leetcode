class Solution {
public:
    bool f(int i,int sum,vector<int>& a,vector<vector<int>> &dp){
        if (sum==0) return true;
        if(i==0) return a[0]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool not_take=f(i-1,sum,a,dp);
        bool take=false;
        if (sum>=a[i]) take=f(i-1,sum-a[i],a,dp);
        return dp[i][sum]=take|not_take;
    } 
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x :nums) sum+=x;
        if (sum%2!=0) return false;
        int target=sum/2;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
    }
};