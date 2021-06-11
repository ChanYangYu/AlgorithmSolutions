#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > res;
/*
n = 옮겨야할 원반 수
s = 원판이 있는 시작 탑
e = 원판이 옮겨질 목적지 탑
m = 거쳐가는 중간 탑
*/
void solve(int n, int s, int e, int m){
    //옮길 원판이 하나라면 목적지 탑으로 이동
    if(n == 1)
        res.push_back({s, e});
    //옮길 원판이 2개 이상인 경우
    else{
        //시작 탑에서 중간 탑으로 n-1개를 옮겨놓는다.
        solve(n-1, s, m, e);
        //시작탑의 마지막 원판을 목적지 탑으로 옮겨놓는다.
        res.push_back({s, e});
        //중간 탑에서 n-1개 원판을 목적지 탑에 옮겨놓는다.
        solve(n-1, m, e, s);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    //원판 개수 = n, 시작 탑 = 1, 목적지 탑 = 3, 중간 탑 = 2
    solve(n, 1, 3, 2);
    
    answer = res;
    return answer;
}
