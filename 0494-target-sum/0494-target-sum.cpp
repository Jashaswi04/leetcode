class Solution {
public:
    void f(int i,vector<int>& a, int k,int &sum,int& count){
        if(i==0){
            if(sum==k) count++;
            return;
        }
        sum+=a[i-1];
        f(i-1,a,k,sum,count);
        sum-=a[i-1];
        sum-=a[i-1];
        f(i-1,a,k,sum,count);
        sum+=a[i-1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int count=0;
        f(n,nums,target,sum,count);
        return count;
    }
};