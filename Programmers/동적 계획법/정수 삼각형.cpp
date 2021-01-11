#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> t) {
    ios_base::sync_with_stdio(false);
    int answer = -1;
    for(int i = 1; i < t.size(); i++){
        answer = -1;
        for(int j = 0; j < t[i].size(); j++){
            if(j == 0)
                t[i][j] += t[i-1][0];
            else if(j == t[i].size()-1)
                t[i][j] += t[i-1][j-1];
            else
                t[i][j] += max(t[i-1][j], t[i-1][j-1]);
            if(answer < t[i][j])
                answer = t[i][j];
        }
    }
    return answer;
}
