#include <bits/stdc++.h>
#define INF 987654321

using namespace std;
int dis[201][201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    //자기자신으로 가는거리 제외 모두 거리 무한으로 초기화
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            dis[i][j] = INF;
            
        }
    }
    
    //간선 추가
    for(int i = 0; i < fares.size(); i++){
        int c, d, f;
        
        c = fares[i][0];
        d = fares[i][1];
        f = fares[i][2];
        
        dis[c][d] = f;
        dis[d][c] = f;
    }
    
    //Floyd-Warshall 알고리즘으로 전체 간선간의 최소거리 계산
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    
    //answer 무한대로 초기화
    answer = 987654321;
    
    //각 지점으로 이동 후 각자의 집으로 이동하는 거리의 합이 최소값인지 계산
    for(int i = 1; i <= n; i++){
        if(dis[s][i] == INF || dis[i][a] == INF || dis[i][b] == INF)
            continue;
        if(answer > dis[s][i] + dis[i][a] + dis[i][b])
            answer = dis[s][i] + dis[i][a] + dis[i][b];
    }
    
    return answer;
}
