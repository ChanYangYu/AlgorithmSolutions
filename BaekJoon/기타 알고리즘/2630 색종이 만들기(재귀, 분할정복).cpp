#include <bits/stdc++.h>
using namespace std;
int white, blue;
int n;
int mp[129][129];

void solve(int y, int x, int size)
{
	bool check = true;
	
	int start = mp[y][x];
	//���� �����̰� �ѻ����� ĥ�����ִ��� üũ 
	for(int i = y; i < y+size; i++){
		for(int j = x; j < x+size; j++){
			if(start != mp[i][j]){
				check = false;
				break;
			}
		}
		if(check == false)
			break;
	}
	
	//��� �ѻ����� ĥ���� ��� 
	if(check){
		if(start == 1)
			blue++;
		else
			white++;
		return;
	}
	else{
		//���� �����̸� 4���ҷ� ������ Ž�� 
		int n_size = size / 2;
		solve(y, x, n_size);
		solve(y, x + n_size, n_size);
		solve(y + n_size, x, n_size);
		solve(y + n_size, x + n_size, n_size);
	}
}

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>mp[i][j];
	
	solve(0,0,n);
	
	cout<<white<<"\n"<<blue;
    return 0;
}
