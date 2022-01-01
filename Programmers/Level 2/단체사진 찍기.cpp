#include <bits/stdc++.h>

using namespace std;

/*
	1. 전체 줄세우기
	2. 조건에 맞는지 검토 
	
	오답노트
	- 전역변수 초기화를 해주지 않아 실패가 떴었음... 
*/
 
vector<string> cond;
char f[8] = {'A','C', 'F', 'J', 'M', 'N', 'R', 'T'};
char sel[8];
int ch[26];
int res;

bool check(){
    bool res = true;
    
    for(int i = 0; i < cond.size(); i++){
        char a = cond[i][0];
        char b = cond[i][2];
        char o = cond[i][3];
        int num = cond[i][4] - '0';
        
        int a_idx;
        int b_idx;
        
        for(int i = 0; i < 8; i++){
            if(sel[i] == a){
                a_idx = i;
            }
            if(sel[i] == b){
                b_idx = i;
            }
        }
        
        if(o == '=' && !(abs(a_idx - b_idx) == num+1)){
            return false;
        }
        else if(o == '<' && !(abs(a_idx - b_idx) < num+1)){
            return false;
        }
        else if(o == '>' && !(abs(a_idx - b_idx) > num+1)){
            return false;
        }
    }
    return true;
}

void recur(int n){
    if(n == 8){
        if(check())
            res++;
        return;
    }
    
    
    for(int i = 0; i < 8; i++){
        int cur = f[i] - 'A';
        if(ch[cur] == 0){
            sel[n] = f[i];
            ch[cur] = 1;
            recur(n+1);
            ch[cur] = 0;
        }
    }
}



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    res = 0;
    cond = data;
    recur(0);
    return res;
}
