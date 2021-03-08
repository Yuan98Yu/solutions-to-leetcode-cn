#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int max_area = 0;
        vector<int> histogram(matrix[0].size());
        for (size_t i = 0; i < matrix.size(); ++i){
            for (size_t j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == '0')
                    histogram[j] = 0;
                else
                    ++histogram[j];
            }
            max_area = max(max_area, largestRectangleArea2(histogram));
        }
        return max_area;
    }
private:
    int drive(vector<int>& heights, int start, int end){
        if (start >= end)
            return 0;
        int min_height_idx = start;
        for (int i = start+1; i < end; ++i)
            if (heights[i] < heights[min_height_idx])
                min_height_idx = i;
        return max( (end-start) * heights[min_height_idx], max(drive(heights, start, min_height_idx), drive(heights, min_height_idx+1, end)));
    }
    int largestRectangleArea(vector<int>& heights) {
        return drive(heights, 0, heights.size());
    }

    int largestRectangleArea2(vector<int>& heights) {
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
