#include <bits/stdc++.h>

using namespace std;
int num_y[10] = {4,1,1,1,2,2,2,3,3,3};
int num_x[10] = {2,1,2,3,1,2,3,1,2,3};
int calc_dis(int y, int x, int target){   
    return abs(num_y[target] - y) + abs(num_x[target] - x);
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_y = 4;
    int left_x = 1;
    
    int right_y = 4;
    int right_x = 3;
    
    for(int i = 0; i < numbers.size(); i++){
        int target = numbers[i];
        int left_move = calc_dis(left_y, left_x, target);
        int right_move = calc_dis(right_y, right_x, target);
        
        if(target == 1 || target == 4 || target == 7){
            answer += "L";
            left_y = num_y[target];
            left_x = num_x[target];
        }
        else if(target == 3 || target == 6 ||  target == 9){
            answer += "R";
            right_y = num_y[target];
            right_x = num_x[target];
        }
        
        else{    
            if(left_move < right_move){
                answer += "L";
                left_y = num_y[target];
                left_x = num_x[target];
            }
            else if(left_move > right_move){
                answer += "R";
                right_y = num_y[target];
                right_x = num_x[target];
            }
            else{
                if(hand == "left"){
                    answer += "L";
                    left_y = num_y[target];
                    left_x = num_x[target];
                }
                else{
                    answer += "R";
                    right_y = num_y[target];
                    right_x = num_x[target];
                }
            }
        }
    }
    return answer;
}
