#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int m, int n, vector<vector<int>> p) {
    ios_base::sync_with_stdio(false);
    int answer = 0;
    vector<vector<int> > dy(n+1, vector<int>(m+1,0));
    
    //시작점 1로 초기화
    dy[1][1] = 1;
    
    //웅덩이 -1로 초기화
    for(int i = 0; i < p.size(); i++){
        int x = p[i][0];
        int y = p[i][1];
        dy[y][x] = -1;
    }
    
    //가로 1로 초기화
    for(int i = 2; i <= n; i++){
        //웅덩이 만나면 종료
        if(dy[i][1] == -1)
            break;
        else
            dy[i][1] = 1;
    }
    
    //세로 1로 초기화
    for(int i = 2; i <= m; i++){
        //웅덩이 만나면 종료
        if(dy[1][i] == -1)
            break;
        else
            dy[1][i] = 1;
    }
    
    //2행 2열부터 탐색 시작
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            //웅덩이면 continue
            if(dy[i][j] == -1)
                continue;
            //위가 웅덩이가 아니면
            if(dy[i-1][j] != -1)
                dy[i][j] += dy[i-1][j];
            //옆이 웅덩이가 아니면
            if(dy[i][j-1] != -1)
                dy[i][j] += dy[i][j-1];
            //효율성 값 계산
            dy[i][j] %= 1000000007;
        }
    }
    answer = dy[n][m];
    return answer;
}
