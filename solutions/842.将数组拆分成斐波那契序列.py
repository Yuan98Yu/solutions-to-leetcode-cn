class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        ans = list()
        def dfs(num1: int, num2: int, rmStr: str, path: List[int]):
            if len(rmStr) == 0:
                ans.append(path)
                return True
            else:
                num1, num2 = num2, num1 + num2
                return num2 < pow(2, 31) and rmStr.startswith(str(num2)) and dfs(num1, num2, rmStr[len(str(num2)):], path+[num2])
        
        n = len(S)
        for i in range(1, n//2 + 1):
            num1 = int(S[:i])
            if (S[0] == '0' and i > 1) or num1 > pow(2, 31) - 1:
                break
            for j in range (1, (n - i)//2 + 1):
                if S[i] == '0' and j>1:
                    break
                num2 = int(S[i:i+j])
                rmstr = S[i+j:]
                if dfs (num1, num2, rmstr, [num1, num2]):
                    return ans[0]
        return []