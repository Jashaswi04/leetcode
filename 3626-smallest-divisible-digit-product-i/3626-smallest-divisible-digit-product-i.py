class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        i=n
        def product(n:int)->int:
            if(n==0): 
                return 0
            prod=1
            while(n>0):
                prod*=n%10
                n//=10
            return prod
        prod=product(i)
        print(prod)
        while(prod%t!=0):
            n+=1
            i=n
            prod=product(i)
        return n