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
		
		//������ �������̵� 
		bool operator<(const Data &a) const{
			//�� ��� ���� �� 
			if(this->count == a.count){
				//������ ��� ���� �� 
				if(this->m == a.m){
					//�� �� 
					if(this->y == a.y){
						//�� �� 
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

//�ݽð� ���� ȸ�� 
void turn_left(int n){
	int tmp[21][21];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			tmp[i][j] = mp[j][n+1-i];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			mp[i][j] = tmp[i][j];
}

//�߷� �ۿ� 
void gravity(int n){
	for(int i = n-1; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			//������ �߷¹��� 
			if(mp[i][j] == -1 || mp[i][j] == -2)
				continue;
			int me = mp[i][j];
			int k;
			for(k = i; k <= n-1; k++){
				//��ĭ�� �ƴϸ� 
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
				//�湮üũ 
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
						
						//0�ΰ�� -4ó�� 
						if(tmp[yy][xx] == 0){
							m++;
							tmp[yy][xx] = -4;
							q.push({yy, xx});
						}
						//ó�� ���� ���� ��� 
						else if(tmp[yy][xx] == first){
							tmp[yy][xx] = -3;
							q.push({yy,xx});
						}
					}
				}
				
				//0���� 
				for(int k = 1; k <= n; k++)
					for(int l = 1; l <= n; l++)
						if(tmp[k][l] == -4)
							tmp[k][l] = 0;
				
				//2���̻��� ��� 
				if(cnt >= 2)
					pq.push(Data(cnt, m, i, j));
			}
		}
	}
	
	//��ġ�ϴ� ��ϱ׷� ���� ��� 
	if(pq.empty())
		return;
	int i = pq.top().y;
	int j = pq.top().x;
	int cnt = pq.top().count;
	 
	queue<pair<int, int> > q;
	int first = mp[i][j];
	
	q.push({i,j});
	//�湮üũ 
	mp[i][j] = -2;
	
	//mp���� ����
	while(!q.empty()){
		int y = q.front().first;
		int x  = q.front().second;
		
		q.pop();
		
		for(int k = 0; k < 4; k++){
			int yy = dy[k] + y;
			int xx = dx[k] + x;
			
			if(yy < 1 || yy > n || xx < 1 || xx > n)
				continue;
			
			//0�ΰ�� -4ó�� 
			if(mp[yy][xx] == 0){
				mp[yy][xx] = -2;
				q.push({yy, xx});
			}
			//ó�� ���� ���� ��� 
			else if(mp[yy][xx] == first){
				mp[yy][xx] = -2;
				q.push({yy,xx});
			}
		}
	}
	
	//���� �߰� 
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
		//�� �̻� ���� ������ ������ ���� 
		if(prev_score == score)
			break;
		gravity(n);
		turn_left(n);
		gravity(n);
	}
	
	cout<<score;
    return 0;
}
