#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

//사이클 저장 
int cycle[201];

int find(int x){
	if(cycle[x] == x)
		return x;
	else{
		cycle[x] = find(cycle[x]);
		return cycle[x];
	}
}

void unio(int i, int j){
	int pi = find(i);
	int pj = find(j);
	
	if(pi < pj){
		cycle[pj] = pi;
		find(j);
	}
	else{
		cycle[pi] = pj;
		find(i);
	}
	
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n, m;
	
	cin>>n>>m;
	
	//사이클 초기화 
	for(int i = 1; i <= n; i++)
		cycle[i] = i;
	
	//모든 간선체크 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin>>x;
			
			if(x == 1 && cycle[i] != cycle[j])
				unio(i,j);
		}
	}
	
	int prev;
	//시작점 입력 
	cin>>prev;
	
	for(int i = 1; i < m; i++){
		//목표지점 입력 
		int cur;
		cin>>cur;
		
		//같은 사이클이 아니면 
		if(cycle[prev] != cycle[cur]){
			cout<<"NO";
			return 0;
		}
		//목표지점을 시작점으로 변경 
		prev = cur;
	}
	cout<<"YES";
	return 0;
}
