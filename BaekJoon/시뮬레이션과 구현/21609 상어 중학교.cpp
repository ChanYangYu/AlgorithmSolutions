#include <bits/stdc++.h>
using namespace std;
class Data{
	public:
		int count;
		int m;
		int y;
		int x;
		
		Data(int c, int m, int y, int x){
			this->count = c;
			this->m = m;
			this->y = y;
			this->x = x;
		}
		
		//연산자 오버라이딩 
		bool operator<(const Data &a) const{
			//총 블록 개수 비교 
			if(this->count == a.count){
				//무지개 블록 개수 비교 
				if(this->m == a.m){
					//행 비교 
					if(this->y == a.y){
						//열 비교 
						return this->x < a.x;
					}
					else
						return this->y < a.y;
				}
				else
					return this->m < a.m;
			}
			else
				return this->count < a.count;
		}
};

int mp[21][21];
int score;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

//반시계 방향 회전 
void turn_left(int n){
	int tmp[21][21];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			tmp[i][j] = mp[j][n+1-i];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			mp[i][j] = tmp[i][j];
}

//중력 작용 
void gravity(int n){
	for(int i = n-1; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			//검은돌 중력무시 
			if(mp[i][j] == -1 || mp[i][j] == -2)
				continue;
			int me = mp[i][j];
			int k;
			for(k = i; k <= n-1; k++){
				//빈칸이 아니면 
				if(mp[k+1][j] != -2)
					break; 
			}
			mp[i][j] = -2;
			mp[k][j] = me;
		}
	}
}

void get_score(int n){
	int tmp[21][21];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			tmp[i][j] = mp[i][j];
	
	priority_queue<Data> pq;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(tmp[i][j] > 0){
				queue<pair<int, int> > q;
				int first = tmp[i][j];
				int cnt = 0;
				int m = 0;
				
				q.push({i,j});
				//방문체크 
				tmp[i][j] = -3;
				
				while(!q.empty()){
					int y = q.front().first;
					int x  = q.front().second;
					
					cnt++;
					q.pop();
					
					for(int k = 0; k < 4; k++){
						int yy = dy[k] + y;
						int xx = dx[k] + x;
						
						if(yy < 1 || yy > n || xx < 1 || xx > n)
							continue;
						
						//0인경우 -4처리 
						if(tmp[yy][xx] == 0){
							m++;
							tmp[yy][xx] = -4;
							q.push({yy, xx});
						}
						//처음 수와 같은 경우 
						else if(tmp[yy][xx] == first){
							tmp[yy][xx] = -3;
							q.push({yy,xx});
						}
					}
				}
				
				//0복구 
				for(int k = 1; k <= n; k++)
					for(int l = 1; l <= n; l++)
						if(tmp[k][l] == -4)
							tmp[k][l] = 0;
				
				//2개이상인 경우 
				if(cnt >= 2)
					pq.push(Data(cnt, m, i, j));
			}
		}
	}
	
	//일치하는 블록그룹 없는 경우 
	if(pq.empty())
		return;
	int i = pq.top().y;
	int j = pq.top().x;
	int cnt = pq.top().count;
	 
	queue<pair<int, int> > q;
	int first = mp[i][j];
	
	q.push({i,j});
	//방문체크 
	mp[i][j] = -2;
	
	//mp에서 제거
	while(!q.empty()){
		int y = q.front().first;
		int x  = q.front().second;
		
		q.pop();
		
		for(int k = 0; k < 4; k++){
			int yy = dy[k] + y;
			int xx = dx[k] + x;
			
			if(yy < 1 || yy > n || xx < 1 || xx > n)
				continue;
			
			//0인경우 -4처리 
			if(mp[yy][xx] == 0){
				mp[yy][xx] = -2;
				q.push({yy, xx});
			}
			//처음 수와 같은 경우 
			else if(mp[yy][xx] == first){
				mp[yy][xx] = -2;
				q.push({yy,xx});
			}
		}
	}
	
	//점수 추가 
	score += (cnt * cnt);
}
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>mp[i][j];
	
	while(1){
		int prev_score = score;
		get_score(n);
		//더 이상 얻을 점수가 없으면 종료 
		if(prev_score == score)
			break;
		gravity(n);
		turn_left(n);
		gravity(n);
	}
	
	cout<<score;
    return 0;
}
