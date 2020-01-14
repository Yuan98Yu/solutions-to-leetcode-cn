#
# @lc app=leetcode.cn id=299 lang=python3
#
# [299] 猜数字游戏
#

# @lc code=start
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls, cows = 0, 0
        secret_counts = [0] * 10
        guess_counts = [0] * 10
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                secret_counts[int(secret[i])] += 1
                guess_counts[int(guess[i])] += 1
        
        for i in range(10):
            cows += min(secret_counts[i], guess_counts[i])
        
        return "%dA%dB" % (bulls, cows)


# @lc code=end

