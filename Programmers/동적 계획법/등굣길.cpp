#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(int m, int n, vector<vector<int>> p) {
    ios_base::sync_with_stdio(false);
    int answer = 0;
    vector<vector<int> > dy(n+1, vector<int>(m+1,0));
    
    //������ 1�� �ʱ�ȭ
    dy[1][1] = 1;
    
    //������ -1�� �ʱ�ȭ
    for(int i = 0; i < p.size(); i++){
        int x = p[i][0];
        int y = p[i][1];
        dy[y][x] = -1;
    }
    
    //���� 1�� �ʱ�ȭ
    for(int i = 2; i <= n; i++){
        //������ ������ ����
        if(dy[i][1] == -1)
            break;
        else
            dy[i][1] = 1;
    }
    
    //���� 1�� �ʱ�ȭ
    for(int i = 2; i <= m; i++){
        //������ ������ ����
        if(dy[1][i] == -1)
            break;
        else
            dy[1][i] = 1;
    }
    
    //2�� 2������ Ž�� ����
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            //�����̸� continue
            if(dy[i][j] == -1)
                continue;
            //���� �����̰� �ƴϸ�
            if(dy[i-1][j] != -1)
                dy[i][j] += dy[i-1][j];
            //���� �����̰� �ƴϸ�
            if(dy[i][j-1] != -1)
                dy[i][j] += dy[i][j-1];
            //ȿ���� �� ���
            dy[i][j] %= 1000000007;
        }
    }
    answer = dy[n][m];
    return answer;
}
