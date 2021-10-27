#include <bits/stdc++.h>

using namespace std;

int ch[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> p) {
    
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            ch[i][j] = 0;
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(p[i][j] != 0 && ch[i][j] == 0){
                queue<pair<int, int> > q;
                int cnt = 1;
                int color = p[i][j];
                
                number_of_area++;
                q.push({i, j});
                ch[i][j] = 1;
                
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    
                    q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int yy = y + dy[k];
                        int xx = x + dx[k];
                        
                        if(yy < 0 || yy >= m || xx < 0 || xx >= n)
                            continue;
                        if(ch[yy][xx] == 1 || p[yy][xx] != color)
                            continue;
                        
                        ch[yy][xx] = 1;
                        cnt++;
                        q.push({yy, xx});
                    }
                }
                
                max_size_of_one_area = max(cnt, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
