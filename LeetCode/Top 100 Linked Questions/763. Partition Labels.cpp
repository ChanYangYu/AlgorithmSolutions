/*
    풀이
    1. 각 알파벳의 마지막 위치 alpha에 저장
    2. 알파벳 범위내 모든 알파벳의 범위를 cnt로 개수세기
    3. res에 저장
*/

class Solution {
public:
    int alpha[26];
    vector<int> partitionLabels(string s) {
        vector<int> res;
        
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'a';
            
            alpha[idx] = i;
        }
        
        int idx = 0;
        while(idx < s.size()){
            int cur = idx;
            int next = alpha[s[idx] - 'a'];
            int cnt = 0;
            
            for(; idx <= next; idx++){
                next = max(next, alpha[s[idx] - 'a']);
                cnt++;
            }
            
            res.push_back(cnt);
        }
        
        return res;
    }
};
