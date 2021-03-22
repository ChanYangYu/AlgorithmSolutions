#include <bits/stdc++.h>
int mp[21][21];
int n;
int res;
using namespace std;

//백업 or 복구 
void copy_map(int tmp[][21], int flag){
	//tmp에 복사 
	if(flag){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				tmp[i][j] = mp[i][j];
	}
	//mp에 복사 
	else{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				mp[i][j] = tmp[i][j];
	}
}

//상 하 좌 우 이동 
void move(int flag){
	//상 
	if(flag == 0){
		for(int j = 0; j < n; j++){
			int pos = 0;
			for(int i = 1; i < n; i++){
				//빈칸이 아니면 
				if(mp[i][j] != 0){
					//타켓 위치가 빈칸이면
					if(mp[pos][j] == 0){
						mp[pos][j] = mp[i][j];
						//이동 
						mp[i][j] = 0;
					}
					//같은 숫자가 만난경우 
					else if(mp[pos][j] == mp[i][j]){
						mp[pos][j] *= 2;
						//이동
						mp[i][j] = 0;
						//합친 경우 이제 합칠 수 없으므로 pos 한칸위로 변경 
						pos++;
					}
					else{
						//pos 다음칸 이동 
						pos++;
						mp[pos][j] = mp[i][j];
						if(pos != i)
							mp[i][j] = 0;
					}
				}
			}
		}
	}
	//하 
	else if(flag == 1){
		for(int j = 0; j < n; j++){
			int pos = n-1;
			for(int i = n-2; i >= 0; i--){
				//빈칸이 아니면 
				if(mp[i][j] != 0){
					//타켓 위치가 빈칸이면
					if(mp[pos][j] == 0){
						mp[pos][j] = mp[i][j];
						//이동 
						mp[i][j] = 0;
					}
					//같은 숫자가 만난경우 
					else if(mp[pos][j] == mp[i][j]){
						mp[pos][j] *= 2;
						//이동
						mp[i][j] = 0;
						//합친 경우 이제 합칠 수 없으므로 pos 한칸위로 변경 
						pos--;
					}
					else{
						//pos 다음칸 이동 
						pos--;
						mp[pos][j] = mp[i][j];
						if(pos != i)
							mp[i][j] = 0;
					}
				}
			}
		}
	}
	//좌 
	else if(flag == 2){
		for(int i = 0; i < n; i++){
			int pos = 0;
			for(int j = 1; j < n; j++){
				//빈칸이 아니면 
				if(mp[i][j] != 0){
					//타켓 위치가 빈칸이면
					if(mp[i][pos] == 0){
						mp[i][pos] = mp[i][j];
						//이동 
						mp[i][j] = 0;
					}
					//같은 숫자가 만난경우 
					else if(mp[i][pos] == mp[i][j]){
						mp[i][pos] *= 2;
						//이동
						mp[i][j] = 0;
						//합친 경우 이제 합칠 수 없으므로 pos 한칸위로 변경 
						pos++;
					}
					else{
						//pos 다음칸 이동 
						pos++;
						mp[i][pos] = mp[i][j];
						if(pos != j)
							mp[i][j] = 0;
					}
				}
			}
		}
	}
	//좌 
	else{
		for(int i = 0; i < n; i++){
			int pos = n-1;
			for(int j = n-2; j >= 0; j--){
				//빈칸이 아니면 
				if(mp[i][j] != 0){
					//타켓 위치가 빈칸이면
					if(mp[i][pos] == 0){
						mp[i][pos] = mp[i][j];
						//이동 
						mp[i][j] = 0;
					}
					//같은 숫자가 만난경우 
					else if(mp[i][pos] == mp[i][j]){
						mp[i][pos] *= 2;
						//이동
						mp[i][j] = 0;
						//합친 경우 이제 합칠 수 없으므로 pos 한칸위로 변경 
						pos--;
					}
					else{
						//pos 다음칸 이동 
						pos--;
						mp[i][pos] = mp[i][j];
						if(pos != j)
							mp[i][j] = 0;
					}
				}
			}
		}
	}
}

//solve
void solve(int cnt){
	//종료조건 
	if(cnt == 5){
		int mx = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(mx < mp[i][j])
					mx = mp[i][j];
			}
		}
		if(mx > res)
			res = mx;
		return;
	}
	
	int tmp[21][21];
	//mp 백업
	copy_map(tmp, 1);
	
	//상,하,좌,우 탐색 
	for(int i = 0; i < 4; i++){
		//이동 
		move(i);
		solve(cnt+1);
		//mp 복구
		copy_map(tmp, 0);
	}
} 

//main 
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>mp[i][j];
	
	solve(0);
	cout<<res;
	
	return 0;
}
