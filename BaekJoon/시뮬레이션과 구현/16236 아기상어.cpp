#include <bits/stdc++.h>
using namespace std;
int mp[20][20];
int ch[20][20];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main(void){
	ios_base::sync_with_stdio(false);
	queue<pair<pair<int, int>, int> > q;
	int sy,sx;
	int size = 2;
	int ate = 0;
	int fish = 0;
	int time = 0;
	int n;
	
	cin>>n;
	
	//�� �Է� 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>mp[i][j];
			
			//�����ġ�̸� 
			if(mp[i][j] == 9){
				sy = i;
				sx = j;
				//�����ġ 0���� �ʱ�ȭ 
				mp[i][j] = 0;
			}
			else if(mp[i][j] != 0)
				fish++;
		}
	}
	
	while(1){
		//����� ������ 0�̸� ���� 
		if(fish == 0)
			break;
		//ch�ʱ�ȭ 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				ch[i][j] = 0;
		
		q.push({{sy,sx},0});
		//�ּҰŸ� ����� ��ġ �� �̵��ð� 
		int fy = -1, fx = -1;
		int mcount = 987654321;
		while(!q.empty()){
			int y = q.front().first.first;
			int x = q.front().first.second;
			int c = q.front().second;
			
			q.pop();
			//���� ���� �������ġ�̰� �ּ� �Ÿ��ΰ�� 
			if(mp[y][x] > 0 && mp[y][x] < size && mcount >= c){
				//�ּҰŸ��� �ִ� ��� 
				if(mcount > c){
					fy = y;
					fx = x;
					mcount = c;	
				}
				//�Ÿ��� ���� �� ���� �ִ°�� 
				else if(fy >= y){
					if(fy > y){
						fy = y;
						fx = x;
					}
					//���� ���̿� �ְ� �� ���ʿ� �ִ°�� 
					else if(fx > x){
						fy = y;
						fx = x;
					}
				}
				continue;
			} 
			
			//�� ���� Ž��! 
			for(int i = 0; i < 4; i++){
				int yy = dy[i] + y;
				int xx = dx[i] + x;
				
				if(yy < 0 || yy >= n || xx < 0 || xx >= n)
					continue;
				
				//ó�� �湮�ϰ� ����� ������� ������ 
				if(ch[yy][xx] == 0 && mp[yy][xx] <= size){
					ch[yy][xx] = 1;
					q.push({{yy,xx},c+1});
				}
			}
		} 
		
		//��ã�� ��� 
		if(fx == -1 && fy == -1)
			break;
		else{
			//����� ���� 
			ate++;
			//�ð��߰� 
			time += mcount;
			//�������� ������� ������ 
			if(ate == size){
				//������� 
				size++;
				ate = 0;
			}
			//�ش���ġ ���� 
			mp[fy][fx] = 0;
			//����� ����-- 
			fish--;
			
			//�����ġ ���� 
			sy = fy;
			sx = fx;
		}
	}
	
	//��� ��� 
	cout<<time;
	

    return 0;
}
