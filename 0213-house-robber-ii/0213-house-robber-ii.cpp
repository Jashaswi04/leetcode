class Solution {
public:
    int max_val(vector<int>& arr){
        int n=arr.size();
        vector <int> dp(n,-1);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int take=arr[i];
            if (i>1) take+=dp[i-2];
            int not_take=dp[i-1];
            dp[i]=max(take,not_take);
        }
        return dp[n-1];
    }
    int rob(vector<int>& arr) {
        vector<int> temp1,temp2;
        int n=arr.size();
        if(n==1) return arr[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(arr[i]);
            if(i!=n-1) temp2.push_back(arr[i]);
        }
        return max(max_val(temp1),max_val(temp2));
    }
};