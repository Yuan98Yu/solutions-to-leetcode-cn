from typing import List


class Solution:
    dir_dict = {'L': (0, -1), 'R': (0, 1), 'U': (-1, 0), 'D': (1, 0)}

    def executeInstructions(self, n: int, startPos: List[int],
                            s: str) -> List[int]:
        def is_valid(pos):
            return 0 <= pos[0] < n and 0 <= pos[1] < n

        def count(i):
            pos = [startPos[0], startPos[1]]
            count = 0
            for j in range(i, len(s)):
                dir = self.dir_dict[s[j]]
                pos[0], pos[1] = pos[0] + dir[0], pos[1] + dir[1]
                if not is_valid(pos):
                    break
                else:
                    count += 1
            return count

        return [count(i) for i in range(len(s))]
