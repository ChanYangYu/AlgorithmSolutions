#include <bits/stdc++.h>

using namespace std;
int res[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    //승, 패 그래프에 저장
    for(int i = 0; i < results.size(); i++){
        int winner = results[i][0];
        int loser = results[i][1];
        
        res[loser][winner] = -1;
        res[winner][loser] = 1;
        
    }
    
    //승,패 기록이 없는칸에는 987654321으로 초기화
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(res[i][j] == 0)
                res[i][j] = 987654321;

    
    //Floyd-Washall 알고리즘을 통해 승, 패 모든 기록 저장
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(res[i][j] == 987654321){
                    if(res[i][k] == 1 && res[k][j] == 1)
                        res[i][j] = 1;
                    else if(res[i][k] == -1 && res[k][j] == -1)
                        res[i][j] = -1;
                }
            }
        }
    }
    
    //자신의 순서를 알기위해서는 다른 선수와의 승, 패를 모두 알고있어야한다.
    for(int i = 1; i <= n; i++){
        bool check = true;
        for(int j = 1; j <= n; j++){
            if(i != j && res[i][j] == 987654321){
                check = false;
                break;
            }
        }
        if(check)
            answer++;
    }
    return answer;
}
