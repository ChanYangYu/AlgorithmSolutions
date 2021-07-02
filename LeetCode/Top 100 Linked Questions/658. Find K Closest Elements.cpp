class Solution {
public:
    
    int my_binary_search(int x, vector<int>& arr){
        int left = 0;
        int right = arr.size()-1;
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(arr[mid] == x)
                return mid;
            else if(arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return left;
    }
    
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> answer;
        int pos = my_binary_search(x, arr);
        int left = pos-1;
        int right = pos;
        
        while(k--){
            if(left < 0)
                answer.push_back(arr[right++]);
            else if(right >= arr.size())
                answer.push_back(arr[left--]);
            else{  
                if(abs(x - arr[left]) <= abs(x - arr[right]))
                    answer.push_back(arr[left--]);
                else
                    answer.push_back(arr[right++]);
            }
        }
        
        sort(answer.begin(), answer.end());
        return answer;
    }
};
