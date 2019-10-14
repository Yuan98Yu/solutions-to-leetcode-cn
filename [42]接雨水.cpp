#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() <= 2)
			return 0;

		int ans = 0;

		vector<int> left_right(height.size());
		int lMax = 0;
		int rMax = 0;
		for (int i = 0; i < height.size(); ++i) {
			if (lMax < height[i])
				lMax = height[i];
			left_right[i] = lMax;
		}
		for (int i = height.size() - 1; i >= 0; --i) {
			cout << "i: " << i << ", " << "rMAX: " << rMax << endl;
			if (rMax < height[i])
				rMax = height[i];
			if (rMax < left_right[i])
				left_right[i] = rMax;
		}
		for (int i = 1; i < height.size() - 1; ++i)
			ans += left_right[i] - height[i];

		for (int i = 0; i < left_right.size(); ++i)
			cout << left_right[i]<<" ";
		cout << endl;

		return ans;
	}
};