#include <bits/stdc++.h>
using namespace std;
char state[5][8];
/*�����Ʈ
 - ���� ������ 1���̶�� �����Ͽ� �Էµ� �� ������� �޴°��̶� ����
 - �������� �������� ��� �������� �ʴ´ٰ� �ߴµ� ����� ���� ���� 
 ���ľ��� �κ� : ������ �Ĳ��� �б� (�Է�, ���, ��������)  
*/
int pos[5] = {6, 6, 6, 6, 6};

void turn(int idx, int dir){
	//�ð������ ��� �ε����� �����ϹǷ� -dir
	pos[idx] += -dir;
	if(pos[idx] < 0)
		pos[idx] = 7;
	if(pos[idx] >= 8)
		pos[idx] = 0;
}

void left_turn(int idx, int dir){
	//���� ������ ����� ��� 
	if(idx == 1)
		turn(idx, dir);
	else{
		//���� ����� ���ʰ� ���� ����� ������ �ٸ� ���̸� 
		if(state[idx][pos[idx] % 8] != state[idx-1][(pos[idx-1] + 4) % 8])
			left_turn(idx-1, -dir);
		//�̵�
		turn(idx, dir);
	}
}

void right_turn(int idx, int dir){
	//������ ������ ����� ��� 
	if(idx == 4)
		turn(idx, dir);
	else{
		//���� ����� ���ʰ� ������ ����� ������ �ٸ� ���̸� 
		if(state[idx][(pos[idx] + 4) % 8] != state[idx+1][pos[idx+1] % 8])
			right_turn(idx+1, -dir);
		//�̵�
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
		
		//���ʸ����� ��ϰ� �ƴѰ�� 
		if(num > 1){
			if(state[num][pos[num] % 8] != state[num-1][(pos[num-1] + 4) % 8])
				left_turn(num-1, -dir);
		}
		//������ ������ ��ϰ� �ƴ� ��� 
		if(num < 4){
			if(state[num][(pos[num] + 4) % 8] != state[num+1][pos[num+1] % 8])
				right_turn(num+1, -dir);
		}
		//�ش� ��Ϲ��� �̵� 
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
