#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int ch[8];
vector<vector<int> > res;
vector<string> u;
vector<string> b;
int bsize;
int usize;
void dfs(int idx, vector<int> v)
{
    int i, j;
    if(idx == bsize){
        //sort
        sort(v.begin(), v.end());
        //같은 정답이 있을경우 체크
        for(i = 0; i < res.size(); i++){
             for(j = 0; j < bsize; j++){
                 if(v[j] != res[i][j])
                     break;
             }
             if(j == bsize)
                 return;
        }
        //없으면 push
        res.push_back(v);
        return;
    }
    for(i = 0; i < usize; i++){
        //선택되지 않았고 길이가 같으면
        if(ch[i] == 0 && u[i].size() == b[idx].size()){
             int ok = 1;
             int s = u[i].size();
              for(j = 0; j < s; j++){
                 if(b[idx][j] != '*' && u[i][j] != b[idx][j]){
                      ok = 0;
                      break;
                  }
              }
             if(j == s){
                 ch[i] = 1;
                 v.push_back(i);
                 dfs(idx+1, v);
                 v.pop_back();
                 ch[i] = 0;
             }
         }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    u = user_id;
    b = banned_id;
    vector<int> v;
    usize = u.size();
    bsize = b.size();
    dfs(0,v);
    return res.size();
}
