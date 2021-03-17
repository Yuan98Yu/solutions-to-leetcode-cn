import typing

from typing import *
map


class Solution:
    class TrieNode:
        pass
    class Trie:
        def __init__(self) -> None:
            pass

    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words = sentence.split()

        def resolve_word(word: str):
            pass

        # for word in words:
        words = map(resolve_word, words)
        return ' '.join(words)
