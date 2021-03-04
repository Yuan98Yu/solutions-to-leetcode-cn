class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return list()

        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        m, n = len(matrix), len(matrix[0])
        def is_valid_pos(i, j, round, dir_idx):
            if dir_idx == 0 or dir_idx == 2:
                return round <= j < n-round
            else:
                return round <= i < m-round

        ans = list()
        i, j = 0, 0
        dir_idx = 0
        round = 0
        for _ in range(m * n):
            ans.append(matrix[i][j])

            new_i, new_j = i + dirs[dir_idx][0], j + dirs[dir_idx][1]
            tmp_round = (round if dir_idx < 3 else round + 1)
            # print(new_i, new_j, tmp_round, dir_idx)
            if is_valid_pos(new_i, new_j, tmp_round, dir_idx):
                # print('True')
                i, j = new_i, new_j
            else:
                dir_idx = (dir_idx + 1) % 4
                i, j = i + dirs[dir_idx][0], j + dirs[dir_idx][1]
                if dir_idx == 0:
                    round += 1
        return ans
