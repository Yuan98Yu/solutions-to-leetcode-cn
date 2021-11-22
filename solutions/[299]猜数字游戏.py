class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls, cows = 0, 0
        memo = dict()
        for c in secret:
            tmp = memo.get(c, 0)
            memo[c] = tmp + 1

        for i in range(len(secret)):
            c1, c2 = secret[i], guess[i]
            if c1 == c2:
                if memo[c2] == 0:
                    cows -= 1
                else:
                    memo[c2] -= 1
                bulls += 1
            elif memo.get(c2, 0) > 0:
                memo[c2] -= 1
                cows += 1

        return f'{bulls}A{cows}B'
