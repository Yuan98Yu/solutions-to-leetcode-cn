from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        '''法 1：由枚举->动态规划->双指针
        对于每一个位置来说，其能盛的水取决于 min(左侧高度最大值， 右侧高度最大值)
        '''
        left_height, right_height = 0, 0
        left_p, right_p = -1, len(height)

        sum_count = 0
        while left_p < right_p:
            if left_height < right_height:
                left_p += 1
                sum_count += max(0, left_height -  height[left_p])
                left_height = max(left_height, height[left_p])
            else:
                right_p -= 1
                sum_count += max(0, right_height -  height[right_p])
                right_height = max(right_height, height[right_p])
        
        return sum_count