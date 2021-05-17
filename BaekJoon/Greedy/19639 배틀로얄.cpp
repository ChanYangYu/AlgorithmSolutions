#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	priority_queue<pair<int, int> > potion;
	priority_queue<pair<int, int> > enemy;
	vector<int> res;
	int x, y, hp;
	int hp_warning;
	
	cin>>x>>y>>hp;
	
	//체력 경고수치 
	hp_warning = hp / 2;
	
	//적 정보 큐에 저장(가장 강한 적순으로 정렬) 
	for(int i = 0; i < x; i++){
		int e;
		
		cin>>e;
		enemy.push({e, i+1});
	}
	
	//물약정보 큐에 저장(가장 큰 물약순으로 정렬) 
	for(int i = 0; i < y; i++){
		int p;
		
		cin>>p;
		potion.push({p, i+1});
	}
	
	//가능한지 여부 체크 
	int possible = 1;
	
	//강한적부터 하나 하나 쓰려뜨린다 
	for(int i = 0; i < x; i++){
		
		//체력이 절반이하면 물약사용 
		while(hp <= hp_warning){
			if(potion.empty())
				break;
			//하나 사용 
			int p = potion.top().first;
			int idx = potion.top().second;
			potion.pop();
			
			res.push_back(idx);
			hp += p;
		}
		//적 한명과 전투 
		int e = enemy.top().first;
		int idx = -enemy.top().second;
		
		enemy.pop();
		
		hp -= e;
		res.push_back(idx);
		
		//hp가 0이하인 경우 
		if(hp <= 0){
			possible = 0;
			break;
		}
	}
	
	if(possible){
		//물약이 남았으면 전체 소비 
		while(!potion.empty()){
			int idx = potion.top().second;
			potion.pop();
			
			res.push_back(idx);
		}
		//결과 출력 
		for(int i = 0; i < res.size(); i++)
			cout<<res[i]<<"\n";
	}
	//불가능하면 0출력 
	else
		cout<<"0";
	return 0;
}
