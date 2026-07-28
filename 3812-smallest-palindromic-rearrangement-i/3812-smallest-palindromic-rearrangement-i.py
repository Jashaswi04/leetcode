class Solution(object):
    def smallestPalindrome(self, s):
        visited={}
        for i in range(0,len(s)):
            if(s[i]not in visited):
                visited[s[i]]=1
            else:
                visited[s[i]]+=1
        key=sorted(visited.keys(),reverse=True)
        result=""
        extra=""
        for k in key:
            length=visited[k]/2
            substring=k*length
            result=substring+result
            visited[k]-=2*length
            if(visited[k]>0):
                extra+=k*visited[k]
        print(result)
        second=result[::-1]
        return result+extra+second