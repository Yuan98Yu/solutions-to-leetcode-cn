from typing import *


class TrieNode:
    def __init__(self) -> None:
        self.children = [None] * 2

    def insert(self, num_str: str) -> None:
        """
        Args:
            num_str: str, 长度为 31 位的二进制字符串
        Returns:
            None
        """
        cur = self
        for c in num_str:
            if cur.children[int(c)] is None:
                cur.children[int(c)] = TrieNode()
            cur = cur.children[int(c)]


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        root = TrieNode()
        for num in nums:
            root.insert(f'{num:0>31b}')

        def get_max(p1: TrieNode, p2: TrieNode, digit: int) -> int:
            tmp_max = 0
            for idx1, idx2 in [(0, 1), (1, 0)]:
                if p1.children[idx1] is not None and p2.children[
                        idx2] is not None:
                    tmp_max = max(
                        2**digit + get_max(p1.children[idx1],
                                           p2.children[idx2], digit - 1),
                        tmp_max)
            if tmp_max == 0:
                for idx1, idx2 in [(0, 0), (1, 1)]:
                    if p1.children[idx1] is not None and p2.children[
                            idx2] is not None:
                        tmp_max = max(
                            get_max(p1.children[idx1], p2.children[idx2],
                                    digit - 1), tmp_max)
            return tmp_max

        return get_max(root, root, 30)
