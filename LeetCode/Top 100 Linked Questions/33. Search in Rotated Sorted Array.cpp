class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            
            int l_start = -1, l_end = -1;
            int r_start = -1, r_end = -1;
            bool l_has_pivot = false;
            bool r_has_pivot = false;
            
            //mid 왼쪽에 원소가 있는 경우
            if(mid-1 >= left){
                l_start = left;
                l_end = mid-1;
                
                if(nums[l_start] > nums[l_end])
                    l_has_pivot = true;
            }
            
            //mid 오른쪽에 원소가 있는 경우
            if(mid+1 <= right){
                r_start = mid+1;
                r_end = right;
                
                if(nums[r_start] > nums[r_end])
                    r_has_pivot = true;
            }
            
            //left 범위에 target이 들어가는 경우
            if(l_start != -1 && nums[l_start] <= target && target <= nums[l_end]){
                left = l_start;
                right = l_end;
                continue;
            }
            
            //right 범위에 target이 들어가는 경우
            if(r_start != -1 && nums[r_start] <= target && target <= nums[r_end]){
                left = r_start;
                right = r_end;
                continue;
            }
            
            //왼쪽에 pivot이 존재하는 경우(그 사이에 정답이 존재할 수 있음)
            if(l_has_pivot){
                if(l_start != -1){
                    left = l_start;
                    right = l_end;
                }
                else
                    return -1;
            }
            
            //오른쪽에 pivot이 존재하는 경우
            else if(r_has_pivot){
                if(r_start != -1){
                    left = r_start;
                    right = r_end;
                }
                else
                    return -1;
            }
            else
                return -1;
        }
        return -1;
    }
};
