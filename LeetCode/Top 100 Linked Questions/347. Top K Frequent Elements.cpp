class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int idx = 0;
        int n = nums.size();
        priority_queue<pair<int, int> > pq;
        vector<int> res;
        
        sort(nums.begin(), nums.end());
        
        while(idx < n) {
            int target = nums[idx];
            int cnt = 0;
            
            while(idx < n && nums[idx] == target){
                cnt++;
                idx++;
            }
            
            pq.push({cnt, target});
        }
        
        for(int i = 0; i < k; i++){
            int num = pq.top().second;
            
            pq.pop();
            res.push_back(num);
        }
        
        return res;
    }
};
