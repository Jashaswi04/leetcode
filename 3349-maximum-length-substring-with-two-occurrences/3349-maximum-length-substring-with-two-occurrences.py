class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        freq={}
        left=0
        max_len=0
        for r in range(len(s)):
            cur=s[r]
            freq[cur]=freq.get(cur,0)+1
            while freq[cur]>2:
                l_ele=s[left]
                freq[l_ele]-=1
                left+=1
            max_len=max(max_len,r-left+1)
        return max_len