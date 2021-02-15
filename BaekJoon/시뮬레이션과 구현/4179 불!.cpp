#include <bits/stdc++.h>
using namespace std;
char mp[1001][1001];
int ch[1001][1001];
int fch[1001][1001];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int r, c;
	queue<pair<int, int> > fire;
	queue<pair<int, int> > jihoon;
	
	cin>>r>>c;
	
	//�Է� 
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin>>mp[i][j];
			if(mp[i][j] == 'J'){
				jihoon.push({i,j});
				ch[i][j] = 1;
			}
			else if(mp[i][j] == 'F'){
				fire.push(make_pair(i,j));
				fch[i][j] = 1;
			}
		}
	}
	
	int res = 0;
	while(1){
		res++;
		
		//�����̺��� �̵� 
		int size = jihoon.size();
		if(size == 0){
			cout<<"IMPOSSIBLE";
			return 0;
		}
		
		for(int i = 0; i < size; i++){
			int y = jihoon.front().first;
			int x = jihoon.front().second;
			
			jihoon.pop();
			
			//�̹� ��ź�ڸ��̸� 
			if(mp[y][x] == 'F')
				continue;
			for(int j = 0; j < 4; j++){
				int yy = dy[j] + y;
				int xx = dx[j] + x;
			
				//���� ���� 
				if(yy < 0 || yy >= r || xx < 0 || xx >=c){
					cout<<res;
					return 0;
				}
				if(ch[yy][xx] == 0 && mp[yy][xx] != '#' && mp[yy][xx] != 'F'){
					ch[yy][xx] = 1;
					jihoon.push(make_pair(yy,xx));
				}
			}
		}
		
		//�� �̵� 
		size = fire.size();
		for(int i = 0; i < size; i++){
			int fy = fire.front().first;
			int fx = fire.front().second;
			
			fire.pop();
			for(int j = 0; j < 4; j++){
				int yy = dy[j] + fy;
				int xx = dx[j] + fx;
			
				//���� ���� 
				if(yy < 0 || yy >= r || xx < 0 || xx >=c)
					continue;
				if(fch[yy][xx] == 0 && mp[yy][xx] != '#'){
					mp[yy][xx] = 'F';
					fch[yy][xx] = 1;
					fire.push(make_pair(yy,xx));
				}
			}
		}
	}
	return 0;
}
