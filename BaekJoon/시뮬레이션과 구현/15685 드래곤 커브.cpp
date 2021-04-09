#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int mark[101][101];
vector<int> dragon;
int g;

//���� �������� ���� 
int turn(int d){
	switch(d){
		case 0 : return 1;
		case 1 : return 2;
		case 2 : return 3;
		case 3 : return 0;
	}
}

//�巡�� Ŀ�� ���� 
void make_dragon(int y, int x, int cur){
	if(g == cur)
		return;
	int start = dragon.size() - 1;
	for(int i = start; i >= 0; i--){
		int t = turn(dragon[i]);
		y = y + dy[t];
		x = x + dx[t];
		
		//�������� ��� 
		if(y >= 0 && y <=100 && x >= 0 && x <= 100)
			/*�����Ʈ : y, x�� �̹� ���� �� �� �ѹ� �����Ѱ��� �־���(�ڵ� ���� ������ üũx) 
			  �ڵ� ���� �� �ش� ������ ������ ������ �ٽ��ѹ� üũ�غ��� 
			*/
			mark[y][x] = 1;
		dragon.push_back(t);
	}
	make_dragon(y, x, cur+1);
}

int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	int n;
	
	cin>>n;
	
	//��� �巡�� Ŀ�� ��ǥ Ž�� 
	for(int i = 0; i < n; i++){
		int x, y, d;
		
		cin>>x>>y>>d>>g;
		
		mark[y][x] = 1;
		mark[y + dy[d]][x + dx[d]] = 1;
		
		dragon.clear();
		dragon.push_back(d);
		make_dragon(y + dy[d], x + dx[d], 0);
	
	}
	
	int cnt = 0;
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			if(i + 1 > 100 || j + 1 > 100)
				break;
			//ũ�Ⱑ 1�� �簢�� üũ 
			if(mark[i][j] == 1){
				if(mark[i+1][j] == 0)
					continue;
				if(mark[i][j+1] == 0)
					continue;
				if(mark[i+1][j+1] == 0)
					continue;
				cnt++;
			}
		}
	}
	
	cout<<cnt;
	return 0;
}
