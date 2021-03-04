class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        
        while(left < right){
            int h = min(height[left], height[right]);
            res = max(res, (right - left) * h);
            
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return res;
    }
};
