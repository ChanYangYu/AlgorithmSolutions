#include <bits/stdc++.h>
using namespace std;
int isFriend[10][10];
int isFinish[10];
int res;

void dfs(int n){
	int idx = -1;
	
	//���� ��ȣ�� ���� �л� Ž�� 
	for(int i = 0; i < n; i++){
		if(isFinish[i] == 0){
			idx = i;
			break;
		}
	}
	
	//��� �л��� Ž���Ǿ����� 
	if(idx == -1){
		//��ü ���� ++ 
		res++;
		return;
	}
	 
	//���õ� �л��� ������ �л����� Ž������ 
	for(int i = idx+1; i < n; i++){
		//���õ� �л��� ģ���̰� ���� ���ߵ��� ���� �л��ΰ�� 
		if(isFriend[idx][i] && !isFinish[i]){
			//���� üũ 
			isFinish[idx] = 1;
			isFinish[i] = 1;
			
			dfs(n);
			
			//���� üũ ���� 
			isFinish[idx] = 0;
			isFinish[i] = 0;
		}
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int t;
	
	cin>>t;
	for(int k = 0; k < t; k++){
		int n, m;
		
		cin>>n>>m;
		
		//finsh, friend �迭 �ʱ�ȭ 
		for(int i = 0; i < n; i++){
			isFinish[i] = 0;
			for(int j = 0; j < n; j++)
				isFriend[i][j] = 0;
		}
		
		//������� �Է� 
		for(int i = 0; i < m; i++){
			int a, b;
			
			cin>>a>>b;
			
			isFriend[a][b] = 1;
			isFriend[b][a] = 1;
		}
		
		//�������� �ʱ�ȭ 
		res = 0;
		dfs(n);
		//����� ��� 
		cout<<res<<"\n";
	}
	
	return 0;
}
