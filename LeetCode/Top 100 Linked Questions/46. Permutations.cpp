class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;

        sort(nums.begin(), nums.end());
        do{
            vector<int> n;
            
            n = nums;
            
            res.push_back(n);
        } while(next_permutation(nums.begin(), nums.end()));
        
        return res;
    }
};
