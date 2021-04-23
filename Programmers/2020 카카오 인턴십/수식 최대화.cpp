#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> prio;
vector<long long> nums;
vector<char> op;

//사칙연산 계산
long long calc(long long a, long long b, char op){
    if(op == '*')
        return a * b;
    else if(op == '+')
        return a + b;
    else
        return a - b;
}

//수식 계산
long long calc_exp(){
    stack<long long> n;
    stack<char> o;
    
    n.push(nums[0]);
    n.push(nums[1]);
    o.push(op[0]);
    int n_idx = 2;
    int o_idx = 1;
    
    while(o_idx < op.size()){
        char cur = op[o_idx];
        if(prio[o.top()] >= prio[cur]){
            while(!o.empty() && prio[o.top()] >= prio[cur]){
                long long a;
                long long b;
                char oper;

                b = n.top();
                n.pop();

                a = n.top();
                n.pop();

                oper = o.top();
                o.pop();

                n.push(calc(a, b, oper));
            }
            n.push(nums[n_idx]);
            o.push(cur);
        }
        else{
            n.push(nums[n_idx]);
            o.push(cur);
        }
        o_idx++;
        n_idx++;
    }
    
    while(!o.empty()){
        long long a;
        long long b;
        char oper;

        b = n.top();
        n.pop();

        a = n.top();
        n.pop();

        oper = o.top();
        o.pop();
        n.push(calc(a, b, oper));
    }
    long long res = n.top();
    
    if(res < 0)
        res = -res;   
    return res;
}

//우선순위 결정
void set_prio(int ml, int pl, int mi){
    prio['*'] = ml;
    prio['+'] = pl;
    prio['-'] = mi;
}

//main
long long solution(string exp) {
    long long answer = 0;
    
    int i = 0;
    while(i < exp.size()){
        if(exp[i] >= '0' && exp[i] <= '9'){
            long long tmp = exp[i] - 48;
            i++;
            while(i < exp.size() && exp[i] >= '0' && exp[i] <= '9'){
                tmp *= 10;
                tmp += exp[i] - 48;
                i++;
            }
            nums.push_back(tmp);
        }
        else{          
            op.push_back(exp[i]);
            i++;
        }
    }
    
    //모든 경우의 수 체크
    set_prio(3,2,1);
    answer = max(answer, calc_exp());
    set_prio(3,1,2);
    answer = max(answer, calc_exp());
    set_prio(1,3,2);
    answer = max(answer, calc_exp());
    set_prio(2,3,1);
    answer = max(answer, calc_exp());
    set_prio(1,2,3);
    answer = max(answer, calc_exp());
    set_prio(2,1,3);
    answer = max(answer, calc_exp());
    
    return answer;
}
