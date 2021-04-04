#include <bits/stdc++.h>
using namespace std;
int mp[31][11][2];
int n, m, h;
vector<pair<int, int> > possible;

//�� üũ �Լ� 
bool check(){
	for(int k = 1; k <= n; k++){
		int i = 1;
		int j = k;
		while(i <= h){
			if(mp[i][j][0] == 1){
				j--;
				i++;
			}
			else if(mp[i][j][1] == 1){
				j++;
				i++;
			}
			else
				i++;
		}
		if(k != j)
			return false;
	}
	return true;
}

bool solve(int choice, int cnt, int start){
	//������� 
	if(choice == cnt){
		if(check())
			return true;
		else
			return false;
	}
	else{
		//���� �� ���� 
		for(int s = start;  s < possible.size(); s++){
			int i = possible[s].first;
			int j = possible[s].second;
			
			//��ġ�� �ʴ� ���� ��� 
			if(mp[i][j][0] == 0 && mp[i][j][1] == 0 && mp[i][j+1][1] == 0){
				mp[i][j][1] = 1;
				mp[i][j+1][0] = 1;
				
				//���� ã������ ���� 
				if(solve(choice, cnt+1, s+1))
					return true;
				mp[i][j][1] = 0;
				mp[i][j+1][0] = 0;
			}
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	
	cin>>n>>m>>h;
	
	//mp�� ǥ�� 
	for(int i = 0; i < m; i++){
		int a, b;
		
		cin>>a>>b;
		
		mp[a][b][1] = 1;
		if(b+1 <= n)
			mp[a][b+1][0] = 1;
	}
	
	//������ ��ġ Ž�� 
	for(int i = 1; i <= h; i++){
		for(int j = 1; j < n; j++){
			if(mp[i][j][0] == 0 && mp[i][j][1] == 0 && mp[i][j+1][1] == 0)
				possible.push_back({i, j});
		}
	}
	
	//0 ~ 3�� �߰������� ���� �ִ��� üũ 
	for(int i = 0; i <= 3; i++){
		if(solve(i, 0, 0)){
			cout<<i;
			return 0;
		}
	}
	
	//������ -1��� 
	cout<<"-1";
	return 0;
}
