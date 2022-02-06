/*
    Ǯ��
     1. cache => �ش� ���ڵ��� �迭�ϴ� ����Ǽ�
     2. ���ڸ� �������� ��, �� ��� ������ ���ڵ��� �迭�ϴ� ����� �� ���� cache�� ����
*/
class Solution {
public:
    int res;
    int cache[20];
    
    int solve(int l, int r){
        int cnt = r - l + 1;
        
        if(cache[cnt] != 0)
            return cache[cnt];
        
        for(int i = l; i <= r; i++)
            cache[cnt] += solve(l, i-1) * solve(i+1, r);
        
        return cache[cnt];
    }
    
    int numTrees(int n) {
        cache[0] = 1;
        
        return solve(1, n);
    }
};
