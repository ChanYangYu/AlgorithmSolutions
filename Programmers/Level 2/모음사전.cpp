#include <bits/stdc++.h>

using namespace std;
char alpha[5] = {'A', 'E', 'I', 'O', 'U'};
int idx;
unordered_map<string, int> mp;

void calc(int cnt, string s){
    if(cnt > 5)
        return;
    mp[s] = idx;
    idx++;
    for(int i = 0; i < 5; i++)
        calc(cnt+1, s + alpha[i]);
}


int solution(string word) {
    int answer = 0;
    
    calc(0, "");
    
    return mp[word];
}
