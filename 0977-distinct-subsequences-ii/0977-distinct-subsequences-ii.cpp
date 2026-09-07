class Solution {
public:
    int distinctSubseqII(string s) {
        int tot=0;
        int n=s.size();
        vector<int> dp(n,1);
        int MOD=1e9+7;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[i]!=s[j]){
                    dp[i]=(dp[i]+dp[j])%MOD;
                }
            }
            tot=(tot+dp[i])%MOD;
        }
        return tot;
    }
};