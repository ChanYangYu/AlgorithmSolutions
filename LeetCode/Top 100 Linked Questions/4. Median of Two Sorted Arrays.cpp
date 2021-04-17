class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int sum = num1.size() + num2.size();
        
        int one = sum / 2;
        int two = sum / 2 - 1;

        int idx1 = 0;
        int idx2 = 0;

        int idx = 0;
        
        double first, second;
        while(idx1 < num1.size() && idx2 < num2.size()){
            if(num1[idx1] < num2[idx2]){
                if(one == idx)
                    first = num1[idx1];
                else if(two == idx)
                    second = num1[idx1]; 
                idx1++;
                idx++;
            }
            else{
                if(one == idx)
                    first = num2[idx2];
                else if(two == idx)
                    second = num2[idx2]; 
                idx2++;
                idx++;
            }
        }
        while(idx1 < num1.size()){
            if(one == idx)
                first = num1[idx1];
            else if(two == idx)
                second = num1[idx1]; 
            idx1++;
            idx++;
        }
        while(idx2 < num2.size()){
            if(one == idx)
                first = num2[idx2];
            else if(two == idx)
                second = num2[idx2]; 
            idx2++;
            idx++;
        }
        
        if(sum % 2 == 0)
            return (first + second) / 2.0;
        else
            return first;
    }
};
