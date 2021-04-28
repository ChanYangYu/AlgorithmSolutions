#include <bits/stdc++.h>
using namespace std;
class Data{
	public:
		int friends;
		int empty;
		int y;
		int x;
		
		Data(int f, int e, int y, int x){
			this->friends = f;
			this->empty = e;
			this->y = y;
			this->x = x;
		}
		
		//연산자 오버라이딩 
		bool operator<(const Data &a) const{
			if(this->friends == a.friends){
				if(this->empty == a.empty){
					if(this->y == a.y){
						return this->x > a.x;
					}
					else
						return this->y > a.y;
				}
				else
					return this->empty < a.empty;
			}
			else
				return this->friends < a.friends;
		}
};

int mp[21][21];
int prefer[401][401];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n;
	
	cin>>n;
	
	//자리 배치 
	for(int k = 1; k <= n*n; k++){
		int me;
		cin>>me;
		
		for(int j = 0; j < 4; j++){
			int x;
			
			cin>>x;
			prefer[me][x] = 1;
		}
		
		priority_queue<Data> pq;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int e = 0;
				int f = 0;
				
				//이미 앉은 자리인 경우 
				if(mp[i][j] != 0)
					continue;
				for(int l = 0; l < 4; l++){
					int yy = i + dy[l];
					int xx = j + dx[l];
					
					if(yy < 1 || yy > n || xx < 1 || xx > n)
						continue;
	
					int person = mp[yy][xx];
					if(person == 0)
						e++;
					else if(prefer[me][person])
						f++;
				}
				pq.push(Data(f, e, i, j));
			}
		}
		int y = pq.top().y;
		int x = pq.top().x;
		
		mp[y][x] = me;
	}
	
	//값 계산 
	int score[5] = {0,1,10,100,1000};
	int res = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int f = 0;
			for(int k = 0; k < 4; k++){
				int yy = i + dy[k];
				int xx = j + dx[k];
				
				if(yy < 1 || yy > n || xx < 1 || xx > n)
					continue;
				
				int me = mp[i][j];
				int person = mp[yy][xx];
				
				if(prefer[me][person])
					f++;
			}
			res += score[f];
		}
	}
	
	cout<<res;
    return 0;
}
