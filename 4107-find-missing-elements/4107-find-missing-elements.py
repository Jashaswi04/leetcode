class Solution(object):
    def findMissingElements(self, nums):
        missing=[]
        small=min(nums)
        large=max(nums)
        for i in range(small+1,large):
            if i not in nums:
                missing.append(i);
        return missing
        