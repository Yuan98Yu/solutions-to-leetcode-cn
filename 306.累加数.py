class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        def bt(sub1: str, sub2: str, rmstr: str) -> bool:
            if not rmstr:
                return True
            sub1, sub2 = sub2, str(int(sub1)+int(sub2))
            return rmstr.startswith(sub2) and bt(sub1, sub2, rmstr[len(sub2):] )
        
        n = len(num)
        if n < 3:
            return False
        for i in range (1, n//2 + 1):
            if num[0] == '0' and i > 1:
                break
            sub1 = num[:i]
            for j in range (1, (n - i)//2 + 1):
                if num[i] == '0' and j>1:
                    break
                sub2 = num[i:i+j]
                rmstr = num[i+j:]
                if bt (sub1, sub2, rmstr):
                    return True
        return False