#include <bits/stdc++.h>
using namespace std;

//������ ĭ ���� 
vector<pair<int, int> > problem;  
int mp[9][9];

//�ڽ��� ���� �ε������� �����ִ� �Լ� 
int choose_box(int x){
	if(x < 3)
		return 0;
	else if(x < 6)
		return 3;
	else
		return 6;
}

// �����ذ� 
int solve(int idx){
	
	//��� ���� �ذ��� ��� 
	if(idx == problem.size())
		return 1;
	else{
		int ch[10] = {0,};
		int y = problem[idx].first;
		int x = problem[idx].second;
		
		//���� ���� üũ 
		for(int i = 0; i < 9; i++){
			if(ch[mp[y][i]] == 0)
				ch[mp[y][i]] = 1;
			if(ch[mp[i][x]] == 0)
				ch[mp[i][x]] = 1;
		}
		int yy = choose_box(y);
		int xx = choose_box(x);
		
		//�ڽ� üũ 
		for(int i = yy; i < yy+3; i++)
			for(int j = xx; j < xx+3; j++)
				if(ch[mp[i][j]] == 0)
					ch[mp[i][j]] = 1;
		
		//9���� �� �� ������ ���ڸ� ã�Ƽ� Ž�� 
		for(int i = 1; i <= 9; i++){
			if(ch[i] == 0){
				mp[y][x] = i;
				//������ Ǯ������ 1�� �����ؼ� ���� 
				if(solve(idx+1))
					return 1;
				mp[y][x] = 0;
			}
		}
		return 0;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	
	//�Է� 
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin>>mp[i][j];
			if(mp[i][j] == 0)
				problem.push_back(make_pair(i,j));
		}
	}
	
	solve(0);
	
	//��� 
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;
	}
	
    return 0;
}
