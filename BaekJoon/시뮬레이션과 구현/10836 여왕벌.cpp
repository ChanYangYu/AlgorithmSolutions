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
	
	//n번의 성장(┌방향 채우기)
	for(int i = 0; i < n; i++){
		int zero, one, two;
		cin>>zero>>one>>two;
		
		int start = zero;
		
		//1이상 성장한 경우 처리 
		for(int j = 0; j < one; j++)
			edge[start+j]++;
		
		start = zero + one;
		
		//2이상 성장한 경우 처리 
		for(int j = 0; j < two; j++)
			edge[start+j] += 2;
	}
	
	//아래에서 위로 방향 맵에 저장 
	for(int i = 0; i < m; i++)
		mp[m-1-i][0] = edge[i];
	
	//최상단에서 오른쪽 방향 맵에 저장 
	for(int i = m; i < 2*m-1; i++)
		mp[0][i-m+1] = edge[i];
	
	//최상단의 값 그대로 밑에 저장 
	for(int i = 1; i < m; i++)
		for(int j = 1; j < m; j++)
			mp[i][j] = mp[i-1][j];
	
	//결과값 출력 
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
