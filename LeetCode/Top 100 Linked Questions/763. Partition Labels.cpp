/*
    Ǯ��
    1. �� ���ĺ��� ������ ��ġ alpha�� ����
    2. ���ĺ� ������ ��� ���ĺ��� ������ cnt�� ��������
    3. res�� ����
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
