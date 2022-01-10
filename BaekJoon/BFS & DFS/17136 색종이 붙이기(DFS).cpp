#include <bits/stdc++.h>
using namespace std;
int mp[10][10];
int cnt[6];
int res = 987654321;
vector<pair<int, int> > v;

int check_paper(int y, int x, int size){
	for(int i = y; i < y+size; i++)
		for(int j = x; j < x+size; j++)
			if(i >= 10 || j >= 10 || mp[i][j] == 0)
				return 0;
	return 1;
}

void cover_paper(int y, int x, int size, int what){
	for(int i = y; i < y+size; i++)
		for(int j = x; j < x+size; j++)
			mp[i][j] = what;
}

void dfs(int idx, int r){
	if(idx == v.size()){
		if(res > r)
			res = r;
		return;
	}
	
	//유망하지 않은 조건 제거 
	if(res < r)
		return;
	
	int i = v[idx].first;
	int j = v[idx].second;
	
	//이미 덮여진 경우 
	if(mp[i][j] == 0){
		dfs(idx+1, r);
		return;	
	}
	
	//5개 모두 색종이 데보기
	for(int k = 5; k >= 1; k--){
		if(cnt[k] > 0 && check_paper(i,j,k)){
			cnt[k]--;
			//색종이 붙이기 
			cover_paper(i,j,k,0);
			dfs(idx+1,r+1);
			//색종이 복구 
			cover_paper(i,j,k,1);
			cnt[k]++; 
		}
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			cin>>mp[i][j];
			if(mp[i][j] == 1)
				v.push_back(make_pair(i,j));
		}
	}
	for(int i = 1; i <= 5; i++)
		cnt[i] = 5;
	
	dfs(0,0);
	
	if(res == 987654321)
		cout<<"-1";
	else
		cout<<res;
	return 0;
}
