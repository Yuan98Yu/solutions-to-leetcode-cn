from typing import List


class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        n = len(nums) // 2
        nums = sorted(nums)

        def get_ans(first_higher_pos):
            k = nums[first_higher_pos] - nums[0]
            if k == 0 or k % 2 != 0:
                return None
            cur_pos = 0
            pre_lower_pos = 0
            pre_lower = 0
            next_higher = first_higher_pos
            pos_list = list()
            while len(pos_list) < n:
                if nums[next_higher] - nums[pre_lower] != k:
                    return None
                for i in range(cur_pos, next_higher):
                    pos_list.append(i)
                pre_lower_pos += 1
                if next_higher == 2*n - 1:
                    break
                if pre_lower_pos == len(pos_list):
                    pos_list.append(next_higher + 1)
                    cur_pos = next_higher + 2
                else:
                    cur_pos = next_higher + 1
                pre_lower = pos_list[pre_lower_pos]
                for i in range(cur_pos, 2 * n):
                    if nums[i] - nums[pre_lower] == k:
                        next_higher = i
                        break

            if len(pos_list) != n or nums[-1] - nums[pos_list[-1]] != k:
                print(first_higher_pos, pre_lower, pos_list)
                return None
            else:
                k = k // 2
                print(k)
                return [nums[pos] + k for pos in pos_list]

        for first_higher_pos in range(1, n + 1):
            ans = get_ans(first_higher_pos)
            if ans is not None:
                return ans
