#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b){
    return (a+b) > (b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strs;
    
    for(int i = 0; i < numbers.size(); i++){
        string s = to_string(numbers[i]);
        strs.push_back(s);
    }
    
    sort(strs.begin(), strs.end(), comp);
    
    for(int i = 0; i < numbers.size(); i++)
        answer += strs[i];
    
    if(answer[0] == '0')
        return "0";
    
    return answer;
}
