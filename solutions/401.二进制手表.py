class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        ans = list()        
        l1 = [pow(2, i) for i in range(0,6)]
        l2 = [pow(2, i) for i in range(0,4)]

        def dfs(h: int, m: int, start: int, rmNum: int) -> (int,int):
            if rmNum == 0:
                ans.append("%d:%02d" %(h, m))
            i = start
            i_limit = len(l1) + len(l2) - rmNum + 1
            while i < min(len(l1)+len(l2),i_limit):
                if i < len(l1):
                    new_m = m + l1[i]
                    if new_m >= 60:
                        i = len(l1)
                        continue
                    else:
                        dfs(h, new_m, i+1, rmNum-1)
                else:
                    new_h = h +l2[i-len(l1)]
                    if new_h >= 12:
                        break
                    else:
                        dfs(new_h, m, i+1, rmNum-1)
                i += 1
        dfs(0, 0, 0, num)
        return ans
