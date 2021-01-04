#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n, l, r, cnt = 0;
	
	cin>>n>>l>>r;
	
	vector<vector<int> > m(n, vector<int>(n));
	vector<vector<int> > ch(n, vector<int>(n));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin>>m[i][j];
	}
	while(1){
		int team = 1;
		vector<int> res;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				ch[i][j] = 0;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(ch[i][j] == 0 &&
				(i+1 < n && ch[i+1][j] == 0 && abs(m[i][j] - m[i+1][j]) >= l && abs(m[i][j] - m[i+1][j]) <= r) ||
				(j+1 < n && ch[i][j+1] == 0 && abs(m[i][j]- m[i][j+1]) >= l && abs(m[i][j] - m[i][j+1]) <= r)){
					queue<pair<int,int> > q;
					ch[i][j] = team;
					q.push(make_pair(i, j));
					int sum = 0;
					int num = 0;
					while(!q.empty()){
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						sum += m[x][y];
						num++;
						if(x+1 < n && ch[x+1][y] == 0 && abs(m[x][y] - m[x+1][y]) >= l && abs(m[x][y] - m[x+1][y]) <= r){
							ch[x+1][y] = team;
							q.push(make_pair(x+1,y));
						}
						if(x-1 >= 0 && ch[x-1][y] == 0 && abs(m[x][y] - m[x-1][y]) >= l && abs(m[x][y] - m[x-1][y]) <= r){
							ch[x-1][y] = team;
							q.push(make_pair(x-1,y));
						}
						if(y+1 < n && ch[x][y+1] == 0 && abs(m[x][y] - m[x][y+1]) >= l && abs(m[x][y] - m[x][y+1]) <= r){
							ch[x][y+1] = team;
							q.push(make_pair(x,y+1));
						}
						if(y-1 >= 0 && ch[x][y-1] == 0 && abs(m[x][y] - m[x][y-1]) >= l && abs(m[x][y] - m[x][y-1]) <= r){
							ch[x][y-1] = team;
							q.push(make_pair(x,y-1));
						}
					}
					res.push_back(sum/num);
					team++;
				}
			}	
		}
		if(team == 1)
			break;
		else{
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(ch[i][j] != 0)
						m[i][j] = res[ch[i][j]-1];
				}
			}
			cnt++;
		}
	}
	cout<<cnt;
}
