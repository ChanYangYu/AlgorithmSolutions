class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int max_cnt = 0;
        
        int prev = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            if(prev != nums[i]){
                if(max_cnt < cnt){
                    res = prev;
                    max_cnt = cnt;
                }
                cnt = 0;
                prev = nums[i];
            }
            cnt++;
        }
        
        if(max_cnt < cnt)
            res = prev;
        
        return res;
    }
};
