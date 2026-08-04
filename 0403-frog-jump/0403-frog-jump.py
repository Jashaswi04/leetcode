class Solution:
    def canCross(self, a: List[int]) -> bool:
        i=1
        last=0
        if a[i]-a[last]!=1:
            return False
        @cache
        def jump(last: int,i: int)->bool:
            if i==len(a)-1:
                return True
            k=a[i]-a[last]
            j=i+1
            while(j<len(a) and a[j]<=a[i]+k+1): 
                new=a[j]-a[i]
                new_k=new-k
                if(new_k>=-1 and new_k<=1):
                    if(jump(i,j)):
                        return True
                j+=1
            return False
        return jump(last,i)
