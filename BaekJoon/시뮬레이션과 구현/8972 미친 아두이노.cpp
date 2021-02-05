#include <bits/stdc++.h>
using namespace std;
int dy[9] = {1,1,1,0,0,0,-1,-1,-1};
int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
//�ݵ�� �ùķ��̼ǿ����� �ӽ÷� ȭ���� ����
//�� �� ������Ʈ �ϴ� ������� ���� 
char mp[101][101];
int main(void){
	ios_base::sync_with_stdio(false);
	queue<pair<int, int> > mad;
	int r, c;
	int y, x;
	string mv;
	
	cin>>r>>c;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			char t;
			cin>>t;
			if(t == 'I'){
				y = i;
				x = j;
				mp[i][j] = 1;
			}
			//��ģ �Ƶ��̳� ��ġ ť�� ���� 
			else if(t == 'R'){
				mp[i][j] = 2;
				mad.push(make_pair(i,j));
			}
		}
	}
	
	cin>>mv;
	
	int move = 0;
	int fail = false;
	for(int i = 0; i < mv.size(); i++){
		int tmp[101][101] = {0,};
		move++;
		int pos = mv[i] - 49;
		//���� �̵� 
		y += dy[pos];
		x += dx[pos];
		
		//������ġ ǥ�� 
		tmp[y][x] = 1;
		
		//ť������ üũ 
		int size = mad.size();
		for(int j = 0; j < size; j++){
			int mn = 987654321;
			int d = -1;
			int my = mad.front().first;
			int mx = mad.front().second;
			
			mad.pop();
			//��ģ �Ƶ��̳� �̵����� Ž�� 
			for(int k = 0; k < 9; k++){
				int yy = my + dy[k];
				int xx = mx + dx[k];
				
				if(yy >= r || yy < 0 || xx >=c || xx < 0)
					continue;
				int dis = abs(y-yy) + abs(x-xx);
				if(dis < mn){
					mn = dis;
					d = k;
				}
			}
			//�ش� ���� �̵�
			my += dy[d];
			mx += dx[d];
			//��ģ �Ƶ��̳븦 ������ �������� Ȯ�� 
			if(my == y && mx == x){
				fail = 1;
				break;
			} 
			tmp[my][mx] +=2;
			
			//�ش��ڸ��� ȥ�� �ִ� ��� �ٽ� ť�� ���� 
			if(tmp[my][mx] == 2)
				mad.push(make_pair(my, mx));
		}
		
		//���� ���� ���� Ȯ�� 
		if(fail)
			break;
		
		//�ٽ� ť���� ������ġ�� �ִ��� Ȯ�� 
		size = mad.size();
		for(int j = 0; j < size; j++){
			int my = mad.front().first;
			int mx = mad.front().second;
			
			mad.pop();
			
			//�ش� ��ġ�� ��ģ�Ƶ��̳밡 ���� �ڸ��� ��� 
			if(tmp[my][mx] > 2)
				tmp[my][mx] = 0;
			//ȥ���� ��� �ٽ� ť�� ���� 
			else
				mad.push(make_pair(my, mx));
		}
		//ȭ�� ������Ʈ 
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				mp[i][j] = tmp[i][j];
	}
	
	//���ӿ� ����� 
	if(fail)
		cout<<"kraj "<<move;
	else{
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(mp[i][j] == 2)
					cout<<"R";
				else if(mp[i][j] == 1)
					cout<<"I";
				else
					cout<<".";
			}
			cout<<endl;
		}
	}
    return 0;
}
