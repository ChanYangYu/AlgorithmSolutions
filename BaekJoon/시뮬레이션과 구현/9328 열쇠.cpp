#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
char mp[101][101];
int v[101][101];
int has_key[26];
int res;
int h, w;
//알파벳키에 대응되는 문의 위치 
queue<pair<int, int> > doors[26];
//출입구 
vector<pair<int, int> > entrance;

void init(){
	cin>>h>>w;
	
	//출입구 초기화 
	entrance.clear();
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin>>mp[i][j];
			v[i][j] = 0;
			
			//가장 자리인 경우 
			if(i == 0 || j == 0 || i == h-1 || j == w-1){
				//출입구에 추가 
				if(mp[i][j] != '*')
					entrance.push_back({i,j});
			}
		}
	}
	
	res = 0;
	//현재 키상태, 문 위치 초기화
	for(int i = 0; i < 26; i++){
		has_key[i] = 0;
		while(!doors[i].empty())
			doors[i].pop();
	}
	
	string keys;
	cin>>keys;
	
	//갖고 있는키가 있으면 
	if(keys != "0")
		for(int i = 0; i < keys.size(); i++)
			has_key[keys[i] - 'a'] = 1;
}

//현재 위치 print (test용) 
void print_pos(int y, int x){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(i == y && j == x)
				cout<<"#";
			else
				cout<<mp[i][j];
		}
		cout<<"\n";
	}
	cout<<"\n";
	sleep(1);
	system("cls");
}

void solve(int y, int x){
	//방문 체크 
	v[y][x] = 1;
	
	//print_pos(y,x);
	//상,하,좌,우 탐색 
	for(int i = 0; i < 4; i++){
		int yy = y + dy[i];
		int xx = x + dx[i];
		
		//범위 이탈 
		if(yy < 0 || yy >= h || xx < 0 || xx >= w)
			continue;
		//벽이거나 이미 방문한 경우 
		if(mp[yy][xx] == '*' || v[yy][xx])
			continue;
		//빈 공간인 경우 
		if(mp[yy][xx] == '.')
			solve(yy, xx);
		//문서인 경우 
		else if(mp[yy][xx] == '$'){
			res++;
			solve(yy,xx);
		}
		//문 인경우 
		else if(mp[yy][xx] >= 'A' && mp[yy][xx] <= 'Z'){
			int door = mp[yy][xx] - 'A';
			if(has_key[door])
				solve(yy, xx);
			else
				doors[door].push({yy,xx});
		}
		//키인 경우 
		else{
			int key = mp[yy][xx] - 'a';
			has_key[key] = 1;
			
			//현재 찾은 키에 대응하는 문의 위치부터 탐색 
			while(!doors[key].empty()){
				int door_y = doors[key].front().first;
				int door_x = doors[key].front().second;
				
				doors[key].pop();
				if(v[door_y][door_x] == 0)
					solve(door_y, door_x);
			}
			//키 위치로 이동 
			solve(yy,xx);
		}
		
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	for(int i = 0; i < t; i++){
		init();
		
		for(int j = 0; j < entrance.size(); j++){
			int y = entrance[j].first;
			int x = entrance[j].second;
			
			//이미 방문한경우 
			if(v[y][x])
				continue;
			//문인 경우 
			if(mp[y][x] >= 'A' && mp[y][x] <= 'Z'){
				int door = mp[y][x] - 'A';
				//키가 있는경우 
				if(has_key[door])
					solve(y,x);
				//키 없는  경우 
				else
					doors[door].push({y,x});
			}
			else{
				if(mp[y][x] == '$')
					res++;
				solve(y,x);
			}
		}
		
		cout<<res<<"\n";
	}
	return 0;
}
