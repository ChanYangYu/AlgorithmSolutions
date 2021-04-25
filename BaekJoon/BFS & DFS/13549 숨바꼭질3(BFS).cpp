#include <bits/stdc++.h>
using namespace std;
int check[100001];
int n, k;

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int, int> > q;
	
	cin>>n>>k;
	
	q.push({n,0});
	
	int res = 987654321;
	while(!q.empty()){
		int pos = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		
		if(res < cnt)
			continue;
		if(pos == k){
			res = min(res, cnt);
			break;
		}
		
		//순간이동 먼저 검토 
		if(2*pos <= 100000 && check[2*pos] == 0){
			check[2*pos] = 1;
			q.push({2*pos, cnt});
		}
		
		if(pos-1 >= 0 && check[pos-1] == 0){
			check[pos-1] = 1;
			q.push({pos-1, cnt+1});
		}
		
		if(pos+1 <= 100000 && check[pos+1] == 0){
			check[pos+1] = 1;
			q.push({pos+1, cnt+1});
		}
		
	}
	
	cout<<res<<"\n";

    return 0;
}
