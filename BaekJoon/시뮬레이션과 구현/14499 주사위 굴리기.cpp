#include <bits/stdc++.h>
using namespace std;
//��, ��, ��, ��, ��, �� 
int mp[20][20];
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
vector<int> pos = {6, 3, 4, 2, 5, 1};
int num[7];

//�Լ� ����� ���� �κ� �Ű澵��!
//int�� �����ϰ� return�� ���°�� �޸��ʰ� �߻� 
void move(int d){
	//�������� �̵� 
	if(d == 1){
		pos = {pos[1], pos[5], pos[0], pos[3], pos[4], pos[2]};
//		int tmp1, tmp2;
//		tmp1 = pos[0];
//		pos[0] = pos[1];
//		tmp2 = pos[2];
//		pos[2] = tmp1;
//		tmp1 = pos[5];
//		pos[5] = tmp2;
//		pos[1] = tmp1;
	}
	//�������� �̵� 
	else if(d == 2){
		pos = {pos[2], pos[0], pos[5], pos[3], pos[4], pos[1]};
//		int tmp1, tmp2;
//		tmp1 = pos[5];
//		pos[5] = pos[1];
//		tmp2 = pos[2];
//		pos[2] = tmp1;
//		tmp1 = pos[0];
//		pos[0] = tmp2;
//		pos[1] = tmp1;
	}
	
	//�������� �̵� 
	else if(d == 3){
		pos = {pos[3], pos[1], pos[2], pos[5], pos[0], pos[4]};
//		int tmp1, tmp2;
//		tmp1 = pos[5];
//		pos[5] = pos[4];
//		tmp2 = pos[3];
//		pos[3] = tmp1;
//		tmp1 = pos[0];
//		pos[0] = tmp2;
//		pos[4] = tmp1;
	}
	
	//�������� �̵� 
	else{
		pos = {pos[4], pos[1], pos[2], pos[0], pos[5], pos[3]};
//		int tmp1, tmp2;
//		tmp1 = pos[0];
//		pos[0] = pos[4];
//		tmp2 = pos[3];
//		pos[3] = tmp1;
//		tmp1 = pos[5];
//		pos[5] = tmp2;
//		pos[4] = tmp1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int n, m;
	int y, x;
	int c;
	
	cin>>n>>m>>y>>x>>c;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>mp[i][j];
	
	for(int i = 0; i < c; i++){
		int d;
		
		cin>>d;
		
		int yy = y + dy[d-1];
		int xx = x + dx[d-1];
		
		if(yy < 0 || yy >= n || xx < 0 || xx >= m)
			continue;
		
		//�ش� ��ġ�� �̵� 
		y = yy;
		x = xx;
		
		//�ֻ��� �̵� 
		move(d);
		
		//�ش� ��ġ�� 0�ΰ�� 
		if(mp[y][x] == 0)
			mp[y][x] = num[pos[0]];
		
		//0�� �ƴѰ�� �ٴڿ� ���� 
		else{
			num[pos[0]] = mp[y][x];
			mp[y][x] = 0;
		}
		
		//���� ��� 
		cout<<num[pos[5]]<<"\n";
	}
	
	return 0;
}
