from typing import List


class Trie:
    def __init__(self, word_list=None) -> None:
        self.count = 0
        self.next = [[0] * 26 for _ in range(10000)]
        self.is_end = [False] * 10000
        if word_list is not None:
            for word in word_list:
                self.insert(word)

    def insert(self, word):
        p = 0
        for c in word:
            c = ord(c) - ord('a')
            if self.next[p][c] == 0:
                self.count += 1
                self.next[p][c] = self.count
            p = self.next[p][c]
        self.is_end[p] = True
        # print(word, self.is_end[p], p)

    def find(self, word):
        p = 0
        for c in word:
            # print(word, c)
            c = ord(c) - ord('a')
            if self.next[p][c] == 0:
                return False
            p = self.next[p][c]
        # print('find:', word, self.is_end[p], p)
        return self.is_end[p]

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie = Trie(wordDict)
        trie.insert('')
        memo = [False] * (len(s)+1)
        memo[0] = True

        for i in range(1, len(s) + 1):
            for j in range(i):
                memo[i] = memo[i] or (memo[j] and trie.find(s[j:i])
            )
        # print(memo)
        # print(trie.find(''))
        # for word in wordDict:
        #     print(trie.find(word))
        return memo[len(s)]
