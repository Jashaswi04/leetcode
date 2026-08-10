class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp=[0]*(n+1)
        @cache
        def square_up(n: int):
            if n<=0:
                return 0
            root=int(math.sqrt(n))
            if (root**2)==n or dp[n]==1:
                dp[n]=1
                return 1
            for i in range(1,root+1):
                if square_up(n-(i**2))==0:
                    dp[n]=1
            return dp[n]
        if square_up(n):
            return True
        return False   