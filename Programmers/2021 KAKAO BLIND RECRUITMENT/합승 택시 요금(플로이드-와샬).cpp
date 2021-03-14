#include <bits/stdc++.h>
#define INF 987654321

using namespace std;
int dis[201][201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    //�ڱ��ڽ����� ���°Ÿ� ���� ��� �Ÿ� �������� �ʱ�ȭ
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            dis[i][j] = INF;
            
        }
    }
    
    //���� �߰�
    for(int i = 0; i < fares.size(); i++){
        int c, d, f;
        
        c = fares[i][0];
        d = fares[i][1];
        f = fares[i][2];
        
        dis[c][d] = f;
        dis[d][c] = f;
    }
    
    //Floyd-Warshall �˰������� ��ü �������� �ּҰŸ� ���
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    
    //answer ���Ѵ�� �ʱ�ȭ
    answer = 987654321;
    
    //�� �������� �̵� �� ������ ������ �̵��ϴ� �Ÿ��� ���� �ּҰ����� ���
    for(int i = 1; i <= n; i++){
        if(dis[s][i] == INF || dis[i][a] == INF || dis[i][b] == INF)
            continue;
        if(answer > dis[s][i] + dis[i][a] + dis[i][b])
            answer = dis[s][i] + dis[i][a] + dis[i][b];
    }
    
    return answer;
}
