#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    /*
    * 法1：穷举
    */
    int largestRectangleArea(vector<int>& heights) {
        vector<int> tmp_v(heights.size());
        int max_area = 0;
        
        for (size_t i = 0; i < heights.size(); ++i)
        {
            int min_height = heights[i];
            for (size_t j = i; j < heights.size(); ++j){
                if( heights[j] < min_height)
                    min_height = heights[j];
                int tmp_area = (j-i+1) * min_height;
                if (tmp_area > max_area)
                    max_area = tmp_area;
            }
            
        }
        return max_area;
    }

    /*
    * 法2：分治
    */
    int drive(vector<int>& heights, int start, int end){
        if (start >= end)
            return 0;
        int min_height_idx = start;
        for (int i = start+1; i < end; ++i)
            if (heights[i] < heights[min_height_idx])
                min_height_idx = i;
        return max( (end-start) * heights[min_height_idx], max(drive(heights, start, min_height_idx), drive(heights, min_height_idx+1, end)));
    }
    int largestRectangleArea2(vector<int>& heights) {
        return drive(heights, 0, heights.size());
    }

    /*
    * 法3：栈
    */
    int largestRectangleArea3(vector<int>& heights) {
        stack<int> s;   //存的是升序序列的下标
        s.push(-1);
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            while(s.top() != -1 && heights[s.top()] >= heights[i]){
                int cur_height = heights[s.top()];
                s.pop();
                max_area = max(max_area, cur_height * (i - s.top() - 1) );
            }
            s.push(i);
        }
        while(s.top() != -1){
            int cur_height = heights[s.top()];
            s.pop();
            max_area = max(max_area, cur_height * (int(heights.size()) - s.top() - 1) );
        }
            
        return max_area;        
    }
};