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
			//������ ����ִ� ��� 
			if(op.empty())
				op.push(exp[i]);
			else{
				//���� �켱������ �� ū��� 
				if(prio[op.top()] < prio[exp[i]])
					op.push(exp[i]);
				else{
					//���� �����ڿ� ������ ������ �켱������ ���ų� ū ������ pop 
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
