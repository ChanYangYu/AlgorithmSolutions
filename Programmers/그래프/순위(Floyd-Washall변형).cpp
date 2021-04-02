#include <bits/stdc++.h>

using namespace std;
int res[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    //��, �� �׷����� ����
    for(int i = 0; i < results.size(); i++){
        int winner = results[i][0];
        int loser = results[i][1];
        
        res[loser][winner] = -1;
        res[winner][loser] = 1;
        
    }
    
    //��,�� ����� ����ĭ���� 987654321���� �ʱ�ȭ
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(res[i][j] == 0)
                res[i][j] = 987654321;

    
    //Floyd-Washall �˰����� ���� ��, �� ��� ��� ����
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
    
    //�ڽ��� ������ �˱����ؼ��� �ٸ� �������� ��, �и� ��� �˰��־���Ѵ�.
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
