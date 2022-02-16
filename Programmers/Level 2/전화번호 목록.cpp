#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i < phone_book.size(); i++)
        mp[phone_book[i]]++;
    
    for(int i = 0; i < phone_book.size(); i++){
        string s = "";
        for(int j = 0; j < phone_book[i].size(); j++){
            s += phone_book[i][j];
            
            if(mp[s] == 1 && s != phone_book[i]){
                return false;
            }
        }
    }
    
    return answer;
}
