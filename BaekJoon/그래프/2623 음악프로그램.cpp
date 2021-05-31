#include <bits/stdc++.h>
#define ll long long
using namespace std;

int preq[1001][1001];
int cnt[1001];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	
	cin>>n>>m;
	
	for(int i = 0; i < m; i++){
		int k;
		vector<int> a;
		
		cin>>k;
		for(int j = 0; j < k; j++){
			int cur;
			
			cin>>cur;
			
			//a = 먼저와야할 가수들 
			for(int l = 0; l < a.size(); l++){
				if(preq[cur][a[l]] == 0){
					preq[cur][a[l]] = 1;
					cnt[cur]++;
				}
			}
			a.push_back(cur);
		}
	}
	
	vector<int> res;
	for(int i = 0; i < n; i++){
		int next = -1;
		
		//먼저 와야하는 가수가 0명인 가수 search 
		for(int j = 1; j <= n; j++){
			if(cnt[j] == 0){
				//다음 가수 선택 후, -1로 중복선정을 막는다. 
				next = j;
				cnt[j] = -1;
				break;
			}
		}
		
		//다음 순서에 올 가수가 없는 경우 
		if(next == -1){
			// 0출력 후 종료 
			cout<<"0";
			return 0;
		}
		//정답 배열에 가수 번호 삽입 
		res.push_back(next);
		
		//현재 선택된 가수보다 이후 순서에 와야할 가수들 cnt(먼저 와야하는 가수들 수)-- 
		for(int j = 1; j <= n; j++){
			if(preq[j][next] == 1){
				preq[j][next] = 0;
				cnt[j]--;
			}
		}
	}
	
	for(int j = 0; j < n; j++)
		cout<<res[j]<<"\n";
	return 0;
}
