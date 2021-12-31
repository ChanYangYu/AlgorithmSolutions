#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;


int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
char mp[1501][1501];
int remove_time[1501][1501];
bool check[1501][1501];

vector<pii> baekjo;
class Data{
	public:
		int d;
		int y;
		int x;
		
		Data(int d, int y, int x){
			this->d = d;
			this->y = y;
			this->x = x;
		}
		
		bool operator<(const Data &a) const{
			return this->d > a.d;
		}
};

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int r, c;
	priority_queue<Data> pq;
	
	cin>>r>>c;
	
	memset(remove_time, -1, sizeof(remove_time));
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin>>mp[i][j];
			
			if(mp[i][j] == '.'){
				remove_time[i][j] = 0;
				pq.push(Data(0, i, j));
			}
			else if(mp[i][j] == 'L'){
				remove_time[i][j] = 0;
				pq.push(Data(0, i, j));
				baekjo.push_back({i, j});
			}
		}
	}
	
	while(!pq.empty()){
		int d = pq.top().d;
		int y = pq.top().y;
		int x = pq.top().x;
		
		pq.pop();
		
		for(int i = 0; i < 4; i++){
			int yy = y + dy[i];
			int xx = x + dx[i];
			
			if(yy < 0 || yy > r || xx < 0 || xx > c){
				continue;
			}
			if(remove_time[yy][xx] != -1){
				continue;
			}
			
			remove_time[yy][xx] = d+1;
			pq.push(Data(d+1, yy, xx));
		}
	}
	
	int sy = baekjo[0].first;
	int sx = baekjo[0].second;
	
	int ey = baekjo[1].first;
	int ex = baekjo[1].second;
	
	pq.push(Data(0, sy, sx));
	check[sy][sx] = true;
	
	while(!pq.empty()){
		int d = pq.top().d;
		int y = pq.top().y;
		int x = pq.top().x;
		
		
		pq.pop();
		if(y == ey && x == ex){
			cout<<d;
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int yy = y + dy[i];
			int xx = x + dx[i];
			
			if(yy < 0 || yy > r || xx < 0 || xx > c){
				continue;
			}
			
			if(check[yy][xx]){
				continue;
			}
			
			int max_d = max(d, remove_time[yy][xx]);
			
			check[yy][xx] = true;
			pq.push(Data(max_d, yy, xx));
		}
	}
		
	return 0;
}
