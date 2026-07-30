class Solution(object):
    def minimumPushes(self, word):
        n=len(word)
        c_list=list(set(list(word)))
        count=0
        for w in word:
            if c_list.index(w)<8:
                count+=1
            elif c_list.index(w)<16:
                count+=2
            elif c_list.index(w)<24:
                count+=3
            else:
                count+=4
        return count