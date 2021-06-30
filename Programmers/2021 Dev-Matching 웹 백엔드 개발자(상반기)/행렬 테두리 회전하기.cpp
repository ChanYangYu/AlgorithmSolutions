#include <bits/stdc++.h>

using namespace std;
int mp[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int cnt = 1;
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++)
            mp[i][j] = cnt++;
    
    for(int i = 0; i < queries.size(); i++){
        int y1 = queries[i][0];
        int x1 = queries[i][1];
        int y2 = queries[i][2];
        int x2 = queries[i][3];
        
        int next = 0;
        int mn = 987654321;
        
        // >
        for(int j = x1; j < x2; j++){
            if(next == 0){
                next = mp[y1][j+1];
                mp[y1][j+1] = mp[y1][j];
                mn = min(mn, mp[y1][j]);
            }
            else{
                mn = min(mn, next);
                int tmp = mp[y1][j+1];
                mp[y1][j+1] = next;
                next = tmp;
            }
        }
        
        // v
        for(int j = y1; j < y2; j++){
            mn = min(mn, next);
            int tmp = mp[j+1][x2];
            mp[j+1][x2] = next;
            next = tmp;
        }
        
        // <
        for(int j = x2; j > x1; j--){
            mn = min(mn, next);
            int tmp = mp[y2][j-1];
            mp[y2][j-1] = next;
            next = tmp;
        }
        
        // ^
        for(int j = y2; j > y1; j--){
            mn = min(mn, next);
            int tmp = mp[j-1][x1];
            mp[j-1][x1] = next;
            next = tmp;
        }
        answer.push_back(mn);
    }
    return answer;
}
