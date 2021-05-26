#include <bits/stdc++.h>
#define ll long long
using namespace std;
int team[100001];
int prefer[100001];
queue<int> q;

int make_team(int p){
	int next = prefer[p];
	
	//���� ����� ���� ���� ��� => ���� ����鵵 ��� ���� ����. 
	if(team[next] == -1)
		team[p] = -1;
	//��������� ���� ������ ��� => ������� ���� ������ �� �ִ�. 
	else if(team[next] == 0){
		q.push(p);
		
		//�ӽ÷� �ڱ� �ڽ��� ������ üũ(�湮üũ) 
		team[p] = p; 
		team[p] = make_team(next);
		
		//�������� ���ƿ� ���(���� ������� ���� ����) 
		if(team[p] == p)
			return -1;
	}
	//���� ����� ���� �ִ� ��� => ���ݱ��� ť�� ����� ����� �� �������� �ִ��� üũ 
	else{ 
		while(!q.empty()){
			int t = q.front();
			
			//ť�� �ִ� ����� �� �������̸�	
			if(t == next){
				//���������� �� ����� 
				team[p] = t;
				//������ ���� 
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
			
			//ť ����
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
