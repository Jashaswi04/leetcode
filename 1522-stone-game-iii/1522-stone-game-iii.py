class Solution:
    def stoneGameIII(self, A: List[int]) -> str:
        n=len(A)
        j=0
        @cache
        def min_max(j : int)-> int:
            if j==n:
                return 0
            a=b=c=-1e7
            if j<n:
                a= A[j]-min_max(j+1)
            if j+1<n:
                b=A[j]+A[j+1]-min_max(j+2)
            if j+2<n:
                c=A[j]+A[j+1]+A[j+2]-min_max(j+3)
            return max(a,b,c)
        total=min_max(j)
        if total>0:
            return ("Alice")
        elif total<0:
            return ("Bob")
        return "Tie"