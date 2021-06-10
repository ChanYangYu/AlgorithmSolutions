class Solution {
public:
    int cache[501][501];
    string w1;
    string w2;
    int solve(int w1_idx, int w2_idx){
        int& ret = cache[w1_idx][w2_idx];
        
        if(ret != -1)
            return ret;
        
        // ���� ���� ���
        if(w2_idx == w2.size())
            //���� word���� ��� �߰�
            return ret = w1.size() - w1_idx;
        // ���� ���� �� ���� ���
        else if(w1_idx == w1.size())
            return ret = w2.size() - w2_idx;
        
        // word1 word2�� �ٸ� ���
        if(w1[w1_idx] != w2[w2_idx]){
            // Insert
            ret = solve(w1_idx, w2_idx + 1) + 1;
            // Delete
            ret = min(ret, solve(w1_idx + 1, w2_idx) + 1);
            // Replace
            ret = min(ret, solve(w1_idx + 1, w2_idx + 1) + 1);
        }
        // �������
        else
            ret = solve(w1_idx + 1, w2_idx + 1);
        
        return ret;
    }
    int minDistance(string word1, string word2) {
        w1 = word1;
        w2 = word2;
        
        memset(cache, -1, sizeof(cache));
        
        return solve(0, 0);
    }
};
