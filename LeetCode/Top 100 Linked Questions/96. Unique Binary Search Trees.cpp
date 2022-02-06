/*
    풀이
     1. cache => 해당 숫자들을 배열하는 경우의수
     2. 숫자를 선택했을 때, 좌 우로 나눠진 숫자들을 배열하는 경우의 수 곱을 cache에 저장
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
