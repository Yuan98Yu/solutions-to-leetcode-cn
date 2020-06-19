#
# @lc app=leetcode.cn id=529 lang=python3
#
# [529] 扫雷游戏
#


# @lc code=start
class Solution:
    def updateBoard(self, board: List[List[str]],
                    click: List[int]) -> List[List[str]]:
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0), (-1, -1), (-1, 1), (1, 1),
                (1, -1)]

        def dfs(i, j):
            if 0 <= i < len(board) and 0 <= j < len(board[0]) \
                and board[i][j] == 'E':
                dig_mines(i, j)
                if board[i][j] == 'B':
                    for dir in dirs:
                        dfs(i + dir[0], j + dir[1])

        def dig_mines(i, j):
            count = 0
            for dir in dirs:
                new_i, new_j = i + dir[0], j + dir[1]
                if 0 <= new_i < len(board) and 0 <= new_j < len(board[0]) \
                    and board[new_i][new_j] == 'M':
                    count += 1
            if count == 0:
                board[i][j] = 'B'
            else:
                board[i][j] = str(count)

        y, x = click[0], click[1]
        if board[y][x] == 'M':
            board[y][x] = 'X'
        elif board[y][x] == 'E':
            dig_mines(y, x)
            if board[y][x] == 'B':
                for dir in dirs:
                    dfs(y + dir[0], x + dir[1])
        return board


# @lc code=end
