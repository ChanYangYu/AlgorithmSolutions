#include <bits/stdc++.h>
using namespace std;
//�����ϰ� ����ġ 
string res[7];

void solve(int depth, int left, int right){
	int mid = (left + right) / 2;
	//�� ������ ��� 
	if(mid == left)
		return;
	else{
		//������ B�� 
		for(int i = left; i < mid; i++)
			res[depth][i] = 'B';
		//������ A�� 
		for(int i = mid; i < right; i++)
			res[depth][i] = 'A';
		//���� depth�� �̵� 
		solve(depth+1, left, mid);
		solve(depth+1, mid, right);
	}
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	
	cin>>n;
	cin.tie(0);
	int mid = n/2;
	//����ġ �ϴ� ������ �з� 
	for(int i = 0; i < 7; i++)
		res[i] = string(mid, 'B') + string((n-mid), 'A');
	 
	solve(0,0,n);
	
	//��� ��� 
	for(int i = 0; i < 7; i++)
		cout<<res[i]<<"\n";
	return 0;
} 
