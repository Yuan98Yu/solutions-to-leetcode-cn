#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	/**
	*	��1��������
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
	*	��2����ϣ��
	*/
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> a;//�ṩһ��һ��hash
		vector<int> b(2, -1);//�������ؽ������ʼ��һ����СΪ2��ֵΪ-1������b
		for (int i = 0; i < nums.size(); i++)
		{
			if (a.count(target - nums[i]) > 0)
			{
				b[0] = a[target - nums[i]];
				b[1] = i;
				break;
			}
			a[nums[i]] = i;//����������map�У�������ȡ����±�
		}
		return b;
	}
};