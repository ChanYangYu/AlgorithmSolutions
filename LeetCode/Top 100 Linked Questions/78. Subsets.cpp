class Solution {
public:
    vector<vector<int> > res;
    vector<int> number;
    int n;
    
    void combination(vector<int> sub, int cur){
        if(cur == n){
            res.push_back(sub);
            return;
        }
        
        combination(sub, cur+1);
        sub.push_back(number[cur]);
        combination(sub, cur+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        number = nums;
        n = nums.size();
        combination({}, 0);
        
        return res;
    }
};
