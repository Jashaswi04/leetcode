class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n=len(piles)
        suffix=[0]*(n+1)
        for i in range(n-1,-1,-1):
            suffix[i]=suffix[i+1]+piles[i]
        @cache
        def min_max(i: int,m: int)-> int:
            if i+2*m>n:
                return suffix[i]
            res=0
            x=1
            while(x<=2*m):
                curr=suffix[i]-min_max(x+i,max(m,x))
                res=max(res,curr)
                x+=1
            return res
        return min_max(0,1)