#include <bits/stdc++.h>
using namespace std;

int mp[300][300];
int mp1[300][300];
int ch[300][300];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int main(void){
	ios_base::sync_with_stdio(false);
	int n,m, res = 0;
	cin>>n>>m;
	
	//���갪 �Է� 
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>mp[i][j]; 
	
	while(1){
		int check = 1;
		//��� ��Ҵ��� ���� 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mp[i][j] != 0){
					//üũ�� 0���� ���� 
					check = 0;
					break;
				}
			}
			if(check == 0)
				break;
		}
		
		//��� ������� �ݺ��� Ż�� 
		if(check){
			//����� 0���� �ʱ�ȭ 
			res = 0;
			break;
		}
		
		//�湮�迭 �ʱ�ȭ 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				ch[i][j] = 0;
		
		//���� ����׷� Ž��
		int group = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(ch[i][j] == 0 && mp[i][j] != 0){
					group++;
					ch[i][j] = group;
					
					queue<pair<int, int> > q;
					
					q.push(make_pair(i,j));
					while(!q.empty()){
						int y = q.front().first;
						int x = q.front().second;
						
						q.pop();
						
						//4���� ����
						for(int k = 0; k < 4; k++){
							int yy = y + dy[k];
							int xx = x + dx[k];
							
							//���� üũ 
							if(yy < 0 || xx < 0 || yy >= n || xx >= m)
								continue;
							//�ش� ���������� �����̸� 
							if(mp[yy][xx] != 0 && ch[yy][xx] == 0){
								ch[yy][xx] = group;
								q.push(make_pair(yy,xx));
							}
						}
					}
				}
			}
		}
		
		//�� ��� �̻��̸�
		if(group >= 2)
			break; 
		
		//���� 1���߰�  
		res++;
		//1��� ���� mp1�� ���� 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int cnt = 0;
				if(mp[i][j] == 0)
					mp1[i][j] = 0;
				else{
					for(int k = 0; k < 4; k++){
						int yy = i + dy[k];
						int xx = j + dx[k];
						
						if(yy < 0 || xx < 0 || yy >= n || xx >= m)
							continue;
						//�ش� ���������� �ٴ��̸� 
						if(mp[yy][xx] == 0)
							cnt++;
					}
					if(cnt > mp[i][j])
						mp1[i][j] = 0;
					else
						mp1[i][j] = mp[i][j]-cnt;
				}
			}
		}
		//mp ����
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				mp[i][j] = mp1[i][j];
	}
	cout<<res;	
    return 0;
}
