#include <bits/stdc++.h>
using namespace std;

//��ǻ���� ��ȣ ��� 
int check_computer(int a, int b){
	int res = 1;
	//a �� b�� ���������� 1���ڸ��� �ʿ� 
	for(int i = 0; i < b; i++){
		res *= a;
		res %= 10;
	}
	// a > 1�̹Ƿ� 0�� ���� 10�� ����� ��� 
	if(res == 0)
		res = 10;
	return res;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int t;
	
	cin>>t;
	
	//�׽�Ʈ ���̽� �˻� 
	for(int i = 0; i < t; i++){
		int a, b;
		cin>>a>>b;
		int idx = check_computer(a,b);
		cout<<idx<<endl;
	}
	return 0;
}
