#include<bits/stdc++.h>
using namespace std;

class Shark{
	public:
		bool live;
		int y;
		int x;
		int s;
		int d;
		int z;
		
		Shark(int y, int x, int s, int d, int z){
			this->y = y;
			this->x = x;
			this->s = s;
			this->d = d;
			this->z = z;
			this->live = true;
		}
};

int r,c,m;
int mp[101][101];
vector<Shark> sharks;

void move(int idx){
	//위, 아래
	int y = sharks[idx].y;
	int x = sharks[idx].x;
	int s = sharks[idx].s;
	int d = sharks[idx].d;
	int z = sharks[idx].z;
	 
	if(d <= 2){
		int next;
		if(d == 1)
			next = -1;
		else
			next = 1;
		 
		int cycle = 2 * (r - 1);
		int ns = s % cycle;
		for(int i = 1; i <= ns; i++){
			if(y + next < 1 || y + next > r)
				next = -next;
			y += next;
		}
		
		//바뀐 방향 저장 
		if(next == -1)
			sharks[idx].d = 1;
		
		else
			sharks[idx].d = 2;
	}
	else{
		int next;
		if(d == 3)
			next = 1;
		else
			next = -1;
		
		int cycle = 2 * (c - 1);
		int ns = s % cycle;
		for(int i = 1; i <= ns; i++){
			if(x + next < 1 || x + next > c)
				next = -next;
			x += next;
		}
		
		//방향저장 
		if(next == -1)
			sharks[idx].d = 4;
		
		else
			sharks[idx].d = 3;
	}
	
	//이미 상어가 있는 경우 
	if(mp[y][x] != -1){
		int shark2 = mp[y][x];
		
		//기존의 있는 상어가 더 크면 
		if(sharks[shark2].z > z)
		{
			//현재 상어 죽음 
			sharks[idx].live = false;
			m--;
		}
		else{
			//기존 상어 죽음 
			sharks[shark2].live = false;
			m--;
			//상어위치 업데이트 
			sharks[idx].y = y;
			sharks[idx].x = x;
			//지도에 표기 
			mp[y][x] = idx;
		}
	}
	//상어가 없는 경우 
	else{
		//상어위치 업데이트 
		sharks[idx].y = y;
		sharks[idx].x = x;
		//지도에 표기 
		mp[y][x] = idx;
	}
}
int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt", stdin);
    
    cin>>r>>c>>m;
    
    //상어 위치 초기화 
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			mp[i][j] = -1;
    
    //입력 
    for(int i = 0; i < m; i++){
    	int y, x, s, d, z;
    	
    	cin>>y>>x>>s>>d>>z;
    	
    	sharks.push_back(Shark(y,x,s,d,z));
    	mp[y][x] = i;
	}
	
	//낚시왕 위치 
	int cur = 0;
	int score = 0;
	
	while(cur < c && m > 0){
		//낚시왕 이동 
		cur++;
		//상어잡이 
		for(int i = 1; i <= r; i++){
			if(mp[i][cur] != -1){
				int idx = mp[i][cur];
				
				sharks[idx].live = false;
				m--;
				score += sharks[idx].z;
				
				break;
			}
		}
		
		//상어 이전 위치 제거 
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				mp[i][j] = -1;
		
		//상어 이동 
		for(int i = 0; i < sharks.size(); i++)
			if(sharks[i].live)
				move(i);
		
	}
	
	cout<<score; 
	return 0;
}
