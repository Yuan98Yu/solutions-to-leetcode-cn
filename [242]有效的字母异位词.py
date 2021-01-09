class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        c2count = dict()
        for c in s:
            count = c2count.get(c, 0)
            c2count[c] = count + 1
        
        for c in t:
            count = c2count.get(c, 0)
            if count == 0:
                return False
            else:
                c2count[c] = count - 1
        
        return True