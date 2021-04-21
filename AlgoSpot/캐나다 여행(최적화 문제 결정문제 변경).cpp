#include <bits/stdc++.h>
using namespace std;
int info[5001][3];
//d��ġ�� ������ k��° ǥ������ ���ϴ��� üũ 
bool check(int d, int n, int k){
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		int start = info[i][0] - info[i][1];
		int end = min(info[i][0], d);
		int cycle = info[i][2];
		
		int diff = end - start;
		
		if(diff >= 0)
			cnt += (diff / cycle) + 1;
	}
	
	return cnt >= k;
}
int main(void){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int t, n, k;
	
	cin>>t;
	
	for(int j = 0; j < t; j++){
		cin>>n>>k;
		
		for(int i = 0; i < n; i++)
			cin>>info[i][0]>>info[i][1]>>info[i][2];
		
		int left = 0;
		int right = 8030000;
		
		while(left <= right){
			int mid = (left + right) / 2;
			
			//ǥ������ ���ϸ� �� ���� ���� Ž�� 
			if(check(mid, n, k))
				right = mid-1;
			//ǥ������ ������ �� ū���� Ž�� 
			else
				left = mid+1;
		}
		cout<<left<<"\n";
	}	
    return 0;
}
