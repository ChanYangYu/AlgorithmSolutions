#include <bits/stdc++.h>
#define ll long long
using namespace std;
int team[100001];
int prefer[100001];
queue<int> q;

int make_team(int p){
	int next = prefer[p];
	
	//다음 사람이 팀이 없는 경우 => 이전 사람들도 모두 팀이 없다. 
	if(team[next] == -1)
		team[p] = -1;
	//다음사람이 아직 유망한 경우 => 다음사람 팀이 정해질 수 있다. 
	else if(team[next] == 0){
		q.push(p);
		
		//임시로 자기 자신을 팀으로 체크(방문체크) 
		team[p] = p; 
		team[p] = make_team(next);
		
		//시작점에 돌아온 경우(이전 사람들은 팀이 없음) 
		if(team[p] == p)
			return -1;
	}
	//다음 사람이 팀이 있는 경우 => 지금까지 큐에 저장된 사람들 중 시작점이 있는지 체크 
	else{ 
		while(!q.empty()){
			int t = q.front();
			
			//큐에 있는 사람들 중 시작점이면	
			if(t == next){
				//시작점으로 팀 만들기 
				team[p] = t;
				//시작점 리턴 
				return t;
			}
			q.pop();
		}
		team[p] = -1;
	}
	
	return team[p];
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int test;
	
	cin>>test;
	
	while(test--){
		int n;
		
		cin>>n;
		 
		for(int i = 1; i <= n; i++){
			cin>>prefer[i];
			
			if(prefer[i] == i)
				team[i] = i;
			else
				team[i] = 0;
		}
		
		for(int i = 1; i <= n; i++){
			if(team[i] != 0)
				continue;
			
			//큐 정리
			while(!q.empty())
				q.pop();
			make_team(i);
		}
		
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(team[i] == -1)
				cnt++;
			//cout<<team[i]<<" ";
		}
		
		cout<<cnt<<"\n";
		
	}
	
	
	return 0;
}
