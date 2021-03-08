from itertools import product


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        is_used = {s:False for s in wordList}

        def has_edge(pre_word, pro_word):
            count = 0
            for i in range(len(pre_word)):
                count += ( 1 if pre_word[i]!=pro_word[i] else 0)
                if count > 1:
                    return False
            # print(pre_word, pro_word, (not is_used[pro_word] and count == 1))
            return count == 1

        queue = [beginWord]
        count = 0
        has_found = False
        while not has_found and queue:
            length = len(queue)
            for _ in range(length):
                word = queue.pop(0)
                if (word == endWord):
                    has_found = True
                    break

                for pro_word in wordList:
                    if not is_used[pro_word] and has_edge(word, pro_word):
                        queue.append(pro_word)
                        is_used[pro_word] = True
                
            count += 1
        
        return count if has_found else 0
