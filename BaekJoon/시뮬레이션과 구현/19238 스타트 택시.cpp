#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Data{
	public:
		int y;
		int x;
		int d;
		Data(int y, int x, int d){
			this->y = y;
			this->x = x;
			this->d = d;
		}
		bool operator< (const Data &a) const{
			if(a.d == this->d){
				if(a.y == this->y)
					return a.x < this->x;
				else
					return a.y < this->y;
			}
			else
				return a.d < this->d;
		}
};

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int ch[401];
int n, m, f;
int ty, tx;
int mp[21][21];
priority_queue<Data> to_person[21][21];
vector<pair<int, int> > start;
vector<pair<int, int> > dest;

void calc_start(int i, int j, int idx){
	int v[21][21];
	int start_y, start_x;
	queue<Data> q;
	memset(v, 0, sizeof(v));
	
	start_y = start[idx].first;
	start_x = start[idx].second;
	
	q.push(Data(i, j, 0));
	v[i][j] = 1;
	
	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		
		q.pop();
		
		if(y == start_y && x == start_x){
			to_person[i][j].push(Data(start_y, start_x, d));
			break;
		}
		for(int l = 0; l < 4; l++){
			int yy = y + dy[l];
			int xx = x + dx[l];
			
			if(yy < 1 || yy > n || xx < 1 || xx > n)
				continue;
			if(mp[yy][xx] == 1)
				continue;
			if(v[yy][xx] == 0){
				v[yy][xx] = 1;
				q.push(Data(yy, xx, d + 1));	
			}
		}
	}
}

int calc_dest(int i, int j, int idx){
	int v[21][21];
	int dest_y, dest_x;
	queue<Data> q;
	memset(v, 0, sizeof(v));
	
	dest_y = dest[idx].first;
	dest_x = dest[idx].second;
	
	q.push(Data(i, j, 0));
	v[i][j] = 1;
	
	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		
		q.pop();
		
		//최단거리 리턴 
		if(y == dest_y && x == dest_x)
			return d;
		for(int l = 0; l < 4; l++){
			int yy = y + dy[l];
			int xx = x + dx[l];
			
			if(yy < 1 || yy > n || xx < 1 || xx > n)
				continue;
			if(mp[yy][xx] == 1)
				continue;
			if(v[yy][xx] == 0){
				v[yy][xx] = 1;
				q.push(Data(yy, xx, d + 1));	
			}
		}
	}
	return -1;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>f;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>mp[i][j];
	
	cin>>ty>>tx;
	
	//출발지 도착지 초기화
	for(int i = 0; i < m; i++){
		int y, x;
		
		cin>>y>>x;
		start.push_back({y,x});
		cin>>y>>x;
		dest.push_back({y,x});
	}
	
	//m번 수행 
	for(int i = 0; i < m; i++){
		int person = -1;
		
		while(!to_person[ty][tx].empty())
			to_person[ty][tx].pop();
		for(int k = 0; k < m; k++){
			//이미 처리한 승객은 continue 
			if(ch[k] == 1)
				continue; 
			//현재 위치부터 승객까지 거리 계산 
			calc_start(ty, tx, k);
			
			//최소 거리인 경우 
			if(!to_person[ty][tx].empty() &&
				to_person[ty][tx].top().y == start[k].first && to_person[ty][tx].top().x == start[k].second)
				person = k; 
		}
		
		//손님한테 갈 수 없는 경우 
		if(to_person[ty][tx].empty()){
			f = -1;
			break;
		}
		
		//택시 위치에서 손님위치까지 거리 
		int dis = to_person[ty][tx].top().d;
		
		//승객에게 이동 
		f -= dis;
	 
		int sy = start[person].first;
		int sx = start[person].second;
		
		//승객의 목적지로 이동 
		dis = calc_dest(sy, sx, person);
		
		//승객의 목적지로 이동할 수 없는 경우 
		if(dis == -1){
			f = -1; 
			break;
		}
		
		f -= dis;
	
		//연료가 중간에 바닥난 경우 
		if(f < 0){
			f = -1;
			break;
		}
		
		//손님 제거 
		ch[person] = 1;
		
		//손님을 태우고 이동한량의 두배 충전
		f += 2*dis;
		

		//택시 최종 목적지로 이동
		ty = dest[person].first;
		tx = dest[person].second;
		
	}
	
	cout<<f; 
	return 0;
}
