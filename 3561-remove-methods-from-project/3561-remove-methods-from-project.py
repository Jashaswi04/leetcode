class Solution:
    def remainingMethods(self, n: int, k: int, inv: List[List[int]]) -> List[int]:
        adj=[[] for _ in range(n)]
        for u,v in inv:
            adj[u].append(v)
        sus=set([k])
        q=deque([k])
        while q:
            curr=q.popleft()
            for neibour in adj[curr]:
                if neibour not in sus:
                    sus.add(neibour)
                    q.append(neibour)
        for u,v in inv:
            if u not in sus and v in sus:
                return list(range(n))
        return [x for x in range(n) if x not in sus]