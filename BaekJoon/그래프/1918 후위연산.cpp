#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> prio;
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	stack<char> op;
	string exp;
	
	cin>>exp;
	
	int i = 0;
	prio['*'] = 2;
	prio['/'] = 2;
	prio['+'] = 1;
	prio['-'] = 1;
	while(i < exp.size()){
		if(exp[i] >= 'A' && exp[i] <= 'Z')
			cout<<exp[i];
		else if(exp[i] == '(')
			op.push(exp[i]);
		else if(exp[i] == ')'){
			while(op.top() != '('){
				char oper = op.top();
				op.pop();
				cout<<oper;
			}
			op.pop();
		}
		else{
			//스택이 비어있는 경우 
			if(op.empty())
				op.push(exp[i]);
			else{
				//현재 우선순위가 더 큰경우 
				if(prio[op.top()] < prio[exp[i]])
					op.push(exp[i]);
				else{
					//현재 연산자와 연산자 스택의 우선순위가 같거나 큰 연산자 pop 
					while(!op.empty() && prio[op.top()] >= prio[exp[i]]){
						cout<<op.top();
						op.pop();
					}
					op.push(exp[i]);
				}
			}
		}
		i++;
	}
	
	while(!op.empty()){
		cout<<op.top();
		op.pop();
	}
    return 0;
}
