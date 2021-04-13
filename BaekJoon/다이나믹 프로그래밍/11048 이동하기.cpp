#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n, m;
	
	cin>>n>>m;
	
	vector<vector<int> > dy(n+1, vector<int>(m+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			cin>>dy[i][j];
	}
	//[1,1]���� ���η� �̵��� ���  
	for(int i = 1; i <= n; i++)
		dy[i][1] = dy[i][1] + dy[i-1][1];
	
	//[1,1]���� ���η� �̵��Ѱ�� 
	for(int j = 1; j <= m; j++)
		dy[1][j] = dy[1][j] + dy[1][j-1];
	
	//[2,2]���� �밢�� ���� ���� �� ���� ū ���� �ڽ��� ��ġ�� �Է� 
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= m; j++){
			vector<int> tmp;
			tmp.push_back(dy[i-1][j-1]);
			tmp.push_back(dy[i-1][j]);
			tmp.push_back(dy[i][j-1]);
			sort(tmp.begin(), tmp.end());
			
			dy[i][j] += tmp[tmp.size()-1];			
		}
	}
	//��� ���̺� ��� 
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout<<dy[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<dy[n][m]; 
}
