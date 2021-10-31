from typing import List


class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        def is_valid(word: str):
            word = word.lower()
            char2type_dict = dict()
            for char_type, char_list in enumerate(['qwertyuiop', 'asdfghjkl', 'zxcvbnm']):
                for char in char_list:
                    char2type_dict[char] = char_type
            
            char_type = char2type_dict[word[0]]
            for char in word:
                if char2type_dict[char] != char_type:
                    return False
            
            return True

        ans = filter(is_valid, words)
        return list(ans)
