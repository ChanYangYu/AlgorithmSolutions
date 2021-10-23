#include <bits/stdc++.h>

using namespace std;
class Pos{
  public:
    int y;
    int x;
    
    Pos(int y, int x){
        this->y = y;
        this->x = x;
    }
};

bool y_check(int y, int x, int diff, int m, char t, vector<string> board){
    bool check = true;
    for(int i = 0; i < diff; i++){
        y += m;
        if(board[y][x] != '.' && board[y][x] != t){
            check = false;
            break;
        }
    }
    return check;
}

bool x_check(int y, int x, int diff, int m, char t, vector<string> board){
    bool check = true;
    for(int i = 0; i < diff; i++){
        x += m;
        if(board[y][x] != '.' && board[y][x] != t){
            check = false;
            break;
        }
    } 
    return check;
}

bool possible_erase(Pos start, Pos end, vector<string> board){
    int diff_y;
    int diff_x;
    int m_y;
    int m_x;
    char target = board[end.y][end.x];
    
    //y
    if(end.y < start.y){
        diff_y = abs(end.y - start.y);
        m_y = -1;
    }
    else{
        diff_y = end.y - start.y;
        m_y = 1;
    }
    
    //x
    if(end.x < start.x){
        diff_x = abs(end.x - start.x);
        m_x = -1;
    }
    else{
        diff_x = end.x - start.x;
        m_x = 1;
    }
    
    //y -> x
    if(y_check(start.y, start.x, diff_y, m_y, target, board)){
        if(x_check(end.y, start.x, diff_x, m_x, target, board))
            return true;
    }
    //x -> y
    if(x_check(start.y, start.x, diff_x, m_x, target, board)){
        if(y_check(start.y, end.x, diff_y, m_y, target, board))
            return true;
    }
    
    return false;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    int ch[30];
    vector<Pos> blocks[30];

    for(int i = 0; i < 30; i++)
        ch[i] = 0;
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] < 'A' || board[i][j] > 'Z')
                continue;
            int cur = board[i][j] - 'A';
            blocks[cur].push_back(Pos(i,j));
        }
    }
    
    
    while(1){
        bool check = true;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] >= 'A' && board[i][j] <= 'Z'){
                    check = false;
                    break;
                }
            }
            if(!check)
                break;
        }
        
        //모두 제거
        if(check)
            return answer;
        
        check = true;
        for(int i = 0; i < 30; i++){
            if(ch[i] == 0 && blocks[i].size() > 0){
                if(possible_erase(blocks[i][0], blocks[i][1], board)){
                    ch[i] = 1;
                    check = false;
                    answer += string(1, 'A' + i);
                    int y = blocks[i][0].y;
                    int x = blocks[i][0].x;
                    
                    board[y][x] = '.';
                    y = blocks[i][1].y;
                    x = blocks[i][1].x;
                    
                    board[y][x] = '.';
                    break;
                }
            }
        }
        
        if(check)
            return "IMPOSSIBLE";
                    
    }
}
