class Solution(object):
    def minimumPushes(self, word):
        count=Counter(word)
        freq=sorted(count.values(),reverse=True)
        total_push=0
        for index,f in enumerate(freq):
            multiplyer=(index//8)+1
            total_push+=f*multiplyer
        return total_push