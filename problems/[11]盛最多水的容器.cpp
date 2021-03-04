#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_area = -1;

		int p1 = 0;
		int p2 = height.size() - 1;
		while (p1 < p2) {
			int tmp_area = (p2 - p1) * (height[p1] < height[p2] ? height[p1] : height[p2]);
			if (tmp_area > max_area)
				max_area = tmp_area;
			if (height[p1] < height[p2]) {
				int tmp_height = height[p1];
				while (height[p1] <= tmp_height && p1 < p2) {
					p1++;
				}
			}
			else if (height[p1] > height[p2]) {
				int tmp_height = height[p2];
				while (height[p2] <= tmp_height && p1 < p2) {
					p2--;
				}
			}
			else {
				int tmp_height = height[p1];
				for (; height[p1] <= tmp_height && p1 < p2; p1++);
				for (; height[p2] <= tmp_height && p1 < p2; p2--);
			}
		}
	}
};