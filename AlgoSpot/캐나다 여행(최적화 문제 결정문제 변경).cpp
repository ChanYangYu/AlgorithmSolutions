#include <bits/stdc++.h>
using namespace std;
int info[5001][3];
//d위치에 있을때 k번째 표지판이 속하는지 체크 
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
			
			//표지판이 속하면 더 작은 범위 탐색 
			if(check(mid, n, k))
				right = mid-1;
			//표지판이 없으면 더 큰범위 탐색 
			else
				left = mid+1;
		}
		cout<<left<<"\n";
	}	
    return 0;
}
