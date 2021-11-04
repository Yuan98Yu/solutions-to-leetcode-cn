class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        count = 1
        prefix = 1

        while count < k:
            tmp = count + self.get_count(prefix, n)
            if tmp > k:
                prefix *= 10
                count += 1
            else:
                prefix += 1
                count = tmp
        return prefix
    
    def get_count(self, prefix, n):
        next = prefix + 1
        count = 0
        while prefix <= n:
            count += min(next, n+1) - prefix
            prefix *= 10
            next *= 10
        
        return count
