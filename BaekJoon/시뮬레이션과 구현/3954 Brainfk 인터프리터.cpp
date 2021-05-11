#include <bits/stdc++.h>
#define MAX 50000000
using namespace std;
int jmp_point[4096];
int finished[4096];
int m_mem[100001];
int m, c, in;
int start_loop;
int end_loop;
int in_ptr;
int ptr;
string cmd;
string input_string;

int solve(int pos){
	int cmd_ptr = pos;
	int i;
	for(i = 0; i < MAX; i++){
		//��ɾ� ���� ������ ��� 
		if(cmd_ptr >= cmd.size())
			break;
		
		//���� ���� 
		if(cmd[cmd_ptr] == '['){
			if(m_mem[ptr] != 0){
				//���� ���� ����
				int excute = solve(cmd_ptr+1);
				i += excute;
				//�����Ʈ : ������ �ѹ��̶� �Ϸ��� ���� ���ο��� ���ѷ����� �ɸ� �� �ִ�. 
				//����Ƚ�� 5õ���� �Ѱ��, �ѹ��̶� ����Ϸ� �Ѱ�� 
				if(i >= MAX && finished[cmd_ptr] 
				&& start_loop == -1 && end_loop == -1 && excute >= MAX){
					start_loop = cmd_ptr;
					end_loop = jmp_point[cmd_ptr];
					return i;
				}
			}
			//����
			cmd_ptr = jmp_point[cmd_ptr];	
		}
		else if(cmd[cmd_ptr] == ']'){
			//0�� ��� ��������
			if(m_mem[ptr] == 0)
				return i+1;
			//���� �Ϸ� üũ 
			else{
				cmd_ptr = jmp_point[cmd_ptr];
				finished[cmd_ptr] = 1;
			}
		}
		else if(cmd[cmd_ptr] == '-'){
			//under-flow 
			if(m_mem[ptr] == 0)
				m_mem[ptr] = 255;
			else
				m_mem[ptr]--;
		}
		else if(cmd[cmd_ptr] == '+'){
			//over-flow
			if(m_mem[ptr] == 255)
				m_mem[ptr] = 0;
			else
				m_mem[ptr]++;
		}
		else if(cmd[cmd_ptr] == '<'){
			//������ ��ġ ����ó�� 
			if(ptr == 0)
				ptr = m-1;
			else
				ptr--;
		}
		else if(cmd[cmd_ptr] == '>'){
			//��������ġ �����ʰ� ó�� 
			if(ptr == m-1)
				ptr = 0;
			else
				ptr++;
		}
		else if(cmd[cmd_ptr] == ','){
			if(in_ptr == in)
				m_mem[ptr] = 255;
			else
				m_mem[ptr] = input_string[in_ptr++];
		}
		cmd_ptr++;	
	}
	
	return i;
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		in_ptr = 0;
		ptr = 0;
		
		cin>>m>>c>>in;
		cin>>cmd;
		cin>>input_string;
		stack<int> pos;
		
		//���� ����Ʈ ���� 
		for(int i = 0; i < cmd.size(); i++){
			//���� �Ϸ� �迭 �ʱ�ȭ 
			finished[i] = 0;
			if(cmd[i] == '[')
				pos.push(i);
			else if(cmd[i] == ']'){
				jmp_point[pos.top()] = i;
				jmp_point[i] = pos.top();
				pos.pop();
			}
		}
		
		//�޸� �ʱ�ȭ 
		for(int i = 0; i < m; i++)
			m_mem[i] = 0;
		
		start_loop = -1;
		end_loop = -1;
		
		int res = solve(0);
		
		//���� : 5000�� �̻������ �������� ���� 
		if(res <= MAX)
			cout<<"Terminates\n";
		else
			cout<<"Loops"<<" "<<start_loop<<" "<<end_loop<<"\n"; 
	}
	
	return 0;
}
