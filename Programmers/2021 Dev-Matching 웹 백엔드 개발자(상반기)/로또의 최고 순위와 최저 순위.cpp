#include <bits/stdc++.h>

using namespace std;

int win[46];

int get_grade(int cnt){
    if(cnt == 6)
        return 1;
    else if(cnt == 5)
        return 2;
    else if(cnt == 4)
        return 3;
    else if(cnt == 3)
        return 4;
    else if(cnt == 2)
        return 5;
    else
        return 6;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int blank = 0;
    
    for(int i = 0; i < win_nums.size(); i++)
        win[win_nums[i]] = 1;
    
    for(int i = 0; i < lottos.size(); i++){
        if(win[lottos[i]])
            cnt++;
        else if(lottos[i] == 0)
            blank++;
    }
    
    int best = cnt+blank;
    int worst = cnt;
    
    answer.push_back(get_grade(best));
    answer.push_back(get_grade(worst));
    
    
    return answer;
}
