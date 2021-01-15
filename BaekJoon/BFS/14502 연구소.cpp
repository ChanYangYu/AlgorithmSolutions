#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int mp[8][8];
int n,m;
int ch[64];
vector<pair<int,int> > v; //���̷��� ��ġ
vector<pair<int,int> > e; //�� ���� ��ġ 
int res; //�ִ� ���� 

void dfs(int s, int prev){
	ios_base::sync_with_stdio(false);
	//������ �Ǿ����� 
	if(s == 3){
		queue<pair<int,int> > q;
		int ecount = e.size();
		int vcount = v.size();
		int cnt = 0; 
		//���̷��� ��ġ BFSŽ�� 
		for(int i = 0; i < vcount; i++){
			q.push(make_pair(v[i].first, v[i].second));
			while(!q.empty()){
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for(int j = 0; j < 4; j++){
					if(dy[j]+y >= n || dy[j]+y < 0 || dx[j]+x >= m || dx[j]+x < 0)
						continue;
					if(mp[dy[j]+y][dx[j]+x] == 0){
						q.push(make_pair(dy[j]+y, dx[j]+x));
						mp[dy[j]+y][dx[j]+x] = 2;
						cnt++;
					}	
				}
			}
			//�ִ񰪺��� ������(���� ����-3) 
			if(res >= ecount - cnt-3)
				break;
		}
		//�ִ� ��(���� ����-3) 
		if(res < ecount - cnt-3)
			res = ecount - cnt-3;
		//�� �ʱ�ȭ 
		for(int i = 0; i < ecount; i++)
			if(ch[i]!= 1)
				mp[e[i].first][e[i].second] = 0;
	}
	else{
		//�� ������ 3�� ���� 
		for(int i = prev; i < e.size(); i++){
			mp[e[i].first][e[i].second] = 1;
			ch[i] = 1;
			dfs(s+1, i+1);
			ch[i] = 0;
			mp[e[i].first][e[i].second] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>mp[i][j];
			if(mp[i][j] == 2)
				v.push_back(make_pair(i,j));
			else if(mp[i][j] == 0)
				e.push_back(make_pair(i,j));
		}
	}
	dfs(0,0); 
	cout<<res;
	return 0;
}
