from typing import List


class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        tmp_list = [0] * len(nums)

        def merge_and_count(l, mid, r):
            for i in range(l, r + 1):
                tmp_list[i] = nums[i]
            k = l
            count = 0
            lp, rp = l, mid + 1
            while lp <= mid and rp <= r:
                if tmp_list[lp] <= tmp_list[rp]:
                    nums[k] = tmp_list[lp]
                    lp += 1
                    count += rp - mid - 1
                else:
                    nums[k] = tmp_list[rp]
                    rp += 1
                k += 1
            while lp <= mid:
                nums[k] = tmp_list[lp]
                k += 1
                lp += 1
                count += r - mid
            while rp <= r:
                nums[k] = tmp_list[rp]
                k += 1
                rp += 1
            return count

        def mergesort_and_count(l, r):
            if l >= r:
                return 0

            mid = (l + r) // 2
            l_count = mergesort_and_count(l, mid)
            r_count = mergesort_and_count(mid + 1, r)
            return l_count + r_count + merge_and_count(l, mid, r)

        return mergesort_and_count(0, len(nums) - 1)
