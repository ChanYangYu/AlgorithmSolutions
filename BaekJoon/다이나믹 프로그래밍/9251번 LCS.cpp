#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int dy[1001][1001]; 
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	char a[1001],b[1001];
	cin>>a;
	cin>>b;
	
	//a �迭 ù��° ���ĺ� ���� ���� 
	for(int i = 1; i <= strlen(a); i++){
		for(int j = 1; j <= strlen(b); j++){
			//b�迭���� ���� ���ĺ��� ������ i-1�� j-1�� dy���� +1
			if(a[i-1] == b[j-1])
				dy[i][j] = dy[i-1][j-1] + 1;
			//���� ���ĺ��� �ƴϸ� 
			//���ο�� ���ŵ� i�� ����j�� ���� ���� i�� j�� �� �� �ְ� ���� 
			else
				dy[i][j] = max(dy[i-1][j], dy[i][j-1]);
		}
	}
	cout<<dy[strlen(a)][strlen(b)];
	return 0;
}
