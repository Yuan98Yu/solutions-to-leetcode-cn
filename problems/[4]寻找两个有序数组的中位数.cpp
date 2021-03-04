#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double median;
		int n = nums1.size();
		int m = nums2.size();
		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = n;
		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[c1-1];
			RMin1 = (c1 == n) ? INT_MAX : nums1[c1+1];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[c2-1];
			RMin2 = (c2 == m) ? INT_MAX : nums2[c2+1];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		if (m + n % 2 == 0)
			median = (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
		else
			median = min(nums1[c1], nums2[c2]);
		return median;
	}

	// 寻找第k个数字：每次排除k/2个数字
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		if ((nums1.size() + nums2.size()) % 2 == 1)
			return dp(nums1, nums2, 0, 0, (nums1.size() + nums2.size() + 1) / 2);
		else {
			int k1 = (nums1.size() + nums2.size() + 1) / 2;
			int k2 = (nums1.size() + nums2.size() + 2) / 2;
			return (dp(nums1, nums2, 0, 0, k1) + dp(nums1, nums2, 0, 0, k2)) / 2;
		}
	}
	double dp(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int k) {
		int len1 = nums1.size() - start1;
		int len2 = nums2.size() - start2;
		if (len1 == 0)
			return nums2[start2 + k - 1];
		if (len2 == 0)
			return nums1[start1 + k - 1];
		if (k == 1)
			return min(nums1[start1], nums2[start2]);

		int i = start1 + min(len1, k / 2) - 1;
		int j = start2 + min(len2, k / 2) - 1;

		if (nums1[i] < nums2[j])
			return dp(nums1, nums2, i + 1, start2, k - (i - start1 + 1));
		else
			return dp(nums1, nums2, start1, j + 1, k - (j - start2 + 1));
	}
};

