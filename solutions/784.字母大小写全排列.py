class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        ans = list()
        def dfs(path: str, s: str):
            if len(s) == 0:
                ans.append(path)
                return
            if s[0].isalpha():
                dfs(path+s[0].lower(), s[1:])
                
                dfs(path+s[0].upper(), s[1:])
            else:
                dfs(path+s[0], s[1:])
        
        dfs ("", S)
        return ans