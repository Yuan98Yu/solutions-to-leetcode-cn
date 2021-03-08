class Solution:
    def minStickers(self, stickers: list, target: str) -> int:
        dp = dict()
        dp[""] = 0
        stickers_counts = list()

        def dfs(target: str) -> int:
            if dp.get(target) is not None:
                return dp.get(target)

            ans = 2e8
            count = [0] * 26
            for c in target:
                count[ord(c)-ord('a')] += 1

            for sticker in stickers_counts:
                if sticker[ord(target[0])-ord('a')] == 0:
                    continue
                tmp_str = ""
                for i in range(26):
                    if count[i] > sticker[i]:
                        tmp_str += chr(ord('a')+i) * (count[i]-sticker[i])
                res = dfs(tmp_str)
                if res >= 0:
                    ans = min(ans, 1 + res)

            if ans == 2e8:
                ans = -1
            dp[target] = ans
            return ans

        for sticker in stickers:
            count = [0] * 26
            for c in sticker:
                count[ord(c)-ord('a')] += 1
            stickers_counts.append(count)
        return dfs(target)
