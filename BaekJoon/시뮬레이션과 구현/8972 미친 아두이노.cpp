#include <bits/stdc++.h>
using namespace std;
int dy[9] = {1,1,1,0,0,0,-1,-1,-1};
int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
//반드시 시뮬레이션에서는 임시로 화면을 저장
//그 후 업데이트 하는 방법으로 구현 
char mp[101][101];
int main(void){
	ios_base::sync_with_stdio(false);
	queue<pair<int, int> > mad;
	int r, c;
	int y, x;
	string mv;
	
	cin>>r>>c;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			char t;
			cin>>t;
			if(t == 'I'){
				y = i;
				x = j;
				mp[i][j] = 1;
			}
			//미친 아두이노 위치 큐에 삽입 
			else if(t == 'R'){
				mp[i][j] = 2;
				mad.push(make_pair(i,j));
			}
		}
	}
	
	cin>>mv;
	
	int move = 0;
	int fail = false;
	for(int i = 0; i < mv.size(); i++){
		int tmp[101][101] = {0,};
		move++;
		int pos = mv[i] - 49;
		//종수 이동 
		y += dy[pos];
		x += dx[pos];
		
		//종수위치 표시 
		tmp[y][x] = 1;
		
		//큐사이즈 체크 
		int size = mad.size();
		for(int j = 0; j < size; j++){
			int mn = 987654321;
			int d = -1;
			int my = mad.front().first;
			int mx = mad.front().second;
			
			mad.pop();
			//미친 아두이노 이동방향 탐색 
			for(int k = 0; k < 9; k++){
				int yy = my + dy[k];
				int xx = mx + dx[k];
				
				if(yy >= r || yy < 0 || xx >=c || xx < 0)
					continue;
				int dis = abs(y-yy) + abs(x-xx);
				if(dis < mn){
					mn = dis;
					d = k;
				}
			}
			//해당 방향 이동
			my += dy[d];
			mx += dx[d];
			//미친 아두이노를 종수가 만났는지 확인 
			if(my == y && mx == x){
				fail = 1;
				break;
			} 
			tmp[my][mx] +=2;
			
			//해당자리에 혼자 있는 경우 다시 큐에 삽입 
			if(tmp[my][mx] == 2)
				mad.push(make_pair(my, mx));
		}
		
		//게임 종료 여부 확인 
		if(fail)
			break;
		
		//다시 큐에서 터진위치가 있는지 확인 
		size = mad.size();
		for(int j = 0; j < size; j++){
			int my = mad.front().first;
			int mx = mad.front().second;
			
			mad.pop();
			
			//해당 위치가 미친아두이노가 모인 자리인 경우 
			if(tmp[my][mx] > 2)
				tmp[my][mx] = 0;
			//혼자인 경우 다시 큐에 삽입 
			else
				mad.push(make_pair(my, mx));
		}
		//화면 업데이트 
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				mp[i][j] = tmp[i][j];
	}
	
	//게임에 진경우 
	if(fail)
		cout<<"kraj "<<move;
	else{
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(mp[i][j] == 2)
					cout<<"R";
				else if(mp[i][j] == 1)
					cout<<"I";
				else
					cout<<".";
			}
			cout<<endl;
		}
	}
    return 0;
}
