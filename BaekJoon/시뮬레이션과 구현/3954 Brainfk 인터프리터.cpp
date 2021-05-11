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
		//명령어 끝에 도달한 경우 
		if(cmd_ptr >= cmd.size())
			break;
		
		//루프 시작 
		if(cmd[cmd_ptr] == '['){
			if(m_mem[ptr] != 0){
				//내부 루프 수행
				int excute = solve(cmd_ptr+1);
				i += excute;
				//오답노트 : 루프를 한번이라도 완료한 경우라도 내부에서 무한루프에 걸릴 수 있다. 
				//실행횟수 5천만을 넘겼고, 한번이라도 실행완료 한경우 
				if(i >= MAX && finished[cmd_ptr] 
				&& start_loop == -1 && end_loop == -1 && excute >= MAX){
					start_loop = cmd_ptr;
					end_loop = jmp_point[cmd_ptr];
					return i;
				}
			}
			//점프
			cmd_ptr = jmp_point[cmd_ptr];	
		}
		else if(cmd[cmd_ptr] == ']'){
			//0인 경우 루프종료
			if(m_mem[ptr] == 0)
				return i+1;
			//루프 완료 체크 
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
			//포인터 위치 음수처리 
			if(ptr == 0)
				ptr = m-1;
			else
				ptr--;
		}
		else if(cmd[cmd_ptr] == '>'){
			//포인터위치 범위초과 처리 
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
		
		//점프 포인트 저장 
		for(int i = 0; i < cmd.size(); i++){
			//루프 완료 배열 초기화 
			finished[i] = 0;
			if(cmd[i] == '[')
				pos.push(i);
			else if(cmd[i] == ']'){
				jmp_point[pos.top()] = i;
				jmp_point[i] = pos.top();
				pos.pop();
			}
		}
		
		//메모리 초기화 
		for(int i = 0; i < m; i++)
			m_mem[i] = 0;
		
		start_loop = -1;
		end_loop = -1;
		
		int res = solve(0);
		
		//오답 : 5000만 이상까지는 정상종료 가능 
		if(res <= MAX)
			cout<<"Terminates\n";
		else
			cout<<"Loops"<<" "<<start_loop<<" "<<end_loop<<"\n"; 
	}
	
	return 0;
}
