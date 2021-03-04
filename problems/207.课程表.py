#
# @lc app=leetcode.cn id=207 lang=python3
#
# [207] 课程表
#


# @lc code=start
class Solution:
    def canFinish(self, numCourses: int,
                  prerequisites: List[List[int]]) -> bool:
        indegrees = [0] * numCourses
        adjacency = [list() for _ in range(numCourses)]
        for course, pre_course in prerequisites:
            adjacency[pre_course].append(course)
            indegrees[course] += 1
        
        queue = list()
        count = 0
        for course in range(numCourses):
            if indegrees[course] == 0:
                queue.append(course)
        
        while queue:
            course = queue.pop()
            count += 1
            for adj in adjacency[course]:
                indegrees[adj] -= 1
                if indegrees[adj] == 0:
                    queue.append(adj)
        
        return count == numCourses


# @lc code=end
