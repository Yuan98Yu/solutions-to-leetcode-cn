class Solution {
public:
    int mySqrt(int x) {
        int ans;
        int left = 0;
        int right = x/2+1;
        while(left < right){
            ans = left + (right-left + 1)/2;
            int tmp = x/ans;
            if(tmp==ans)
                return ans;
            else if(tmp>ans){
                left = ans;
            }
            else{
                right = ans-1;
            }
        }
        return left;
    }
};