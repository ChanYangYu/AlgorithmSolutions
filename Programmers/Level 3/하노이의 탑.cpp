#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > res;
/*
n = �Űܾ��� ���� ��
s = ������ �ִ� ���� ž
e = ������ �Ű��� ������ ž
m = ���İ��� �߰� ž
*/
void solve(int n, int s, int e, int m){
    //�ű� ������ �ϳ���� ������ ž���� �̵�
    if(n == 1)
        res.push_back({s, e});
    //�ű� ������ 2�� �̻��� ���
    else{
        //���� ž���� �߰� ž���� n-1���� �Űܳ��´�.
        solve(n-1, s, m, e);
        //����ž�� ������ ������ ������ ž���� �Űܳ��´�.
        res.push_back({s, e});
        //�߰� ž���� n-1�� ������ ������ ž�� �Űܳ��´�.
        solve(n-1, m, e, s);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    //���� ���� = n, ���� ž = 1, ������ ž = 3, �߰� ž = 2
    solve(n, 1, 3, 2);
    
    answer = res;
    return answer;
}
