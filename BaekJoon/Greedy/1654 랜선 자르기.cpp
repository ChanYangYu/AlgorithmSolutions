#include <bits/stdc++.h>
using namespace std;
//k���� �������̸� ��� �迭 
long long lan[10000];

int main(void){
	ios_base::sync_with_stdio(false);
	
	//���� ���� 
	long long k, n, sum = 0;
	
	cin>>k>>n;
	
	//k���� ���� �Է¹����鼭 ���� ���� 
	for(int i = 0; i < k; i++){
		cin>>lan[i];
		sum += lan[i];
	}
	
	//���� ū ���̴� �������� ���� n���� ���� ũ�� 
	long long best = sum/n;
	
	while(1){
		//���� ���̷� ������ ������ ���� 
		long long cnt = 0;
		//�������� ���� ������ �ִ� ���� 
		long long next_best = 0;
		for(int i = 0; i < k; i++){
			//�ִ����� �������� ������ ������ ���� 
			long long m = lan[i]/best;
			//������ �������� 1�� ���������� ������ ���� 
			long long c = lan[i]/(m+1);
			
			cnt += m;
			//���� ������ �ִ���̸� ���� 
			if(next_best < c)
				74
		}
		//������ n���̻��̸� ���� 
		if(cnt >= n)
			break;
		//���� ������ �ִ���̷� ���� 
		else
			best = next_best;
	}
	
	//best�� ��� 
	cout<<best;
	
    return 0;
}
