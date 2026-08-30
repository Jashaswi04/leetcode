class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi=0,mini=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[maxi]<nums[i]) maxi=i;
            if(nums[mini]>nums[i]) mini=i;
        }
        int diff=abs(maxi-mini)-1;
        cout<<diff;
        int res=1e8;
        if(maxi>mini) res=min(res,min(min((mini+diff+2),(n-maxi+diff+1)),n-diff));
        else if (maxi<mini) res=min(res,min(min((maxi+diff+2),(n-mini+diff+1)),n-diff));
        else res=1;
        return res;
    }
};