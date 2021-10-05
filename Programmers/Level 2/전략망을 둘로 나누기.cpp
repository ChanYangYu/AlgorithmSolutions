#include <bits/stdc++.h>

using namespace std;
int mp[101][101];

int get_diff(int n){
    int first = 0;
    int second = 0;
    int ch[101];
    
    memset(ch, 0, sizeof(ch));
    for(int i = 1; i <= n; i++){
        if(ch[i] == 0){
            int cnt = 1;
            queue<int> q;
            
            ch[i] = 1;
            q.push(i);
            
            while(!q.empty()){
                int cur = q.front();
                
                q.pop();
                for(int j = 1; j <= n; j++){
                    if(mp[cur][j] == 1 && ch[j] == 0){
                        cnt++;
                        
                        ch[j] = 1;
                        q.push(j);
                    }
                }
            }
            if(first == 0)
                first = cnt;
            else
                second = cnt;
        }
    }
    
    return abs(first - second);
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    for(int i = 0; i < wires.size(); i++){
        int a = wires[i][0];
        int b = wires[i][1];
        
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    
    for(int i = 0; i < wires.size(); i++){
        int a = wires[i][0];
        int b = wires[i][1];
        
        mp[a][b] = 0;
        mp[b][a] = 0;
        
        int cnt = get_diff(n);
        
        answer = min(answer, cnt);
        
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    return answer;
}
