#include <bits/stdc++.h>
int mp[21][21];
int n;
int res;
using namespace std;

//��� or ���� 
void copy_map(int tmp[][21], int flag){
	//tmp�� ���� 
	if(flag){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				tmp[i][j] = mp[i][j];
	}
	//mp�� ���� 
	else{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				mp[i][j] = tmp[i][j];
	}
}

//�� �� �� �� �̵� 
void move(int flag){
	//�� 
	if(flag == 0){
		for(int j = 0; j < n; j++){
			int pos = 0;
			for(int i = 1; i < n; i++){
				//��ĭ�� �ƴϸ� 
				if(mp[i][j] != 0){
					//Ÿ�� ��ġ�� ��ĭ�̸�
					if(mp[pos][j] == 0){
						mp[pos][j] = mp[i][j];
						//�̵� 
						mp[i][j] = 0;
					}
					//���� ���ڰ� ������� 
					else if(mp[pos][j] == mp[i][j]){
						mp[pos][j] *= 2;
						//�̵�
						mp[i][j] = 0;
						//��ģ ��� ���� ��ĥ �� �����Ƿ� pos ��ĭ���� ���� 
						pos++;
					}
					else{
						//pos ����ĭ �̵� 
						pos++;
						mp[pos][j] = mp[i][j];
						if(pos != i)
							mp[i][j] = 0;
					}
				}
			}
		}
	}
	//�� 
	else if(flag == 1){
		for(int j = 0; j < n; j++){
			int pos = n-1;
			for(int i = n-2; i >= 0; i--){
				//��ĭ�� �ƴϸ� 
				if(mp[i][j] != 0){
					//Ÿ�� ��ġ�� ��ĭ�̸�
					if(mp[pos][j] == 0){
						mp[pos][j] = mp[i][j];
						//�̵� 
						mp[i][j] = 0;
					}
					//���� ���ڰ� ������� 
					else if(mp[pos][j] == mp[i][j]){
						mp[pos][j] *= 2;
						//�̵�
						mp[i][j] = 0;
						//��ģ ��� ���� ��ĥ �� �����Ƿ� pos ��ĭ���� ���� 
						pos--;
					}
					else{
						//pos ����ĭ �̵� 
						pos--;
						mp[pos][j] = mp[i][j];
						if(pos != i)
							mp[i][j] = 0;
					}
				}
			}
		}
	}
	//�� 
	else if(flag == 2){
		for(int i = 0; i < n; i++){
			int pos = 0;
			for(int j = 1; j < n; j++){
				//��ĭ�� �ƴϸ� 
				if(mp[i][j] != 0){
					//Ÿ�� ��ġ�� ��ĭ�̸�
					if(mp[i][pos] == 0){
						mp[i][pos] = mp[i][j];
						//�̵� 
						mp[i][j] = 0;
					}
					//���� ���ڰ� ������� 
					else if(mp[i][pos] == mp[i][j]){
						mp[i][pos] *= 2;
						//�̵�
						mp[i][j] = 0;
						//��ģ ��� ���� ��ĥ �� �����Ƿ� pos ��ĭ���� ���� 
						pos++;
					}
					else{
						//pos ����ĭ �̵� 
						pos++;
						mp[i][pos] = mp[i][j];
						if(pos != j)
							mp[i][j] = 0;
					}
				}
			}
		}
	}
	//�� 
	else{
		for(int i = 0; i < n; i++){
			int pos = n-1;
			for(int j = n-2; j >= 0; j--){
				//��ĭ�� �ƴϸ� 
				if(mp[i][j] != 0){
					//Ÿ�� ��ġ�� ��ĭ�̸�
					if(mp[i][pos] == 0){
						mp[i][pos] = mp[i][j];
						//�̵� 
						mp[i][j] = 0;
					}
					//���� ���ڰ� ������� 
					else if(mp[i][pos] == mp[i][j]){
						mp[i][pos] *= 2;
						//�̵�
						mp[i][j] = 0;
						//��ģ ��� ���� ��ĥ �� �����Ƿ� pos ��ĭ���� ���� 
						pos--;
					}
					else{
						//pos ����ĭ �̵� 
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
	//�������� 
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
	//mp ���
	copy_map(tmp, 1);
	
	//��,��,��,�� Ž�� 
	for(int i = 0; i < 4; i++){
		//�̵� 
		move(i);
		solve(cnt+1);
		//mp ����
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
