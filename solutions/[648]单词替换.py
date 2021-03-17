from typing import *


class Trie:
    def __init__(self) -> None:
        self.children = [None] * 26
        self.is_end = False

    def insert(self, key: str):
        cur = self
        for c in key:
            c2i = ord(c) - ord('a')
            if cur.children[c2i] is None:
                cur.children[c2i] = Trie()
            cur = cur.children[c2i]
        cur.is_end = True

    def search(self, word: str):
        cur = self
        i = 0
        for c in word:
            i += 1
            c2i = ord(c) - ord('a')
            cur = cur.children[c2i]
            if cur is None or cur.is_end:
                break
        if cur is None or not cur.is_end:
            return word
        return word[:i]


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for prefix in dictionary:
            trie.insert(prefix)

        def resolve_word(word: str):
            prefix = trie.search(word)
            return prefix if prefix is not None else word

        words = map(resolve_word, sentence.split())
        return ' '.join(words)
