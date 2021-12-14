#include <bits/stdc++.h>
#define pii pair<int,int> 

using namespace std;

/*

 1. 각 노드의 정보와 부모노드의 정보를 전역으로 저장
 2. 양이 있는 노드는 따로 sheeps에 인덱스 저장
 3. 양이 있는 노드를 반복문으로 돌면서 1번 노드로 탐색(solve)
  - 늑대가 있는 노드인 경우 양을 먹은 늑대수만큼 제거해주면서 올라감 
  - 타고올라가면서 parent노드를 갱신(이후에 양이 있는 다른노드에서 같은길로 중복해서 올라올 수 있으므로)
 
 ! 틀린 부분
  1. "늑대 한 마리는 최대 한 마리의 양만 잡아먹습니다." 의 의미를 간과하였다.
  2. node[idx].second = 0을 해주지 않아 원하는 제대로 늑대수가 제거되지 않았다.
   
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
