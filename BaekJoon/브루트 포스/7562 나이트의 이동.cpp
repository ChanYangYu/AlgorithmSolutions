#include <bits/stdc++.h>
using namespace std;
int ch[300][300];
int dy[8] = {-1,-2,-2,-1, 1, 2, 1, 2};
int dx[8] = {-2,-1, 1, 2, 2, 1,-2,-1};

int main(void){
	ios_base::sync_with_stdio(false);
	int t;
	
	cin>>t;
	
	//test���̽� �ݺ� 
	for(int k = 0; k < t; k++){
		int size;
		cin>>size;
		
		//�湮���� �˻� �迭 �ʱ�ȭ 
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				ch[i][j] = 0;
		//���� ��ġ �Է� 
		int y,x,ty,tx;
		cin>>y>>x;
		//��ǥ ��ġ �Է� 
		cin>>ty>>tx;
		
		queue<pair<pair<int, int>,int > > q;
		
		//������ġ ť�� ���� 
		q.push({{y,x},0});
		
		//������ �湮ó�� 
		ch[y][x] = 0;
		while(!q.empty()){
			y = q.front().first.first;
			x = q.front().first.second;
			int c = q.front().second;
			
			q.pop();
			
			//��ǥ������ ���������� 
			if(y == ty && x == tx){
				//����� ����� ���� 
				cout<<c<<endl;
				break;
			}
			
			//���� Ž�� 
			for(int i = 0; i < 8; i++){
				int yy = dy[i] + y;
				int xx = dx[i] + x;
				
				//���� ���� 
				if(yy < 0 || yy >= size || xx < 0 || xx >= size)
					continue;
				//ó���湮�̸� ť�� ���� 
				if(ch[yy][xx] == 0){
					ch[yy][xx] = 1;
					q.push({{yy,xx},c+1});
				}
			}
		}
	}
	
    return 0;
}
