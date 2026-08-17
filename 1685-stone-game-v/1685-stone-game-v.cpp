class Solution {
public:
    int pick(int left, int right, vector<int>& presum, vector<vector<int>>& dp) {
        if (right == left) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        int res = 0;
        for (int i = left; i < right; i++) {
            int suml = presum[i + 1] - presum[left]; // Fixed index here
            int sumr = presum[right + 1] - presum[i + 1];
            if (suml > sumr) {
                res = max(res, pick(i + 1, right, presum, dp) + sumr); // Keep right part if left is larger
            }
            else if (suml < sumr) {
                res = max(res, pick(left, i, presum, dp) + suml);    // Keep left part if right is larger
            }
            else {
                res = max(res, max(pick(left, i, presum, dp), pick(i + 1, right, presum, dp)) + suml);
            }
        }
        return dp[left][right] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; i++) presum[i + 1] = stoneValue[i] + presum[i];
        return pick(0, n - 1, presum, dp);
    }
};
