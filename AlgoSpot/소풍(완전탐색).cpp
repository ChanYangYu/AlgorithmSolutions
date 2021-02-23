#include <bits/stdc++.h>
using namespace std;
int isFriend[10][10];
int isFinish[10];
int res;

void dfs(int n){
	int idx = -1;
	
	//가장 번호가 빠른 학생 탐색 
	for(int i = 0; i < n; i++){
		if(isFinish[i] == 0){
			idx = i;
			break;
		}
	}
	
	//모든 학생이 탐색되었으면 
	if(idx == -1){
		//전체 개수 ++ 
		res++;
		return;
	}
	 
	//선택된 학생의 다음번 학생부터 탐색시작 
	for(int i = idx+1; i < n; i++){
		//선택된 학생과 친구이고 아직 선발되지 않은 학생인경우 
		if(isFriend[idx][i] && !isFinish[i]){
			//선별 체크 
			isFinish[idx] = 1;
			isFinish[i] = 1;
			
			dfs(n);
			
			//선별 체크 해제 
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
		
		//finsh, friend 배열 초기화 
		for(int i = 0; i < n; i++){
			isFinish[i] = 0;
			for(int j = 0; j < n; j++)
				isFriend[i][j] = 0;
		}
		
		//인접행렬 입력 
		for(int i = 0; i < m; i++){
			int a, b;
			
			cin>>a>>b;
			
			isFriend[a][b] = 1;
			isFriend[b][a] = 1;
		}
		
		//전역변수 초기화 
		res = 0;
		dfs(n);
		//결과값 출력 
		cout<<res<<"\n";
	}
	
	return 0;
}
