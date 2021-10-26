#include <bits/stdc++.h>

using namespace std;

int cache[5001][1<<8];
int n;
vector<vector<int>> d;

int solve(int r, int state){
    int& ret = cache[r][state];
    
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(int i = 0; i < n; i++)
        if((state & (1<<i)) == 0)
            if(r >= d[i][0])
                ret = max(ret, solve(r-d[i][1], (state | (1<<i)))+1);
        
    return ret;
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    d = dungeons;
    n = d.size();
    
    memset(cache, -1, sizeof(cache));
    answer = solve(k, 0);
    return answer;
}
