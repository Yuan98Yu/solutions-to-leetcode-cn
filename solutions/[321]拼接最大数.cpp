#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		int m = nums1.size(), n = nums2.size();
		vector<int> res;
		for (int i = max(0, k - n); i <= min(k, m); i++)
			res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
		return res;
	}
	vector<int> maxVector(vector<int> nums, int k) {
		int drop = nums.size() - k;
		vector<int> res;
		for (int num : nums) {
			while (drop && res.size() && res.back() < num) {
				res.pop_back();
				--drop;
			}
			res.push_back(num);
		}
		res.resize(k);
		return res;
	}
	vector<int> mergeVector(vector<int> nums1, vector<int> nums2) {
		vector<int> res;
		while (nums1.size() + nums2.size()) {
			vector<int>& tmp = nums1 > nums2 ? nums1 : nums2;
			res.push_back(tmp[0]);
			tmp.erase(tmp.begin());
		}
		return res;
	}

	//vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	//	vector<int> ans(k, 0);

	//	nums1 = get_max_k_num(nums1, k);
	//	nums2 = get_max_k_num(nums2, k);
	//	dp(nums1, 0, nums2, 0, k, ans, 0);

	//	return ans;
	//}

	//vector<int> get_max_k_num(vector<int>& nums, int k) {
	//	if (nums.size() <= k)
	//		return nums;

	//	vector<int> nums_stack;
	//	nums_stack.push_back(10);
	//	for (int i=0; i < nums.size(); ++i) {
	//	// 剩余元素数量加已有元素数量大于等于k
	//		while (nums_stack.back() < nums[i] && nums.size() - i + nums_stack.size() > k) {
	//			nums_stack.pop_back();
	//		}
	//	if (nums_stack.size() == k + 1)
	//		continue;
	//	else
	//		nums_stack.push_back(nums[i]);
	//	}
	//	nums_stack.erase(nums_stack.begin());
	//	return nums_stack;
	//}

	//void dp(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k,
	//	vector<int>& ans, int start3) {
	//	int p1 = start1;
	//	int p2 = start2;
	//	if (k == 0)
	//		return;

	//	int max1 = -1;
	//	int max2 = -1;
	//	int p_max1 = 0;
	//	int p_max2 = 0;
	//	for (; p1 < nums1.size() - (nums2.size()-start2+1 >= k ? 0 : k - nums2.size()+start2-1); ++p1) {
	//		if (nums1[p1] > max1) {
	//			max1 = nums1[p1];
	//			p_max1 = p1;
	//			if (max1 == 9)
	//				break;
	//		}
	//	}
	//	for (; p2 < nums2.size() - (nums1.size()-start1+1 >= k ? 0 : k - nums1.size()+start1-1); ++p2) {
	//		if (nums2[p2] > max2) {
	//			max2 = nums2[p2];
	//			p_max2 = p2;
	//			if (max2 == 9)
	//				break;
	//		}
	//	}
	//	if (max1 < ans[start3] && max2 < ans[start3])
	//		return;
	//	else if (max1 > ans[start3] || max2 > ans[start3])
	//		for (int i = start3 + 1; i < ans.size(); ++i)
	//			ans[i] = 0;

	//	if (max1 > max2) {
	//		ans[start3] = max1;
	//		dp(nums1, p_max1 + 1, nums2, start2, k - 1, ans, start3 + 1);
	//	}
	//	else if (max1 < max2) {
	//		ans[start3] = max2;
	//		dp(nums1, start1, nums2, p_max2 + 1, k - 1, ans, start3 + 1);
	//	}
	//	else {
	//		ans[start3] = max1;
	//		dp(nums1, p_max1 + 1, nums2, start2, k - 1, ans, start3 + 1);
	//		dp(nums1, start1, nums2, p_max2 + 1, k - 1, ans, start3 + 1);
	//	}
	//}


	//vector<int>& max_of_2v(vector<int>& nums1, vector<int>& nums2) {
	//	for (int i = 0; i < nums1.size(); ++i) {
	//		if (nums1[i] > nums2[i])
	//			return nums1;
	//		else if (nums1[i] < nums2[i])
	//			return nums2;
	//	}
	//	
	//	return nums1;
	//}
	
//vector<int> maxNumber2(vector<int>& nums1, vector<int>& nums2, int k) {
//	vector<int> nums_stack;
//	nums_stack.push_back(10);
//	int p1 = 0;
//	int p2 = 0;
//	while(p1 < nums1.size() && p2 < nums2.size()) {
//		// 剩余元素数量加已有元素数量大于等于k
//		while ((nums_stack.back() < nums1[p1]||nums_stack.back()<nums2[p2]) 
//			&& nums1.size() - p1 + nums2.size() - p2 - 2 + nums_stack.size() >= k) {
//			nums_stack.pop_back();
//		}
//		if (nums_stack.size() == k + 1)
//			continue;
//		else if (nums1[p1] >= nums2[p2]) {
//			nums_stack.push_back(nums1[p1++]);
//		}
//		else {
//			nums_stack.push_back(nums2[p2++]);
//		}
//	}
//	for (; p1 < nums1.size(); ++p1) {
//		// 剩余元素数量加已有元素数量大于等于k
//		while (nums_stack.back() < nums1[p1] && nums2.size() - p1 + nums_stack.size() > k) {
//			nums_stack.pop_back();
//		}
//		if (nums_stack.size() == k + 1)
//			continue;
//		else
//			nums_stack.push_back(nums2[p1]);
//	}
//	for (; p2 < nums2.size(); ++p2) {
//		// 剩余元素数量加已有元素数量大于等于k
//		while (nums_stack.back() < nums2[p2] && nums2.size() - p2 + nums_stack.size() > k) {
//			nums_stack.pop_back();
//		}
//		if (nums_stack.size() == k + 1)
//			continue;
//		else
//			nums_stack.push_back(nums2[p2]);
//	}
//	pass
//	nums_stack.erase(nums_stack.begin());
//	return nums_stack;
//}
};