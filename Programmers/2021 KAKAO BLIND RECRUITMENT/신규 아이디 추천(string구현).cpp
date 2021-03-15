#include <bits/stdc++.h>

using namespace std;

string solution(string n) {
    string answer = "";
    string tmp = "";
    
    //1단계
    for(int i = 0; i < n.size(); i++)
        if(n[i] >= 'A' && n[i] <= 'Z')
            n[i] += 32;
    
    //2단계
    for(int i = 0; i < n.size(); i++){
        if(n[i] == '-' || n[i] == '_' || n[i] == '.' || (n[i] >= 'a' && n[i] <= 'z') || (n[i] >= '0' && n[i] <= '9'))
            tmp += string(1, n[i]); 
    }
    
    // 3 단계
    for(int i = 0; i < tmp.size(); i++){
        answer += string(1,tmp[i]);
        while (i+1 < tmp.size() && tmp[i] == '.' && tmp[i + 1] == '.')
            i++;
    }
    
    //4단계
    if(answer.front() == '.')
        answer = answer.substr(1);
    
    if(answer.back() == '.')
        answer = answer.substr(0, answer.size()-1);
    
    //5단계
    if(answer.size() == 0)
        answer = "a";
    
    //6단계
    if(answer.size() > 15)
        answer = answer.substr(0,15);
    if(answer.back() == '.')
        answer = answer.substr(0, answer.size()-1);
    
    //7단계
    int idx = answer.size();
    while(answer.size() < 3)
        answer += string(1, answer[idx-1]);
    return answer;
}
