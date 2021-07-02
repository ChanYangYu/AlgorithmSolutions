class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums(nums.size() + 1, 0);
        int res = -987654321;
        priority_queue<int, vector<int>, greater<int> > pq;
        
        sums[0] = 0;
        pq.push(sums[0]);
        
        for(int i = 0; i < nums.size(); i++){
            int mn = pq.top();
            sums[i+1] = nums[i] + sums[i];
            
            res = max(res, (sums[i+1] - mn));
            pq.push(sums[i+1]);
        }
        
        return res;
    }
};
