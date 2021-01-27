#include <bits/stdc++.h>
using namespace std;
//그룹 배열 
int mp[50][50];
//그룹 재탐색 check배열 
int mp1[50][50];
//성벽 정보 저장 배열 
int wall[50][50];
//그룹 재탐색 그룹체크배열 
int ch[2501];
//각 그룹의 크기 저장 벡터 
vector<int> group;

int main(void){
	ios_base::sync_with_stdio(false);
	int n,m;
	
	cin>>n>>m;
	
	//wall 초기화 
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			cin>>wall[i][j];
	
	//그룹의 개수 
	int gr_num = 0;
	//최대 크기의 그룹 
	int max_gr = 0;
	
	//그룹 정하기 
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(mp[i][j] == 0){
				gr_num++;
				int cnt_gr = 0;
				queue<pair<int, int> > q;
				
				q.push(make_pair(i,j));
				mp[i][j] = gr_num;
				
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					
					cnt_gr++;
					q.pop();
					
					int tmp = wall[y][x];
					//남쪽이 뚫려있으면 
					if(tmp < 8){
						if(y+1 < m && mp[y+1][x] == 0){
							mp[y+1][x] = gr_num;
							q.push(make_pair(y+1,x));
						}
					}
					else
						tmp -= 8;
					
					//동쪽이 뚫려있으면 
					if(tmp < 4){
						if(x+1 < n && mp[y][x+1] == 0){
							mp[y][x+1] = gr_num;
							q.push(make_pair(y,x+1));
						}
					}
					else
						tmp -= 4;
						
					//북쪽이 뚫려있으면 
					if(tmp < 2){
						if(y-1 >= 0 && mp[y-1][x] == 0){
							mp[y-1][x] = gr_num;
							q.push(make_pair(y-1,x));
						}
					}
					else
						tmp -= 2;
						
					//서쪽이 뚫려있으면 
					if(tmp < 1){
						if(x-1 >= 0 && mp[y][x-1] == 0){
							mp[y][x-1] = gr_num;
							q.push(make_pair(y,x-1));
						}
					}
					else
						tmp -= 1;	
				}
				
				//최대 크기 그룹 체크 
				if(max_gr < cnt_gr)
					max_gr = cnt_gr;
				//그룹 추가 
				group.push_back(cnt_gr);
			}
		}
	}
	//최대 넓이 방법 
	int best_choice = 0;
	
	//근접 그룹 탐색 
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(ch[mp[i][j]] == 0){
				ch[mp[i][j]] = 1;
				int my_grp = group[mp[i][j]-1];
				
				queue<pair<int, int> > q;
				q.push(make_pair(i,j));
				mp1[i][j] = 1;
				
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					
					q.pop();
					
					int tmp = wall[y][x];
					if(tmp < 8){
						if(y+1 < m && mp1[y+1][x] == 0){
							mp1[y+1][x] = 1;
							q.push(make_pair(y+1,x));
						}
					}
					else{
						//북쪽 벽을 뚫었을때 이웃값 계산
						if(y+1 < m && mp[y+1][x] != mp[i][j]){								
							int next_grp = group[mp[y+1][x]-1];
							if(best_choice < (my_grp + next_grp))
								best_choice = my_grp + next_grp;
						}
						tmp -= 8;
					}
					
					if(tmp < 4){
						if(x+1 < n && mp1[y][x+1] == 0){
							mp1[y][x+1] = 1;
							q.push(make_pair(y,x+1));
						}
					}
					else{
						//동쪽 벽을 뚫었을때 이웃값 계산
						if(x+1 < n && mp[y][x+1] != mp[i][j]){
							int next_grp = group[mp[y][x+1]-1];
							if(best_choice < (my_grp + next_grp))
								best_choice = my_grp + next_grp;
						}
						tmp -= 4;
					}
					
					if(tmp < 2){
						if(y-1 >= 0 && mp1[y-1][x] == 0){
							mp1[y-1][x] = 1;
							q.push(make_pair(y-1,x));
						}
					}
					else{
						//북쪽 벽을 뚫었을때 이웃값 계산
						if(y-1 >= 0 && mp[y-1][x] != mp[i][j]){
							int next_grp = group[mp[y-1][x]-1];
							if(best_choice < (my_grp + next_grp))
								best_choice = my_grp + next_grp;
						}
						tmp -= 2;
					}
						
					if(tmp < 1){
						if(x-1 >= 0 && mp1[y][x-1] == 0){
							mp1[y][x-1] = 1;
							q.push(make_pair(y,x-1));
						}
					}
					else{
						//서쪽 벽을 뚫었을때 이웃값 계산
						if(x-1 >= 0 && mp[y][x-1] != mp[i][j]){
							int next_grp = group[mp[y][x-1]-1];
							if(best_choice < (my_grp + next_grp))
								best_choice = my_grp + next_grp;
						}
						tmp -= 1;
					}
				}
			}
		}
	}
	//결과값 출력 
	cout<<gr_num<<endl<<max_gr<<endl<<best_choice;
	
    return 0;
}
