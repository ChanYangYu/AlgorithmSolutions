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
		
		//�ִܰŸ� ���� 
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
	
	//����� ������ �ʱ�ȭ
	for(int i = 0; i < m; i++){
		int y, x;
		
		cin>>y>>x;
		start.push_back({y,x});
		cin>>y>>x;
		dest.push_back({y,x});
	}
	
	//m�� ���� 
	for(int i = 0; i < m; i++){
		int person = -1;
		
		while(!to_person[ty][tx].empty())
			to_person[ty][tx].pop();
		for(int k = 0; k < m; k++){
			//�̹� ó���� �°��� continue 
			if(ch[k] == 1)
				continue; 
			//���� ��ġ���� �°����� �Ÿ� ��� 
			calc_start(ty, tx, k);
			
			//�ּ� �Ÿ��� ��� 
			if(!to_person[ty][tx].empty() &&
				to_person[ty][tx].top().y == start[k].first && to_person[ty][tx].top().x == start[k].second)
				person = k; 
		}
		
		//�մ����� �� �� ���� ��� 
		if(to_person[ty][tx].empty()){
			f = -1;
			break;
		}
		
		//�ý� ��ġ���� �մ���ġ���� �Ÿ� 
		int dis = to_person[ty][tx].top().d;
		
		//�°����� �̵� 
		f -= dis;
	 
		int sy = start[person].first;
		int sx = start[person].second;
		
		//�°��� �������� �̵� 
		dis = calc_dest(sy, sx, person);
		
		//�°��� �������� �̵��� �� ���� ��� 
		if(dis == -1){
			f = -1; 
			break;
		}
		
		f -= dis;
	
		//���ᰡ �߰��� �ٴڳ� ��� 
		if(f < 0){
			f = -1;
			break;
		}
		
		//�մ� ���� 
		ch[person] = 1;
		
		//�մ��� �¿�� �̵��ѷ��� �ι� ����
		f += 2*dis;
		

		//�ý� ���� �������� �̵�
		ty = dest[person].first;
		tx = dest[person].second;
		
	}
	
	cout<<f; 
	return 0;
}
