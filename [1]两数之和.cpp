#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	/**
	*	法1：暴力法
	*/
	vector<int> twoSum1(vector<int>& nums, int target) {
		int i, j;
		for(i = 0; i < nums.size()-1; i++)
			for (j = i; j < nums.size()-1; j++) 
				if (nums[i] + nums[j] == target)
					break;
		return { i, j };
	}
	/**
	*	法2：哈希表
	*/
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> a;//提供一对一的hash
		vector<int> b(2, -1);//用来承载结果，初始化一个大小为2，值为-1的容器b
		for (int i = 0; i < nums.size(); i++)
		{
			if (a.count(target - nums[i]) > 0)
			{
				b[0] = a[target - nums[i]];
				b[1] = i;
				break;
			}
			a[nums[i]] = i;//反过来放入map中，用来获取结果下标
		}
		return b;
	}
};