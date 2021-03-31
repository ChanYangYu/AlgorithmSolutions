#include <bits/stdc++.h>
#define MIN -987654321	
using namespace std;
int num[51];
int cache[51][51];
/* �̴ϸƽ� �˰��� */ 
//���� => ���� �ּ��� ���ð� ���� �� ������ ���� 
int solve(int left, int right){
	//������� 
	if(left > right)
		return 0;
	//��� ��찡 
	int& ret = cache[left][right];
	
	if(ret != MIN)
		return ret;
	
	//��, �� �� ������ ���� 
	ret = max(num[left] - solve(left+1, right), num[right] - solve(left, right-1));
	
	//�ΰ� ������ ������ ���� 
	if(right - left + 1 >= 2){
		ret = max(ret, - solve(left+2, right));
		ret = max(ret, - solve(left, right-2));
	}
	
	return ret;
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);
	int t;
	int n;
	
	cin>>t;
	for(int k = 0; k < t; k++){
		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>num[i];
		//�ʱ�ȭ 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cache[i][j] = MIN;
		int res = solve(0, n-1);
		
		cout<<res<<"\n";
	}
	return 0;
}
