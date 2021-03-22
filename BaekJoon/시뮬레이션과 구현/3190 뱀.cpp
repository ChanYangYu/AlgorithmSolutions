#include <bits/stdc++.h>
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int mp[101][101];

struct pos{
	int y;
	int x;
	struct pos* next;
};

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	
	int n, k, l;
	vector<pair<int, char> > turn;
	
	cin>>n>>k;
	
	for(int i = 0; i < k; i++){
		int y, x;
		cin>>y>>x;
		
		mp[y][x] = 2;
	}
	
	cin>>l;
	for(int i = 0; i < l; i++){
		int t;
		char d;
		
		cin>>t>>d;
		turn.push_back({t,d});
	}
	
	int direc = 0;
	int time = 0;
	int idx = 0;
	
	struct pos *head;
	struct pos *tail;
	
	head = (struct pos *)malloc(sizeof(struct pos));
	
	head->x = 1;
	head->y = 1;
	head->next = NULL;
	
	//tail에 새로운 노드를 만들고 그 next에 head를 붙이는 실수!
	//tail이 pointer이므로 만들어진 노드를 가리키면 된다. 
	tail = head;
	
	mp[1][1] = 1;
	
	while(1){
		//머리 이동
		struct pos *new_head;
		new_head = (struct pos *)malloc(sizeof(struct pos));
		new_head->y = head->y + dy[direc];
		new_head->x = head->x + dx[direc];
		new_head->next = NULL;
		
		time++;
		
		//벽에 부딪쳤으면 
		if(new_head->x < 1 || new_head->x > n || new_head->y < 1 || new_head->y > n)
			break;
		
		//자기몸과 부딪쳤으면 
		if(mp[new_head->y][new_head->x] == 1)
			break; 
		
		//머리 연결 
		head->next = new_head;
		head = new_head;
		
		//사과가 없으면
		if(mp[new_head->y][new_head->x] != 2){
			struct pos *tmp;
			tmp = tail;
			//지도에서 꼬리 제거
			mp[tail->y][tail->x] = 0;
			tail = tail->next;
			free(tmp);
		}
		
		//머리 지도에 그림 
		mp[new_head->y][new_head->x] = 1;
		
		//방향 전환 
		if(idx < turn.size() && time == turn[idx].first){
			char d = turn[idx].second;
			idx++;
			
			if(d == 'D')
				direc++;
			else
				direc--;
			
			if(direc < 0)
				direc = 3;
			
			if(direc > 3)
				direc = 0;
		}
	}

	cout<<time; 
	return 0;
}
