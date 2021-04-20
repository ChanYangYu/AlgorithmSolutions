#include <bits/stdc++.h>
using namespace std;
double dis[101][101];
double pos[101][2];

bool check(double d, int n){
	int check[101];
	int cnt = 0;
	queue<int> q;
	
	for(int i = 0; i < 100; i++)
		check[i] = 0;
	
	q.push(0);	
	check[0] = 1;
	cnt++;
	
	while(!q.empty()){
		int start = q.front();
		
		q.pop();
		
		for(int i = 0; i < n; i++){
			if(check[i] == 0 && dis[start][i] <= d){
				q.push(i);
				check[i] = 1;
				cnt++;
			}
		}
	}
	
	return n == cnt;
}
int main(void){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int t, n;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>n;
		
		for(int i = 0; i < n; i++)
			cin>>pos[i][0]>>pos[i][1];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				double diff_y = pow(pos[i][0] - pos[j][0], 2.0);
				double diff_x = pow(pos[i][1] - pos[j][1], 2.0);
				dis[i][j] = sqrt(diff_y + diff_x);
				
			}
		}
		double left = 0.0;
		double right = 1415.0;
		
		while(right - left > 0.0001){
			double mid = (right + left) / 2.0;
			
			if(check(mid, n)){
				right = mid;
			}
			else
				left = mid; 
		}
		
		printf("%.2lf\n",right);
	}	
    return 0;
}
