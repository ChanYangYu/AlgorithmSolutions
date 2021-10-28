#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int hor[4] = {4,1,3,6};
int ver[4] = {2,1,5,6};
int mp[21][21];
int score[21][21];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int turn_right(int d){ return (d+1) % 4; }

int turn_left(int d){ return d == 0 ? 3 : d-1; }

// 북, 동, 남, 서 
void move(int d){
	if(d == 0){
		int tmp = ver[3];
		ver[3] = ver[0];
		ver[0] = ver[1];
		ver[1] = ver[2];
		ver[2] = tmp;
		
		hor[1] = ver[1];
		hor[3] = ver[3];
	}
	else if(d == 1){	
		int tmp = hor[0];
		hor[0] = hor[3];
		hor[3] = hor[2];
		hor[2] = hor[1];
		hor[1] = tmp;
		
		ver[1] = hor[1];
		ver[3] = hor[3];
	}
	else if(d == 2){
		int tmp = ver[0];
		ver[0] = ver[3];
		ver[3] = ver[2];
		ver[2] = ver[1];
		ver[1] = tmp;
		
		hor[1] = ver[1];
		hor[3] = ver[3];
	}
	else{	
		int tmp = hor[3];
		hor[3] = hor[0];
		hor[0] = hor[1];
		hor[1] = hor[2];
		hor[2] = tmp;
		
		ver[1] = hor[1];
		ver[3] = hor[3];
	}
}

void calc_score(int n, int m){
	int ch[21][21];
	
	memset(ch, 0, sizeof(ch));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ch[i][j] == 0){
				int cnt = 1;
				int color = mp[i][j];
				queue<pii> q;
				vector<pii> v;
				
				ch[i][j] = 1;
				v.push_back({i,j});
				q.push({i,j});
				
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					
					q.pop();
					for(int k = 0; k < 4; k++){
						int yy = y + dy[k];
						int xx = x + dx[k];
						
						if(yy < 1 || yy > n || xx < 1 || xx > m)
							continue;
						if(ch[yy][xx] == 1 || mp[yy][xx] != color)
							continue;
						ch[yy][xx] = 1;
						cnt++;
						v.push_back({yy,xx});
						q.push({yy,xx});
					}
				}
				for(int l = 0; l < v.size(); l++){

					int y = v[l].first;
					int x = v[l].second;
					
					score[y][x] = cnt;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	
	cin>>n>>m>>k;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin>>mp[i][j];
	
	calc_score(n, m);
	
	int d = 1;
	int y = 1;
	int x = 1;
	int res = 0;
	 
	for(int i = 0; i < k; i++){
		int yy = y + dy[d];
		int xx = x + dx[d];
		
		// 이동방향 반대 
		if(yy < 1 || yy > n || xx < 1 || xx > m){
			d = (d+2) % 4;
			yy = y + dy[d];
			xx = x + dx[d];
		}
		
		res += score[yy][xx] * mp[yy][xx];
		move(d);
		
		if(hor[3] > mp[yy][xx])
			d = turn_right(d);
		else if(hor[3] < mp[yy][xx])
			d = turn_left(d);
		y = yy;
		x = xx;
	}
	
	cout<<res;
    return 0;
}
