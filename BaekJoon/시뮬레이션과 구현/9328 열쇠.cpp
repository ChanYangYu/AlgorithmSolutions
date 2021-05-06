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
//���ĺ�Ű�� �����Ǵ� ���� ��ġ 
queue<pair<int, int> > doors[26];
//���Ա� 
vector<pair<int, int> > entrance;

void init(){
	cin>>h>>w;
	
	//���Ա� �ʱ�ȭ 
	entrance.clear();
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin>>mp[i][j];
			v[i][j] = 0;
			
			//���� �ڸ��� ��� 
			if(i == 0 || j == 0 || i == h-1 || j == w-1){
				//���Ա��� �߰� 
				if(mp[i][j] != '*')
					entrance.push_back({i,j});
			}
		}
	}
	
	res = 0;
	//���� Ű����, �� ��ġ �ʱ�ȭ
	for(int i = 0; i < 26; i++){
		has_key[i] = 0;
		while(!doors[i].empty())
			doors[i].pop();
	}
	
	string keys;
	cin>>keys;
	
	//���� �ִ�Ű�� ������ 
	if(keys != "0")
		for(int i = 0; i < keys.size(); i++)
			has_key[keys[i] - 'a'] = 1;
}

//���� ��ġ print (test��) 
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
	//�湮 üũ 
	v[y][x] = 1;
	
	//print_pos(y,x);
	//��,��,��,�� Ž�� 
	for(int i = 0; i < 4; i++){
		int yy = y + dy[i];
		int xx = x + dx[i];
		
		//���� ��Ż 
		if(yy < 0 || yy >= h || xx < 0 || xx >= w)
			continue;
		//���̰ų� �̹� �湮�� ��� 
		if(mp[yy][xx] == '*' || v[yy][xx])
			continue;
		//�� ������ ��� 
		if(mp[yy][xx] == '.')
			solve(yy, xx);
		//������ ��� 
		else if(mp[yy][xx] == '$'){
			res++;
			solve(yy,xx);
		}
		//�� �ΰ�� 
		else if(mp[yy][xx] >= 'A' && mp[yy][xx] <= 'Z'){
			int door = mp[yy][xx] - 'A';
			if(has_key[door])
				solve(yy, xx);
			else
				doors[door].push({yy,xx});
		}
		//Ű�� ��� 
		else{
			int key = mp[yy][xx] - 'a';
			has_key[key] = 1;
			
			//���� ã�� Ű�� �����ϴ� ���� ��ġ���� Ž�� 
			while(!doors[key].empty()){
				int door_y = doors[key].front().first;
				int door_x = doors[key].front().second;
				
				doors[key].pop();
				if(v[door_y][door_x] == 0)
					solve(door_y, door_x);
			}
			//Ű ��ġ�� �̵� 
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
			
			//�̹� �湮�Ѱ�� 
			if(v[y][x])
				continue;
			//���� ��� 
			if(mp[y][x] >= 'A' && mp[y][x] <= 'Z'){
				int door = mp[y][x] - 'A';
				//Ű�� �ִ°�� 
				if(has_key[door])
					solve(y,x);
				//Ű ����  ��� 
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
