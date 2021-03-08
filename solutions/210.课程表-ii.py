#
# @lc app=leetcode.cn id=210 lang=python3
#
# [210] 课程表 II
#

# @lc code=start
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegrees = [0] * numCourses
        adjacency = [list() for _ in range(numCourses)]
        for course, pre_course in prerequisites:
            adjacency[pre_course].append(course)
            indegrees[course] += 1
        
        ans = list()
        queue = list()
        count = 0
        for course in range(numCourses):
            if indegrees[course] == 0:
                queue.append(course)
        
        while queue:
            course = queue.pop()
            ans.append(course)
            count += 1
            for adj in adjacency[course]:
                indegrees[adj] -= 1
                if indegrees[adj] == 0:
                    queue.append(adj)
        
        return ans if count == numCourses else []
# @lc code=end

