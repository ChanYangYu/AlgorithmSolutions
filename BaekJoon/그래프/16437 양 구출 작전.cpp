#include <bits/stdc++.h>
#define pii pair<int,int> 

using namespace std;

/*

 1. �� ����� ������ �θ����� ������ �������� ����
 2. ���� �ִ� ���� ���� sheeps�� �ε��� ����
 3. ���� �ִ� ��带 �ݺ������� ���鼭 1�� ���� Ž��(solve)
  - ���밡 �ִ� ����� ��� ���� ���� �������ŭ �������ָ鼭 �ö� 
  - Ÿ��ö󰡸鼭 parent��带 ����(���Ŀ� ���� �ִ� �ٸ���忡�� ������� �ߺ��ؼ� �ö�� �� �����Ƿ�)
 
 ! Ʋ�� �κ�
  1. "���� �� ������ �ִ� �� ������ �縸 ��ƸԽ��ϴ�." �� �ǹ̸� �����Ͽ���.
  2. node[idx].second = 0�� ������ �ʾ� ���ϴ� ����� ������� ���ŵ��� �ʾҴ�.
   
*/
pair<char, int> node[123457]; 
int parent[123457];
vector<int> sheeps;
long long res;

int solve(int idx, int sheep_cnt){
	if(idx == 1){
		res += sheep_cnt;
		return 1;
	}
	
	if(node[idx].first == 'W'){
		if(sheep_cnt - node[idx].second <= 0){
			node[idx].second -= sheep_cnt;
			return idx; 
		}
		else{
			int new_sheep_cnt = sheep_cnt - node[idx].second;
			node[idx].second = 0;
			return parent[idx] = solve(parent[idx], new_sheep_cnt);
		}
	}
	else
		return parent[idx] = solve(parent[idx], sheep_cnt); 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  cin>>n;
  
  for(int i = 2; i <= n; i++){
  	char t;
  	int a, p;
  	
  	cin>>t>>a>>p;
  	
  	node[i] = {t, a};
  	parent[i] = p;
  	
  	if(t == 'S')
  		sheeps.push_back(i);
  }
  
  for(int i = 0; i < sheeps.size(); i++){
  	int idx = sheeps[i];
  	
  	solve(idx, node[idx].second);
  }
  
  cout<<res;
}
