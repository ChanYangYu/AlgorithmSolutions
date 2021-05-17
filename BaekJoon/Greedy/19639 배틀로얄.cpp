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
	
	//ü�� ����ġ 
	hp_warning = hp / 2;
	
	//�� ���� ť�� ����(���� ���� �������� ����) 
	for(int i = 0; i < x; i++){
		int e;
		
		cin>>e;
		enemy.push({e, i+1});
	}
	
	//�������� ť�� ����(���� ū ��������� ����) 
	for(int i = 0; i < y; i++){
		int p;
		
		cin>>p;
		potion.push({p, i+1});
	}
	
	//�������� ���� üũ 
	int possible = 1;
	
	//���������� �ϳ� �ϳ� �����߸��� 
	for(int i = 0; i < x; i++){
		
		//ü���� �������ϸ� ������ 
		while(hp <= hp_warning){
			if(potion.empty())
				break;
			//�ϳ� ��� 
			int p = potion.top().first;
			int idx = potion.top().second;
			potion.pop();
			
			res.push_back(idx);
			hp += p;
		}
		//�� �Ѹ�� ���� 
		int e = enemy.top().first;
		int idx = -enemy.top().second;
		
		enemy.pop();
		
		hp -= e;
		res.push_back(idx);
		
		//hp�� 0������ ��� 
		if(hp <= 0){
			possible = 0;
			break;
		}
	}
	
	if(possible){
		//������ �������� ��ü �Һ� 
		while(!potion.empty()){
			int idx = potion.top().second;
			potion.pop();
			
			res.push_back(idx);
		}
		//��� ��� 
		for(int i = 0; i < res.size(); i++)
			cout<<res[i]<<"\n";
	}
	//�Ұ����ϸ� 0��� 
	else
		cout<<"0";
	return 0;
}
