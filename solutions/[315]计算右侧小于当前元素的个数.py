from typing import List


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        n = len(nums)
        tmp_arr = [0] * n
        tmp_ans = [0] * n
        index_dict = list(range(n))
        def merge(l, mid, r):
            for i in range(l, r+1):
                tmp_arr[i] = nums[i]
            k = l
            lp, rp = l, mid + 1
            while lp <= mid and rp <=r:
                if tmp_arr[lp] <= tmp_arr[rp]:
                    nums[k] = tmp_arr[lp]
                    lp += 1
                    pass
                else:
                    nums[k] = tmp_arr[rp]
                    rp += 1
                    pass
                k += 1
            
        def mergesort_and_count(l, r):
            pass

        mergesort_and_count(0, n-1)
        return [tmp_ans[index_dict[i]] for i in range(n)]
