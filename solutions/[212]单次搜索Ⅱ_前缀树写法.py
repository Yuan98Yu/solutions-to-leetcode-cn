from typing import List
from itertools import product


class TrieNode(dict):

    def __init__(self, parent=None, val=None) -> None:
        super().__init__()
        self.word = False
        self.val = val
        self.parent = parent
        self.count = 0


class Solution:

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.board = board
        self.ans_list = set()
        trie = TrieNode()
        
        for word in words:
            cur_node = trie
            for c in word:
                cur_node.count += 1
                node = cur_node.setdefault(c, TrieNode(cur_node, c))
                node.parent = cur_node
                cur_node = node
            cur_node.count += 1
            cur_node.word = word
        
        for row, col in product(range(len(board)), range(len(board[0]))):
            self.__dfs(row, col, trie)
        
        return list(self.ans_list)

    def __dfs(self, row, col, root):
        def is_valid_pos(row, col):
            return (0 <= row < len(self.board)
                    and 0 <= col < len(self.board[0])
                    and self.board[row][col] != '#')
        
        if not is_valid_pos(row, col):
            return False
        char = self.board[row][col]
        if root is None or root.get(char) is None:
            return False

        root = root.get(char)
        if root.word:
            cur_node = root
            self.ans_list.add(cur_node.word)
            while cur_node:
                cur_node.count -= 1
                if cur_node.count == 0:
                    print(cur_node.val)
                    c = cur_node.val
                    cur_node.parent.pop(c)
                cur_node = cur_node.parent
        
        tmp, self.board[row][col] = self.board[row][col], '#'
        for dir in [(-1,0), (1,0), (0,-1), (0,1)]:
            next_row, next_col = row+dir[0], col+dir[1]
            self.__dfs(next_row, next_col, root)
        self.board[row][col] = tmp