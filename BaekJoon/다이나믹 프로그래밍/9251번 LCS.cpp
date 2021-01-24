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
	
	//a 배열 첫번째 알파벳 부터 검토 
	for(int i = 1; i <= strlen(a); i++){
		for(int j = 1; j <= strlen(b); j++){
			//b배열에서 같은 알파벳이 있으면 i-1행 j-1열 dy값에 +1
			if(a[i-1] == b[j-1])
				dy[i][j] = dy[i-1][j-1] + 1;
			//같은 알파벳이 아니면 
			//새로운값이 갱신된 i행 이전j열 값과 이전 i행 j열 값 중 최고값 갱신 
			else
				dy[i][j] = max(dy[i-1][j], dy[i][j-1]);
		}
	}
	cout<<dy[strlen(a)][strlen(b)];
	return 0;
}
