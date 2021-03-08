from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1],[1,1]]
        if numRows <= 2:
            return ans[:numRows]
        
        for i in range(2, numRows):
            tmp = [1]
            for j in range(1, len(ans[i-1])):
                tmp.append(ans[i-1][j-1] + ans[i-1][j])
            tmp.append(1)
            ans.append(tmp)
        return ans