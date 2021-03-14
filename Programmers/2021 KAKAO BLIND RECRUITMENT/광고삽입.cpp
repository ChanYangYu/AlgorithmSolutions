#include <bits/stdc++.h>

using namespace std;
int marking[360000][2];
int num_user[360000];

int calc_time(string t){
    int res = 0;
    
    res += stoi(t.substr(0,2)) * 3600;
    res += stoi(t.substr(3,5)) * 60;
    res += stoi(t.substr(6,8));
    
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    ios_base::sync_with_stdio(false);
    int play, adv;
    
    play = calc_time(play_time);
    adv = calc_time(adv_time);
        
    
    for(int i = 0; i < logs.size(); i++){
        int start = 0;
        int end = 0;
    
        start = calc_time(logs[i]);
        marking[start][0]++;
        
        end += stoi(logs[i].substr(9,11)) * 3600;
        end += stoi(logs[i].substr(12,14)) * 60;
        end += stoi(logs[i].substr(15,17));
        
        marking[end][1]++;
        
    }
    
    int user = 0;
    for(int i = 0; i <= play; i++){
        if(marking[i][0] > 0)       
            user += marking[i][0];
        
        //end지점에서 빠져나간 유저수--(오답노트 : num_user[i] = user보다 위로 와야한다.)
        if(marking[i][1] > 0)
            user -= marking[i][1];
        
        num_user[i] = user;
        
    }
    
    long long mx;
    long long sum = 0;
    int ans_time = 0;
    
    //0 ~ adv 시간까지 합 저장(오답노트 : i <= adv -> 0부터 시작하므로 i < adv가 되어야한다.)
    for(int i = 0; i < adv; i++)
        sum += num_user[i];
    
    mx = sum;
    //adv ~ 끝까지 돌면서 최대합을 구함(오답노트 : i = adv부터 시작해야한다.)
    for(int i = adv; i <= play; i++){
        sum = sum - num_user[i-adv] + num_user[i];
        if(mx < sum){
            ans_time = i - adv + 1;
            mx = sum;
        }
    }
    
    int tmp = ans_time / 3600;
    //시
    if(tmp < 10)
        answer += "0" + to_string(tmp) + ":";
    else
        answer += to_string(tmp) + ":";
    
    //분
    tmp = (ans_time % 3600) / 60;
    if(tmp < 10)
        answer += "0" + to_string(tmp) + ":";
    else
        answer += to_string(tmp) + ":";
    
    //초
    tmp = ((ans_time % 3600) % 60);
    if(tmp < 10)
        answer += "0" + to_string(tmp);
    else
        answer += to_string(tmp);
    
    return answer;
}
