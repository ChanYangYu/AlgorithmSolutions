#include <bits/stdc++.h>

using namespace std;

class Data{
  public:
    int y;
    int x;
    int d;
    int cnt;
    
    Data(int y, int x, int d, int cnt){
        this->y = y;
        this->x = x;
        this->d = d;
        this->cnt = cnt;
    }
};

// µ¿, ¼­, ³², ºÏ
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int ch[501][501][4];

int turn_left(int d){
    if(d == 0)
        return 3;
    if(d == 1)
        return 2;
    if(d == 2)
        return 0;
    if(d == 3)
        return 1;
}

int turn_right(int d){
    if(d == 0)
        return 2;
    if(d == 1)
        return 3;
    if(d == 2)
        return 1;
    if(d == 3)
        return 0;
}

int get_circular_length(int row, int col, int dir, vector<string>& grid){
    queue<Data> q;
    int row_size = grid.size();
    int col_size = grid[0].size();
    int l;
    
    q.push(Data(row, col, dir, 1));
    ch[row][col][dir] = 1;
    
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int d = q.front().d;
        int cnt = q.front().cnt;
        
        q.pop();
        
        if(grid[y][x] == 'L')
            d = turn_left(d);
        else if(grid[y][x] == 'R')
            d = turn_right(d);
        
        y = y + dy[d];
        x = x + dx[d];
        
        if(y < 0)
            y = row_size - 1;
        else if(y >= row_size)
            y = 0;
        else if(x < 0)
            x = col_size -1;
        else if(x >= col_size)
            x = 0;
        
        if(ch[y][x][d] > 0){
            l = cnt;
            break;
        }
        cnt++;
        ch[y][x][d] = cnt;
        q.push(Data(y, x, d, cnt));
    }
    
    return l;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            for(int k = 0; k < 4; k++){
                if(ch[i][j][k] == 0){
                    int l = get_circular_length(i, j, k, grid);
                    
                    answer.push_back(l);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
