class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i, j = 0, 0
        for j in range(len(typed)):
            if i < len(name) and typed[j] == name[i]:
                i += 1
            elif j > 0 and typed[j] == typed[j-1]:
                continue
            else:
                return False
        return i == len(name)
         
