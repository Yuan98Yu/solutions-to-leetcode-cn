class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr = sorted(arr)
        median = arr[(len(arr) - 1) // 2]
        for i in range(len(arr)):
            arr[i] -= median

        ans = list()
        i, j = 0, len(arr) - 1
        for _ in range(k):
            if abs(arr[i]) > abs(arr[j]):
                ans.append(arr[i]+median)
                i += 1
            else:
                ans.append(arr[j]+median)
                j -= 1

        return ans
