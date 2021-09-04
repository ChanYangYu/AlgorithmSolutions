#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
//#define DEBUG
using namespace std;

struct Piece{
	int y;
	int x;
	int d;
	int up;
	int down;
};

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int mp[13][13];
int top[13][13];
Piece p[11];
int n, k;

int get_inverse(int d){
	if(d == 0) return 1;
	else if(d == 1) return 0;
	else if(d == 2) return 3;
	else return 2;
}

void execute_white(int idx, int ny, int nx){
	int next_top = top[ny][nx];
	int cur_down = p[idx].down;
	
	// down �������� 
	p[cur_down].up = 0;
	
	// ���ο� top�� ���� 
	p[idx].down = next_top;
	p[next_top].up = idx;
	
	// ������ġ�� ���ο� top ���� 
	top[p[idx].y][p[idx].x] = cur_down;
	
	// ���� �� �̵� 
	int cur = idx;
	while(true){
		p[cur].y = ny;
		p[cur].x = nx;
		
		if(p[cur].up == 0){
			// �̵��ϴ� ��ġ�� ���ο� top ���� 
			top[ny][nx] = cur;
			break;
		}
		cur = p[cur].up;
	}
}

void execute_red(int idx, int ny, int nx){
	int cur_down = p[idx].down;
	int next_top = top[ny][nx];
	
	// down �������� 
	p[cur_down].up = 0;
	p[idx].down = 0;
	
	// ���� ��ġ top ���� 
	top[p[idx].y][p[idx].x] = cur_down;
	
	int cur = idx;
	while(true){
		p[cur].y = ny;
		p[cur].x = nx;
		
		// �Ųٷ� ���� 
		swap(p[cur].up, p[cur].down);
		
		if(p[cur].down == 0){
			// ���ο� top�� ���� 
			p[cur].down = next_top;
			p[next_top].up = cur;
			break;
		}
		cur = p[cur].down;
	}
	// ���� ��ġ top ���� 
	top[ny][nx] = idx; 
}

void execute_blue(int idx){
	int new_d = get_inverse(p[idx].d);
	int yy = p[idx].y + dy[new_d];
	int xx = p[idx].x + dx[new_d];
	
	// ���� ���� 
	p[idx].d = new_d;
	
	// �ٽ��ѹ� �Ķ� ������ ��� 
	if(yy < 1 || yy > n || xx < 1 || xx > n || mp[yy][xx] == 2)
		return;
	// �Ͼ� ����
	else if(mp[yy][xx] == 0)
		execute_white(idx, yy, xx);
	// ���� ����
	else
		execute_red(idx, yy, xx);
}

bool check_state(int idx){
	int cur = idx;
	int cnt = 0;
	
	while(true){
		cnt++;
		if(p[cur].down == 0)
			break;
		cur = p[cur].down;
	}
	
	return cnt >= 4; 
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	cin>>n>>k;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>mp[i][j];
	
	for(int i = 1; i <= k; i++){
		cin>>p[i].y>>p[i].x>>p[i].d;
		p[i].up = 0;
		p[i].down = 0;
		p[i].d--;
		top[p[i].y][p[i].x] = i; 
	}
	
	int turn = 1;
	bool check = false;
	
	while(turn <= 1000){
		for(int i = 1; i <= k; i++){
			//print_state();
			int d = p[i].d;
			int yy = p[i].y + dy[d];
			int xx = p[i].x + dx[d];			
			
			if(yy < 1 || yy > n || xx < 1 || xx > n || mp[yy][xx] == 2)
				execute_blue(i);
			else if(mp[yy][xx] == 0)
				execute_white(i, yy, xx);
			else
				execute_red(i, yy, xx);
			
			// ���� 4���� �׿��ִ� �� üũ 
			for(int j = 1; j <= k; j++){
				if(check_state(j)){
					check = true;
					break;
				}
			}
			if(check)
				break;
		}
		
		if(check)
			break;
		turn++;
	}
	
	turn = (turn > 1000) ? -1 : turn;
	cout<<turn;
    return 0;
}
