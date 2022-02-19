#include <bits/stdc++.h>
using namespace std;
int mp[700][700];
int edge[1400];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int m, n;
	
	fill(edge,edge + 1400,1);
	
	cin>>m>>n;
	
	//n���� ����(������ ä���)
	for(int i = 0; i < n; i++){
		int zero, one, two;
		cin>>zero>>one>>two;
		
		int start = zero;
		
		//1�̻� ������ ��� ó�� 
		for(int j = 0; j < one; j++)
			edge[start+j]++;
		
		start = zero + one;
		
		//2�̻� ������ ��� ó�� 
		for(int j = 0; j < two; j++)
			edge[start+j] += 2;
	}
	
	//�Ʒ����� ���� ���� �ʿ� ���� 
	for(int i = 0; i < m; i++)
		mp[m-1-i][0] = edge[i];
	
	//�ֻ�ܿ��� ������ ���� �ʿ� ���� 
	for(int i = m; i < 2*m-1; i++)
		mp[0][i-m+1] = edge[i];
	
	//�ֻ���� �� �״�� �ؿ� ���� 
	for(int i = 1; i < m; i++)
		for(int j = 1; j < m; j++)
			mp[i][j] = mp[i-1][j];
	
	//����� ��� 
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
