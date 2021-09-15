#include <bits/stdc++.h>

using namespace std;

string connect_string(int target_cnt, string target){
    string str = "";
    if(target_cnt > 1)
        str += to_string(target_cnt);
    return str + target;
}

int get_length(int n, string s){
    string res = "";
    string target = s.substr(0, n);
    int target_cnt = 1;
    int size = s.size();
    int i = n;
    
    while(i < size){
        int pos = (i+n >= size) ? size-i : n;
        string cur = s.substr(i, pos);
        
        if(target == cur){
            target_cnt++;
        }
        else{
            res += connect_string(target_cnt, target);
            target_cnt = 1;
            target = cur;
        }
        i += n;
    }
    res += connect_string(target_cnt, target);
    return res.size();
}


int solution(string s) {
    int answer = s.size();
    int range = s.size() / 2;
    
    for(int i = 1; i <= range; i++){
        answer = min(answer, get_length(i, s));
    }
    return answer;
}
