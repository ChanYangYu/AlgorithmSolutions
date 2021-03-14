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
        
        //end�������� �������� ������--(�����Ʈ : num_user[i] = user���� ���� �;��Ѵ�.)
        if(marking[i][1] > 0)
            user -= marking[i][1];
        
        num_user[i] = user;
        
    }
    
    long long mx;
    long long sum = 0;
    int ans_time = 0;
    
    //0 ~ adv �ð����� �� ����(�����Ʈ : i <= adv -> 0���� �����ϹǷ� i < adv�� �Ǿ���Ѵ�.)
    for(int i = 0; i < adv; i++)
        sum += num_user[i];
    
    mx = sum;
    //adv ~ ������ ���鼭 �ִ����� ����(�����Ʈ : i = adv���� �����ؾ��Ѵ�.)
    for(int i = adv; i <= play; i++){
        sum = sum - num_user[i-adv] + num_user[i];
        if(mx < sum){
            ans_time = i - adv + 1;
            mx = sum;
        }
    }
    
    int tmp = ans_time / 3600;
    //��
    if(tmp < 10)
        answer += "0" + to_string(tmp) + ":";
    else
        answer += to_string(tmp) + ":";
    
    //��
    tmp = (ans_time % 3600) / 60;
    if(tmp < 10)
        answer += "0" + to_string(tmp) + ":";
    else
        answer += to_string(tmp) + ":";
    
    //��
    tmp = ((ans_time % 3600) % 60);
    if(tmp < 10)
        answer += "0" + to_string(tmp);
    else
        answer += to_string(tmp);
    
    return answer;
}
