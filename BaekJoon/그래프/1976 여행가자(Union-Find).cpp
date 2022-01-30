#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

//����Ŭ ���� 
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
	
	//����Ŭ �ʱ�ȭ 
	for(int i = 1; i <= n; i++)
		cycle[i] = i;
	
	//��� ����üũ 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin>>x;
			
			if(x == 1 && cycle[i] != cycle[j])
				unio(i,j);
		}
	}
	
	int prev;
	//������ �Է� 
	cin>>prev;
	
	for(int i = 1; i < m; i++){
		//��ǥ���� �Է� 
		int cur;
		cin>>cur;
		
		//���� ����Ŭ�� �ƴϸ� 
		if(cycle[prev] != cycle[cur]){
			cout<<"NO";
			return 0;
		}
		//��ǥ������ ���������� ���� 
		prev = cur;
	}
	cout<<"YES";
	return 0;
}
