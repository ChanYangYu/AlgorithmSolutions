class Solution {
public:
    bool m_binary_search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int pos = -1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(nums[mid] == target)
                return true;
            
            if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        
        return false;
    }
    
    int get_start(vector<int>& nums, int target){   
        int left = 0;
        int right = nums.size() - 1;
        int pos = -1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(nums[mid] == target)
                pos = mid;
            
            if(nums[mid] >= target)
                right = mid-1;
            else
                left = mid+1;
        }
        
        return pos;
    }
    
    int get_end(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int pos = -1;
        
        while(left <= right){
            cout<<left<<" "<<right<<"\n";
            int mid = (left + right) / 2;
            
            if(nums[mid] == target)
                pos = mid;
            
            if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        
        return pos;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(m_binary_search(nums, target) == false)
            return {-1, -1};
        
        int start = get_start(nums, target);
        int end = get_end(nums, target);
        
//         if(binary_search(nums.begin(), nums.end(), target) == false)
//             return {-1, -1}; 
//         int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
//         int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
		
        return {start, end};
    }
};

