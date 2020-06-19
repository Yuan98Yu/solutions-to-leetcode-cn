class Solution:
    def who_win(self, n, edges):
        new_edges = [ list() for _ in range(n+1)]
        for (i, j) in edges:
            new_edges[i].append(j)
            new_edges[j].append(i)

        def count(end, cur, father):
            if cur == end:
                return 0
            ans = 0
            for next in new_edges[cur]:
                if next != father:
                    ans += 1 + count(end, next, cur)
            return ans
        
        def find_path(cur, father, path):
            if cur == n:
                return True
            
            find = False
            for next in new_edges[cur]:
                if find:
                    break
                if next != father:
                    find &= find_path(next, cur, path)
            
            if find:
                path.append(cur)
            
            return find
        
        path = list()
        find_path(1, 0, path)
        path.pop()
        count1 = count(n, 1, 0) + count(path[len(path)//2-1], path[-1], 0)
        count2 = count(1, n, 0) + count(path[len(path)//2], path[0], 0)

        return count1 >= count2
        

