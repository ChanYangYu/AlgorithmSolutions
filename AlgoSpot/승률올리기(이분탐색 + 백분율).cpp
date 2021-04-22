#include <bits/stdc++.h>
using namespace std;

int main(void){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	int t;
	long long MAX = 2000000000;
	
	cin>>t;
	
	for(int i = 0; i < t; i++){
		long long n, m;
		
		cin>>n>>m;
		
		//�ʱⰪ(��з�) 
		double initial = (m * 100) / n;
		
		//20��� �ʰ� üũ 
		if((((m + MAX) * 100) / (n + MAX)) - initial < 1){
			cout<<"-1\n";
			continue;
		}
		
		long long left = 0;
		long long right = MAX;
		
		//�̺й����� �ٻ�ġ ���	
		while(left <= right){
			long long mid = (left + right) / 2;
				
			if((((m + mid) * 100) / (n + mid)) - initial >= 1)
				right = mid-1;
			else
				left = mid + 1;
		}
		//����� ��� 
		cout<<left<<"\n";
	}

    return 0;
}
