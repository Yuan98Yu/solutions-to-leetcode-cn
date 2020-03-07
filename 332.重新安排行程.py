#
# @lc app=leetcode.cn id=332 lang=python3
#
# [332] 重新安排行程
#

# @lc code=start
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        n = len(tickets)
        tickets_dict = dict()
        for ticket in tickets:
            start, dest = ticket[0], ticket[1]
            dests = tickets_dict.get(start, list())
            dests.append([dest, False])
            tickets_dict[start] = dests
        
        for value in tickets_dict.values():
            value = value.sort()

        def dfs(start, ans):
            if len(ans) == n+1:
                return True
            
            dests = tickets_dict.get(start, None)
            if not dests:
                return False
            
            for dest in dests:
                if dest[1] == True:
                    continue
                ans.append(dest[0])
                dest[1] = True
                if dfs(dest[0], ans):
                    return True
                else:
                    ans.pop()
                    dest[1] = False
            
            return False
        
        start = 'JFK'
        ans = [start]
        dfs(start, ans)
        return ans

        
# @lc code=end

