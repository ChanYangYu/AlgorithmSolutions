#include <bits/stdc++.h>

using namespace std;

/*
	1. ��ü �ټ����
	2. ���ǿ� �´��� ���� 
	
	�����Ʈ
	- �������� �ʱ�ȭ�� ������ �ʾ� ���а� ������... 
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



// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int solution(int n, vector<string> data) {
    res = 0;
    cond = data;
    recur(0);
    return res;
}
