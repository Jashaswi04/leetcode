class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int res=-1;
        int n=nums.size();
        vector<int> maxi(n);
        vector<int> mini(n);
        mini[n-1]=nums[n-1];
        maxi[0]=nums[0];
        for (int i=1;i<n;i++){
            maxi[i]=nums[i];
            for(int j=i-1;j>=0;j--){
                if(nums[j]>maxi[i]) maxi[i]=nums[j];
            }
        }
        for (int i=0;i<n;i++){
            mini[i]=nums[i];
            for(int l=i+1;l<n;l++){
                if(nums[l]<mini[i]) mini[i]=nums[l];
            }
        }
        for (int i=0;i<n;i++){
            if (maxi[i]-mini[i]<=k) return i;
        }
        return -1;
    }
};