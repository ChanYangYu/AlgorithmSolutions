#include <bits/stdc++.h>
using namespace std;
char state[5][8];
/*오답노트
 - 가장 왼쪽이 1번이라고 생각하여 입력도 이 순서대로 받는것이라 생각
 - 문제에서 같은극인 경우 움직이지 않는다고 했는데 제대로 읽지 않음 
 고쳐야할 부분 : 문제를 꼼꼼이 읽기 (입력, 출력, 제약조건)  
*/
int pos[5] = {6, 6, 6, 6, 6};

void turn(int idx, int dir){
	//시계방향의 경우 인덱스가 감소하므로 -dir
	pos[idx] += -dir;
	if(pos[idx] < 0)
		pos[idx] = 7;
	if(pos[idx] >= 8)
		pos[idx] = 0;
}

void left_turn(int idx, int dir){
	//왼쪽 마지막 톱니인 경우 
	if(idx == 1)
		turn(idx, dir);
	else{
		//현재 톱니의 동쪽과 왼쪽 톱니의 서쪽이 다른 극이면 
		if(state[idx][pos[idx] % 8] != state[idx-1][(pos[idx-1] + 4) % 8])
			left_turn(idx-1, -dir);
		//이동
		turn(idx, dir);
	}
}

void right_turn(int idx, int dir){
	//오른쪽 마지막 톱니인 경우 
	if(idx == 4)
		turn(idx, dir);
	else{
		//현재 톱니의 서쪽과 오른쪽 톱니의 동쪽이 다른 극이면 
		if(state[idx][(pos[idx] + 4) % 8] != state[idx+1][pos[idx+1] % 8])
			right_turn(idx+1, -dir);
		//이동
		turn(idx, dir);
	}
}

int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	for(int i = 1; i <= 4; i++)
		for(int j = 0; j < 8; j++)
			cin>>state[i][j];
	
	int k;
	
	cin>>k;
	
	for(int i = 0; i < k; i++){
		int num, dir;
		
		cin>>num>>dir;
		
		//왼쪽마지막 톱니가 아닌경우 
		if(num > 1){
			if(state[num][pos[num] % 8] != state[num-1][(pos[num-1] + 4) % 8])
				left_turn(num-1, -dir);
		}
		//오른쪽 마지막 톱니가 아닌 경우 
		if(num < 4){
			if(state[num][(pos[num] + 4) % 8] != state[num+1][pos[num+1] % 8])
				right_turn(num+1, -dir);
		}
		//해당 톱니바퀴 이동 
		turn(num, dir);
		
	}
	
	int res = 0;
	int t = 1;
	for(int i = 1; i <= 4; i++){
		res += (state[i][(pos[i] + 2) % 8] - 48) * t;
		t *= 2;
	}
	
	cout<<res;
	return 0;
}
